from __future__ import division
import numpy as np
import matplotlib.pyplot as plt

phi = np.pi/6   # radians
v = 5               # m/s
g = 9.8             # m/s^2


theta = np.linspace(0,np.pi/2, 300)

a = 2*v**2*np.sin(theta)*np.cos(theta+phi)
b = 1/(g*np.cos(phi)**2)
R = a*b

v0 = 5
m = 1
c = 1
x = np.linspace (0, 10, 300)
v_x = (-c*x/(2*m) + np.sqrt(v0))**2



plt.figure()
plt.plot(theta, R, 'k')
plt.xlabel(r"$\theta$")
plt.ylabel(r"Range($\theta$)")
plt.grid(True)

plt.figure()
plt.plot(x,v_x, 'k')
plt.xlabel("x [m]")
plt.ylabel("v(x) [m/s]")

plt.show()
