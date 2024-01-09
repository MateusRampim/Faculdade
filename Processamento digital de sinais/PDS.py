# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import lfilter,freqz


def mse(x,y):
    return np.mean(np.abs(x-y)**2)
    
def delta(n):#impulso
    return (n==0)*1.

def u(n):#degrau
    return (n>=0)*1.

def eqdif(b,a,x):
    y= np.zeros_like(x)
   
    for n in range(len(y)):
        for k in range(len(a)):
            if n-k >= 0:
                y[n] += (-a[k]*y[n-k])
        for k in range(len(b)):
            if n-k >= 0:
                y[n] += (b[k]*x[n-k])
    
    
    return y

def sinc2(n,wc):
    x=np.zeros(n.shape)
    x[n!=0]= np.sin((wc*n[n!=0]))/(n[n!=0]*np.pi)
    x[n==0] = (wc/np.pi)
    return x

def dtft(x,n,w=np.linspace(-np.pi, np.pi,1024)):
    X = np.zeros(len(w),dtype=complex)
    for k in range(len(w)):
        for i in range(len(n)):
            X[k] +=x[i]*np.exp(-1j*w[k]*n[i]) 
                    
    
    return X


def dft(x):
    N = len(x)
    X = np.zeros(N,dtype=complex)
    W = np.exp(-1j*2*np.pi/N)
    for k in range(N):
        for n in range(N):
            X[k] += x[n]*W**(k*n)
    
    return X    


def fft(x):
    N = len(x)
    if N <= 1:
        return x
    X= np.zeros(N,dtype=complex)
    Xe =fft(x[0::2])
    Xo =fft(x[1::2])
    
    for k in range(N//2):
        X[k] = Xe[k] + np.exp(-2j*np.pi*k/N)*Xo[k]
        X[k + N//2] = Xe[k] - np.exp(-2j*np.pi*k/N)*Xo[k]
        
    return X
     
        

    
    
    
