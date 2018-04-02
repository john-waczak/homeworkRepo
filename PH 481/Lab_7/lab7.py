import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt("malusLaw.csv", delimiter=",")
reflection = np.loadtxt("reflection.csv", delimiter=",")
reflectivityData = np.loadtxt("reflectivityData.csv", delimiter=",")
transmission = np.loadtxt("transmission.csv", delimiter=",")


theta = data1[:, 0]
v_norm = data1[:, 1]
t = np.sort(theta)
theory = np.cos(t)*np.cos(t)

plt.figure()
plt.plot(theta, v_norm, 'ro', label="transmission data")
plt.plot(t, theory, 'k', label="Malus law theory curve")
plt.title("Transmission voltage vs polarizer angle difference")
plt.xlabel(r"$\theta$ [radians]")
plt.ylabel("Normalized voltage (transmission intensity)")
plt.xlim(-1, 2)
plt.legend()
plt.savefig("malusLaw")

Lambda = reflection[:,0]
ref = reflection[:,1]/100  # divide by 100 to get R/T as decimal not percentage
tran = transmission[:,1]/100
lambda_p = reflectivityData[:,0]*1000  # to get to nm wavelengths from um
r = reflectivityData[:,1]
R = np.interp(Lambda, lambda_p, r)
print(R)
Ref = np.multiply(ref, R) #element wise multiply


f, axarr = plt.subplots(2, sharex=True)
axarr[0].set_xlim(400,950)
axarr[1].set_xlabel(r"$\lambda$ [ nm ]")
axarr[0].set_ylabel("Transmission")
axarr[1].set_ylabel("Reflection")

axarr[0].plot(Lambda, tran, color='k')
axarr[0].set_ylim(.50, .85)

axarr[1].plot(Lambda, Ref, color='k')
axarr[1].set_ylim(.10,.25)
plt.savefig("spectra")

l2 = 696*10**(-9)  # lambda 2
l1 = 561*10**(-9)  # lambda 1
n = 21  # index of refraction SbO3
d = l2*l1/(2*n*(l2-l1)) * 10**9 # to change units to nm 
alpha = (1/d)*np.log((1-Ref)/tran)  # [1/nm]

plt.figure()
plt.plot(Lambda, alpha, color='k')
plt.xlim(400,950)
plt.ylim(0, 0.005)
plt.xlabel(r"$\lambda$ [nm]")
plt.ylabel(r"$\alpha$ [1/nm]")
plt.title("absorption of SbO3 vs wavelength")
plt.savefig("absorption")


plt.show()
