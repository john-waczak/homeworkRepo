import numpy as np
import matplotlib.pyplot as plt


a = 1
g = 10
L = 1
m = 1
K = 1

k = np.linspace(-np.pi/a, np.pi/a, 300) 

w = np.sqrt(g/L + 2*K - 2*K*np.cos(k*a))

plt.plot(k, w, 'k')
#plt.plot(k, np.sqrt(2*K/m*(1-np.cos(k*a))))
plt.xlim(-np.pi/a, np.pi/a)
plt.xlabel('k')
plt.ylabel('$\omega$(k)')
plt.show() 
