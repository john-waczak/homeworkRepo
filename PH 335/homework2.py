from __future__ import division 
import numpy as np
import matplotlib.pyplot as plt

#theta = np.pi/6   # radians 
#v = 5               # m/s
#g = 9.8             # m/s^2


#phi = np.linspace(0,np.pi/2, 300)

#a = 2*v**2*np.sin(theta)*np.cos(theta+phi)
#b = 1/(g*np.cos(phi)**2)
#R = a*b

v0 = 5
m = 1
c = 1
x = np.linspace (0, 10, 300)
v = (-c*x/(2*m) + np.sqrt(v0))**2



plt.figure()
#plt.plot(phi, R, 'k')
#plt.ylim(-10,5)
plt.plot(x,v, 'k') 
plt.grid(True)
plt.xlabel("x [m]")
plt.ylabel("v(x) [m/s]") 
#plt.xlabel("$\phi$")
#plt.ylabel("Range($\phi$)")
plt.show()
