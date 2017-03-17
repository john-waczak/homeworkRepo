from __future__ import division
import numpy as np
import matplotlib.pyplot as plt


A=1
T=1
gamma = 1
w = 2*np.pi / T
V0 = 1
t = np.linspace(-T/2-0.5, T/2+0.5, 10000)

def coefficient_1(n):
    return (V0/T)*(2*gamma/(gamma**2+n**2*w**2))

def coefficient_2(n):
    return ((4*A)/(np.pi**2*n**2))*(1-(-1)**n)


def prob_1(N):
    V= 0
    for n in range(0,N):
        V = V + coefficient_1(n)*np.cos(n*w*t)
    return V

def prob_2(N):
    V= 0
    for n in range(1,N):
        V = V + coefficient_2(n)*np.cos(n*w*t)
    return V


plt.figure()
plt.plot(t, prob_1(100))


plt.figure()
plt.plot(t,prob_2(3), '--', color='k', label='terms up to n=3')
plt.plot(t,prob_2(11), color='k',label='terms up to n = 11')
plt.xlabel("t [s]")
plt.ylabel("V(t) [volts]")
plt.grid(True)
plt.legend()
plt.show()
