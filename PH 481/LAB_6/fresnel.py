import numpy as np
import matplotlib.pyplot as plt


data = np.loadtxt("fresnel.csv", delimiter=',')

n = data[:,0]
xn = data[:,1]
theory = data[:,2]

print(data)
plt.figure()
plt.plot(n, xn, 'bo', label="x_n")
plt.plot(n, theory, 'ko', label="theory curve for chi squared fit")
plt.xlabel('n')
plt.ylabel('x_n [m]')
plt.legend()
plt.savefig("fresnelPlot")
plt.show()
