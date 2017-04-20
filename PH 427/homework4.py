import numpy as np
import matplotlib.pyplot as plt

z_0 = 8.59
z = np.linspace(0, z_0, 1000)
circle = np.sqrt(z_0**2 - z**2)
even = z*np.tan(z)
odd = -z*(1/np.tan(z))

plt.figure()
plt.plot(z, odd, '--k', label='-zcot(z)')
plt.plot(z, even, 'k', label='ztan(z)')
plt.plot(z, circle, 'b', label ='$\sqrt{z_0^2 - z^2}$')
plt.xlabel('z')
plt.ylabel('f(z)')
plt.xlim(0,3*np.pi)
plt.ylim(0, 3*np.pi)
#plt.axes().set_aspect('equal', 'datalim')
plt.legend()
plt.grid(True)
plt.show()
