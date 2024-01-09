
import numpy as np
import matplotlib.pyplot as plt
import PDS as pds
import time



# x = np.array([7,5,9,3])
# xe= x[0::2]
# xo = x[1::2]

# xee =xe[0::2]
# xeo =xe[1::2]
# xoe =xo[0::2]
# xoo =xo[1::2]

M = 11
N = 2**np.arange(M)
t_dft= np.zeros(M)
t_fft = np.zeros(M)

mse = np.zeros(M)
for i in range(M):
    x = np.random.rand(N[i])
    
    t0 = time.time()
    Xdft = pds.dft(x)
    t_dft[i] = time.time() - t0
    
    t0 = time.time()
    Xfft = pds.fft(x)
    t_fft[i]= time.time() - t0
    mse[i] = pds.mse(Xdft,Xfft)

plt.plot(N,t_dft,N,t_fft)
print(np.mean(mse))




