import numpy as np
import matplotlib.pyplot as plt

k = 1.38*10**-23               #[m2kgs-2K-1]
h = 6.626*10**-34             #[m2kg/s]
c = 2.998*10**8                 #[m/s]
T = 287                               #[K]


lam =np.linspace (0.001, 100, 10000)

def blackBody(lam, T):
    A = (2*np.pi*h*c**2)/((lam*10**-6)**5)
    B = 1/(np.exp(h*c/((lam*10**-6)*k*T))-1)
    return A*B

print "CO2 value: %f" % blackBody(14.95, T)
print "CH4value: %f" % blackBody(7.65, T)

plt.plot(lam, blackBody(lam, T), )
plt.xlabel("$\lambda$ [$\mu$m]")
plt.ylabel("Spectral Intensity [W/$m^2$/$\mu m$]")
plt.ylim(0, 2.6*10**7)
plt.xticks(np.arange(0, 100, 5))
plt.grid(True)
plt.show()
