from __future__ import division
import numpy as np
import matplotlib.pyplot as plt

g = 9.8             #[m/s^2]
v0 = 1              #[m/s]

theta = np.linspace(0, np.pi/2, 1000)
time_in_air = 2*np.sin(theta)*v0/g
Range = v0**2*np.cos(theta)*np.sin(theta)/g


fig1, ax1 = plt.subplots()
ax1.plot(theta, time_in_air, 'k')
plt.title(r"Time of flight, $v_0=1$ m/s")
ax1.set_xticks([0., 0.125*np.pi, 0.25*np.pi, 0.375*np.pi, .5*np.pi])
ax1.set_xticklabels(["$0$", r"$\frac{\pi}{8}$",
                     r"$\frac{\pi}{4}$", r"$\frac{3\pi}{8}$", r"$\frac{\pi}{2}$"])
plt.xlabel(r"$\theta$ [radians] ")
plt.ylabel("$t_{flight}(\theta)$ [seconds]")
plt.grid(True)


fig2, ax2 = plt.subplots()
ax2.plot(theta, Range, 'k')
plt.title(r"Range, $v_0 = 1$ m/s")
ax2.set_xticks([0., 0.125*np.pi, 0.25*np.pi, 0.375*np.pi, .5*np.pi])
ax2.set_xticklabels(["$0$", r"$\frac{\pi}{8}$",
                     r"$\frac{\pi}{4}$", r"$\frac{3\pi}{8}$", r"$\frac{\pi}{2}$"])
plt.xlabel(r"$\theta$ [radians] ")
plt.ylabel("$Range(\theta)$ [seconds]")
plt.grid(True)
plt.show()
