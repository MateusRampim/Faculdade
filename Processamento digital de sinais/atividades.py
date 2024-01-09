# -*- coding: utf-8 -*-
"""
Created on Thu Aug 17 10:35:35 2023

@author: mateu
"""

import numpy as np
import matplotlib.pyplot as plt
import PDS as pds

n = np.arange(-10,31 )
w0=np.pi/10
x=np.cos(w0*n)*1

plt.figure()
plt.stem(n,pds.u(n)*(np.cos(w0*n)*1)-(pds.u(n-2)*(np.cos(w0*(n-2)*1))))
plt.figure()
plt.stem(n,x)

mediamov = []
janela = 10
for i in range(len(x) - janela + 1):
        media = sum(x[i:i+janela]) / janela
        mediamov.append(media)
        
plt.figure()
plt.stem(np.arange(-10,len(mediamov)-10 ),mediamov)