import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-10,10, 1000);

A = (2/(np.pi*3)) **0.25 * np.e**((-x**2)/3)
B = (4*np.sqrt(2)/np.pi)**0.5 *  (1/(x**2 + 2))

C = 1/np.sqrt(10) * 1/np.cosh(x/5)

plt.figure()
plt.plot(x, A, 'k')
plt.title("$\psi_1(x)$")
plt.ylabel("y")
plt.xlabel("x")
plt.grid(True)

plt.figure()
plt.plot(x,B, 'k')
plt.title("$\psi_2(x)$")
plt.ylabel("y")
plt.xlabel("x")
plt.grid(True)

plt.figure()
plt.plot(x,C, 'k')
plt.title("$\psi_3(x)$")
plt.ylabel("y")
plt.xlabel("x")
plt.grid(True)

plt.show()
