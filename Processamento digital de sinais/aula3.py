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
from scipy.signal import lfilter

x =np.load('123test.npy')
Fs= 8192



a = [1.0] + [0.7] * 5000 +[1.1]
#sd.play(x,Fs,blocking=True)
x1=lfilter([1],a,x)
sd.play(x1,Fs,blocking=True)