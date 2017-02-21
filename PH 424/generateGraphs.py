from __future__ import division
import numpy as np
import matplotlib.pyplot as plt


dir = "C:/Users/John/Desktop/homeworkRepo/PH 424"
frequencies = np.loadtxt(dir+"/angularFrequencies.txt")
current = np.loadtxt(dir+"/current.txt")
phaseDifference = np.loadtxt(dir+"/phaseDifference.txt")


plt.figure()
plt.scatter(frequencies, current, color='k')
plt.ylabel("I [Amps]")
plt.xlabel("$\omega$ [kHz]")
plt.title("Response current vs angular frequency")
plt.grid(True)

plt.figure()
plt.scatter(frequencies, phaseDifference, color='k')
plt.ylabel("$\phi$ [radians]")
plt.xlabel("$\omega$ [kHz]")
plt.ylim(-0.002,0.002)
plt.title("Phase differnece vs angular frequency")
plt.grid(True)

plt.show()
