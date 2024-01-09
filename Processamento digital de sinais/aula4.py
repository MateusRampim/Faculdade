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
from scipy.signal import residuez

n=np.arange(-3,101)
b=[6,-10,2]
a=[1,-3,2]
r,p,k= residuez(b, a)
"""
parte A


n=np.arange(-3,11)
#transformada Z 
h_a=2*pds.u(n)+3*(2.**n)*pds.u(n)+pds.delta(n)
#
h_n = pds.lfilter(b, a, pds.delta(n))
print(pds.mse(h_n, h_a))
plt.stem(n,h_a)
plt.figure()
plt.stem(n,h_n)

"""

#parte B
p=[np.exp(1j*np.pi/10),np.exp(-1j*np.pi/10)]#[-0.5,0]
#a = np.poly(p)
#b=[1.]
h_n = pds.lfilter(b, a, pds.delta(n))
plt.stem(n,h_n)
