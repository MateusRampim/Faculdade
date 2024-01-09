import socket
import tkinter as tk
from tkinter import ttk
from tkinter import scrolledtext
from ttkthemes import ThemedTk
from tkinter import messagebox
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib.pyplot as plt

HOST ='127.0.0.1'
PORT = 8000
CLIENT = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
CLIENT.connect((HOST, PORT))

def exibir_info_na_interface(mensagem_original, mensagem_binaria, mensagem_ami, mensagem_cripto):

    info_text.config(state=tk.NORMAL)
    info_text.delete(1.0, tk.END)
    info_text.insert(tk.END, f"Mensagem original: {mensagem_original}\n")
    info_text.insert(tk.END, f"Mensagem criptografada: {mensagem_cripto}\n")
    info_text.insert(tk.END, f"Mensagem em binário: {mensagem_binaria}\n")
    info_text.insert(tk.END, f"Mensagem ami: {toString(mensagem_ami)}\n")
    info_text.config(state=tk.DISABLED)


def exibir_grafico_na_interface(saida_ami):
    plt.clf()
    plt.plot(saida_ami, drawstyle='steps-pre')
    plt.ylim(-1.2,1.2)
    canvas.draw()


def show_error_message(message):
    root = tk.Tk()
    root.withdraw()  # Hide the main window

    # Display an error message
    messagebox.showerror("Error", message)

def binario(mensagem):
    trans = ''
    for letra in mensagem:
        trans += format(ord(letra), '08b')
    return trans

def inv_binario(mensagem):
    trans = ''
    for i in range(0, len(mensagem), 8):
        bytes = mensagem[i:i + 8]
        trans += chr(int(bytes, 2))
    return trans

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

CHAVE_VIGENERE = "Guilherme&Matheus"

def criptografia(mensagem):
    mensagem_cifrada = ""
    chave_expandida = (CHAVE_VIGENERE * (len(mensagem) // len(CHAVE_VIGENERE)) + CHAVE_VIGENERE)[:len(mensagem)]
    for char, chave_char in zip(mensagem, chave_expandida):
        novo_codigo = (ord(char) + ord(chave_char)) % 256
        mensagem_cifrada += chr(novo_codigo)

    return mensagem_cifrada


def toString(vetor):
    return ''.join(map(str, vetor))


def processaMensagem(mensagem):
    mensagem_cripto = criptografia(mensagem)
    mensagem_binaria = binario(mensagem_cripto)
    mensagem_ami = ami(mensagem_binaria)
    
    print("Mensagem original:", mensagem)
    print("Mensagem criptografada:", mensagem_cripto)
    print("Mensagem em binário:", mensagem_binaria)
    print("Mensagem codificada:", toString(mensagem_ami))
    return mensagem_cripto, mensagem_binaria, mensagem_ami

def gerar_mensagem_e_atualizar_interface():
    if (mensagem_text.get("1.0", tk.END).strip() == ''):
        show_error_message("Digite a mensagem a ser enviada")
        return

    mensagem_digitada = mensagem_text.get("1.0", tk.END).strip()

    mensagem_cripto, mensagem_binaria, mensagem_ami= processaMensagem(mensagem_digitada)
    enviar_mensagem(toString(mensagem_ami))
    exibir_info_na_interface(mensagem_digitada, mensagem_binaria, mensagem_ami, mensagem_cripto)
    exibir_grafico_na_interface(mensagem_ami)


# Função para enviar a mensagem
def enviar_mensagem(msg):
    CLIENT.send(msg.encode('utf-8'))


# Cria a interface gráfica
root = ThemedTk()
root.title("Codificação AMI")

# Cria um campo de texto para digitar a mensagem
instrucao_texto = ttk.Label(root, text="Digite sua mensagem aqui:")
instrucao_texto.pack(pady=5)
mensagem_text = scrolledtext.ScrolledText(root, width=70, height=3)
mensagem_text.pack(pady=10)

# Cria um campo de texto para exibir as informações
info_text = scrolledtext.ScrolledText(root, width=70, height=10, state=tk.DISABLED)
info_text.pack()

gerar_mensagem_button = ttk.Button(root, text="Enviar mensagem", command=gerar_mensagem_e_atualizar_interface, )
gerar_mensagem_button.pack(pady=10)

# Figura p grafico
fig, ax = plt.subplots()
canvas = FigureCanvasTkAgg(fig, master=root)
canvas_widget = canvas.get_tk_widget()
canvas_widget.pack(pady=(0,10))


def fechar_janela():
    root.quit()
    root.destroy()


# Configuração da geometria para centralizar na tela
largura_janela = 700
altura_janela = 600
largura_tela = root.winfo_screenwidth()
altura_tela = root.winfo_screenheight()

x_pos = largura_tela // 2 - largura_janela // 2
y_pos = altura_tela // 2 - altura_janela // 2

root.geometry(f"{largura_janela}x{altura_janela}+{x_pos}+{y_pos}")

root.protocol("WM_DELETE_WINDOW", fechar_janela)

root.mainloop()
