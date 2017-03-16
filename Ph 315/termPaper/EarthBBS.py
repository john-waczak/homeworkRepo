import numpy as np
import matplotlib.pyplot as plt

k = 1.38*10**-23               #[m2kgs-2K-1]
h = 6.626*10**-34             #[m2kg/s]
c = 2.998*10**8                 #[m/s]
T = 287                               #[K]


lam =np.linspace (0.001*10**(-6), 100*10**(-6), 10000)

def blackBody(lam, T):
    A = (2*np.pi*h*c**2)/(lam**5)
    B = 1/(np.exp(h*c/(lam*k*T))-1)
    return A*B

k = np.linspace(0.01, 3000, 10000)
def blackBodyK(k, T):
    A = (2*np.pi*h*c**2)/((2*np.pi/k)**5)
    B = 1/(np.exp(h*c/((2*np.pi/k)*k*T))-1)
    return A*B


#print "CO2 value: %f" % blackBody(14.95*10**-6, T)
#print "CH4value: %f" % blackBody(7.65*10**-6, T)

plt.figure()
plt.plot(lam, blackBody(lam, T) )
plt.grid(True)

plt.figure()
plt.plot(k, blackBodyK(k,T))
plt.show()
