import numpy as np
import matplotlib.pyplot as plt


A = 1
L = 1
v = 1
x = np.linspace(0, L, 1000)

def probOne(t):
    f = np.zeros(1000)
    for n in range(1,30):
        f = f + (9*A*np.sin(np.pi*n/3))/(np.pi**2*n**2)*np.sin(np.pi*n*x/L)*np.cos(np.pi*n*v*t/L)
    return f

plt.figure()
plt.plot(x, probOne(0), label="t = 0")
plt.xlabel("x")
plt.ylabel("f(x,t)")
plt.legend()
plt.title("30 term fourier series expansion for f(x,t)")
plt.show()
