import numpy as np
import matplotlib.pyplot as plt

z0 = 5
z = np.linspace(0, 1.25*z0, 1000)

plt.figure()
plt.plot(z, z*np.tan(z), 'b', label='$z tan(z)$')
plt.plot(z, -z*np.tan(z)**(-1), 'r', label='$-z\cot(z)$')
plt.plot(z, np.sqrt(z0**2-z**2), 'k', label='$\sqrt{z_0^2-z^2}$')
plt.ylim(0, 1.25*z0)
plt.xlim(0, 1.25*z0)
plt.xlabel('z')
plt.ylabel('Transcendental function')
plt.legend(loc=1)
plt.savefig("intersection.png")
