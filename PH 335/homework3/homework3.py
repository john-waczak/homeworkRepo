import numpy as np
import matplotlib.pyplot as plt

z = np.linspace(-5,5, 100)
cosh = (np.exp(z)+np.exp(-z))/2
sinh = (np.exp(z)-np.exp(-z))/2


#problem 1 a
plt.figure()
plt.plot(z,cosh, 'k', label='cosh(z)')
plt.plot(z,sinh, 'b', label='sinh(z)')
plt.xlabel("z")
plt.ylabel("f(z)")
plt.grid(True)
plt.legend(loc=4)

#problem 1 c
plt.figure()
tanh = sinh/cosh
plt.plot(z,tanh, 'k', label='tanh(z)')
plt.xlabel("z")
plt.ylabel("f(z)")
plt.grid(True)
plt.legend(loc=4)

#problem 2 b

t = np.linspace(0, 100, 1000)
m = 20 #kg
c = 1
v0 = 20 #m/s

X = (m/c)*np.log(1+(c*v0*t)/m)
V = v0/(1+c*v0*t/m)

plt.figure()
plt.plot(t,X)
plt.xlabel('t [s]')
plt.ylabel('x [m]')
plt.grid(True)

plt.figure()
plt.plot(t, V)
plt.xlabel('t [s]')
plt.ylabel('v [m/s]') 
plt.grid(True)

plt.show()
