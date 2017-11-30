import numpy as np
import matplotlib.pyplot as plt

L = 1
z = 0.5

x = np.linspace(0, L, 1000)

def d(n):
    I = 1/L 
    for i in range (1, n+1):
        I = I + (2/L)*np.cos((x-z)*i*np.pi/L)
    return I

def g(n):
    I = 0
    for i in range(1, n+1):
        I = I + (2/L)*np.sin(x*i*np.pi/L)*np.sin(z*i*np.pi/L)
    return I 

plt.figure()
plt.plot(x, d(20), 'b')
plt.plot(x, g(20), 'r') 
plt.show() 
