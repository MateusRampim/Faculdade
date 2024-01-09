# -*- coding: utf-8 -*-
"""
Created on Thu Aug 17 10:35:35 2023
equacao a diferencas

@author: mateu
"""

import numpy as np
import matplotlib.pyplot as plt
import PDS as pds
from scipy.signal import lfilter

M = 5

# Media Movel
n = np.arange(-3, 10)
x = pds.delta(n)
b = np.ones(M+1)/(M+1)
a = np.ones(1)
h_ref = lfilter(b, a, x)
h = pds.eqdif(b, a, x)

plt.figure()
plt.stem(n, h_ref)
plt.figure()
plt.stem(n, h)
print(pds.mse(h, h_ref))

# sistema IIR
b=np.ones(1)
a=np.array([1,.5])

h_ref = lfilter(b, a, x)
h = pds.eqdif(b, a, x)
plt.figure()
plt.stem(n, h_ref)
plt.figure()
plt.stem(n, h)
print(pds.mse(h, h_ref))
