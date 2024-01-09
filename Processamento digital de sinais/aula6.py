# -*- coding: utf-8 -*-
"""
Created on Thu Aug 17 10:35:35 2023
equacao a diferencas
alfa 0.4

tau 50.100.500
@author: mateu
"""

import numpy as np
import matplotlib.pyplot as plt
import PDS as pds
import sounddevice as sd
import scipy.signal as signal

def H(w,beta=0.2,alfa=0.8):
    return beta/(1-alfa*np.exp(-1j*w))
w = np.linspace(-np.pi, np.pi,1024)
f1 = 500
f2 = 3000

x =np.load('123test_noisy.npy')
Fs= 8192
b,a = signal.iirnotch(f1, Q=5,fs=Fs)

x1= pds.lfilter(b, a, x)
b,a = signal.iirnotch(f2, Q=5,fs=Fs)

X2= pds.lfilter(b, a, x1)


freqangular1= 2*np.pi*f1/Fs
freqangular2= 2*np.pi*f2/Fs
r=.99
c1=(1-(1+r**2*np.cos(freqangular1)+r**2))/(2-2*np.cos(freqangular1))

b1=np.array([1,-2.0*np.cos(freqangular1),1])
a1=np.array([1,-(1+r**2)*np.cos(freqangular1),r**2])

x1 = pds.lfilter(b1, a1, x)
w,hx1=pds.freqz(b1,a1,w,whole=True)
plt.plot(w, np.abs(hx1))
b2=np.array([1,-2.0*np.cos(freqangular2),1])

a2=np.array([1,(1+r**2)*np.cos(freqangular2),r**2])
x2 = pds.lfilter(b2, a2, x1)

sd.play(x2,Fs,blocking=True)


# beta= 0.2
# alfa = 0.8



# #analitico"

# # plt.plot(w, np.abs(H(w)),w,np.angle(H(w)))
# # plt.figure()


# #analitico2
# a=[1,-alfa]
# b=[beta]
# w,ha=pds.freqz(b,a,w,whole=True)
# plt.plot(w,np.abs(ha),w,np.angle(ha))

# #numerico
# n=np.arange(100)
# w0=0.1*np.pi
# x=np.cos(w0*n)
# y= pds.lfilter(b, a, x)
# plt.figure()
# plt.plot(n, x,'.-b',n,y,'.-')
# plt.figure()