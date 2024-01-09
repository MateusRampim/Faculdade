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


#analitico"
w = np.linspace(-np.pi, np.pi,1024)
l = 11
# a = 1

x1 = np.exp(-1j * w * (l-1) / 2)
x2 = np.sin(w * l / 2) / np.sin(w / 2)
print( np.sin(w / 2))
xana= x1*x2

plt.plot(w, np.abs(xana))
print(np.abs(xana))
plt.grid()
plt.show()
plt.figure()
n=np.arange(-20,21 )
wc = np.pi/4 
x3 = pds.sinc2(n, wc)

plt.plot(w, np.angle(xana))
plt.figure()
plt.stem(n,x3)
plt.grid()
plt.figure()

#numerico

l = 10
n= np.arange(l)
x=np.ones(l)
xnum=pds.dtft(x, n,w)
plt.plot(w, np.abs(xnum))
print(pds.mse(xana, xnum))