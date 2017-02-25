from __future__ import division
import numpy as np
import matplotlib.pyplot as plt


R = 100
C = 0.1*10**(-6)
L = 0.1674288


dir = "C:/Users/John/Desktop/homeworkRepo/PH 424/LRC_lab/dataGraphs"
w = np.loadtxt(dir+"/angularFrequencies.txt")
phi_e= np.loadtxt(dir+"/phaseDiffExp.txt")
#phi_t = np.loadtxt(dir+"/phaseDiffTheory.txt")
Y_e = np.loadtxt(dir+"/admittanceExp.txt")
#Y_t = np.loadtxt(dir+"/admittanceTheory.txt")


w1 = np.linspace(1000,20000, 10000)
Y_t = 1/np.sqrt(R**2+(w1*L-1/(w1*C))**2)
phi_t = np.arctan((w1*L-1/(w1*C))/R)


plt.figure()
plt.scatter(w, phi_e, color='b', label ='Phi experimental')
plt.plot(w1,  phi_t, 'k', label = 'Phi theoretical')
plt.ylabel("$\phi$  [rad]")
plt.xlabel("$\omega$ [rad/sec]")
plt.title("Phase lag in LRC circuit")
plt.grid(True)
plt.legend(loc = 'upper left')
plt.xlim(6000, 11000)


plt.figure()
plt.scatter(w, Y_e, color='b', label = 'Y experimental')
plt.plot(w1, Y_t,'k', label = 'Y theoretical')
plt.ylabel("Y [siemens]")
plt.xlabel("$\omega$ [rad/sec]")
plt.title("Admittance response of LCR circuit")
plt.grid(True)
plt.ylim(0, 0.011)
plt.legend()

plt.show()
