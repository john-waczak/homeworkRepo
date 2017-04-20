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

#problem 3 c
plt.figure()
v_t = 20 #m/s
g = 10 #m/s^2

a = g*t/v_t
V3 = v_t*(np.exp(a)-np.exp(-a))/(np.exp(a)+np.exp(-a))

Y3 = (v_t**2/g)*np.log((np.exp(a)+np.exp(-a))/2)



plt.plot(t, V3, label='v(t)')
plt.plot(t, g*t, label = 'gt') 
plt.xlim(0,10)
plt.ylim(0, 100)
plt.grid(True)
plt.xlabel("t [s]")
plt.ylabel("v [m/s]") 
plt.legend()

plt.figure()
plt.plot(t, Y3, label='y(t)')
plt.plot(t, 0.5*g*t**2, label='1/2gt^2x')
plt.grid(True)
plt.ylim(-10, 300) 
plt.xlim(0,15)
plt.xlabel("t [s]")
plt.ylabel(" y [m]")
plt.legend(loc=4)


#Problem 4 b
plt.figure()
v0 = 20
b = 3 #linear drag coefficient
t = np.linspace(0, 100, 1000)
m = 10 #kg
c = 1 
V4 = b/(np.exp(b*t/m)*((b+c*v0)/v0)-c)
plt.plot(t, V4)
plt.grid(True)
plt.xlim(0,20)
plt.xlabel('t [s]')
plt.ylabel('v [m/s]') 


plt.show()
