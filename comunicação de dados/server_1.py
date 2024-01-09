import socket
import tkinter as tk
from tkinter import ttk
from tkinter import scrolledtext
from ttkthemes import ThemedTk
from tkinter import messagebox
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib.pyplot as plt

SERVER_IP = ''
SERVER_PORT = 8000


def server_run():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    socket_server = (SERVER_IP, SERVER_PORT)
    server.bind(socket_server)
    server.listen(1)
    cone, ip_client = server.accept()
    print(f"conectado no {ip_client}")
    return cone, ip_client


def comunicao(cone, ip_client):
    root = tk.Tk()
    root.title("RECEBE AMI")
    label = tk.Label(root, text="Mensagem")
    label.pack(padx=10, pady=20)
    info_text = scrolledtext.ScrolledText(root, width=70, height=10, state=tk.DISABLED)
    info_text.pack(pady=10)
    fig, ax = plt.subplots()
    canvas = FigureCanvasTkAgg(fig, master=root)
    canvas_widget = canvas.get_tk_widget()
    canvas_widget.pack(pady=10)
    largura_janela = 700
    altura_janela = 600
    largura_tela = root.winfo_screenwidth()
    altura_tela = root.winfo_screenheight()

    x_pos = largura_tela // 2 - largura_janela // 2
    y_pos = altura_tela // 2 - altura_janela // 2

    root.geometry(f"{largura_janela}x{altura_janela}+{x_pos}+{y_pos}")

    def atualiza_janela():
        mensagem = cone.recv(1024).decode('utf-8')
        if mensagem:
            mensagem_binaria, mensagem_str, mensagem_cripto = processa_mensagem(mensagem)
            vetami = ami(mensagem_binaria)
            info_text.config(state=tk.NORMAL)
            info_text.delete(1.0, tk.END)
            info_text.insert(tk.END, f"Mensagem original: {mensagem_str}\n")
            info_text.insert(tk.END, f"Mensagem criptografada: {mensagem_cripto}\n")
            info_text.insert(tk.END, f"Mensagem em binário: {mensagem_binaria}\n")
            info_text.insert(tk.END, f"Mensagem ami: {mensagem}\n")
            info_text.config(state=tk.DISABLED)
            plt.clf()
            plt.plot(vetami, drawstyle='steps-pre')
            plt.ylim(-1.2, 1.2)
            canvas.draw()

        if root.winfo_exists():  # Verifica se a janela ainda está aberta
            root.after(5000, atualiza_janela)  # Chama a função novamente após 100 milissegundos

    root.after(5000, atualiza_janela)  # Chama a função pela primeira vez

    root.mainloop()

def ami(mensagem):
    conv = []
    polaridade = 1
    for bit in mensagem:
        if bit == '1':
            conv.append(polaridade)
            polaridade *= -1
        else:
            conv.append(0)
    return conv


def processa_mensagem(mensagem):
    mensagem_binaria = desv_ami(mensagem)
    mensagem_cripto = inv_binario(mensagem_binaria)
    mensagem_str = descriptografa(mensagem_cripto, "Guilherme&Matheus")
    print("Mensagem recebida:", mensagem)
    print("Mensagem Criptografada:", mensagem_cripto)
    print("Mensagem em binário:", mensagem_binaria)
    print("Mensagem Original:", mensagem_str)


    return mensagem_binaria, mensagem_str, mensagem_cripto


def descriptografa(mensagem_cifrada, chave):
    mensagem_decifrada = ""
    chave_expandida = (chave * (len(mensagem_cifrada) // len(chave) + 1))[:len(mensagem_cifrada)]
    for char, chave_char in zip(mensagem_cifrada, chave_expandida):
        novo_codigo = (ord(char) - ord(chave_char)) % 256
        mensagem_decifrada += chr(novo_codigo)

    return mensagem_decifrada

def desv_ami(mensagem):
    trans = ''
    for caractere in mensagem:
        if caractere == '0':
            trans += '0'
        elif caractere == '1':
            trans += '1'
    return trans

def inv_binario(mensagem):
    trans = ''
    for i in range(0, len(mensagem), 8):
        bytes = mensagem[i:i + 8]
        trans += chr(int(bytes, 2))
    return trans


# main



cone, ip_client = server_run()
comunicao(cone, ip_client)




