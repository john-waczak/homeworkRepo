import numpy as np
import matplotlib.pyplot as plt

blased = np.loadtxt("blasedGrating.csv", delimiter=',')
sine = np.loadtxt("sineGrating.csv", delimiter=',')

maxV = 10.51
m = blased[:,0]
B = blased[:,1]/maxV
S = sine[:,1]/maxV

plt.figure()
plt.plot(m,B, '-o', label='blazed grating')
plt.plot(m,S, '-o', label='sine grating')
plt.legend()
plt.xlabel('m')
plt.ylabel('efficiency')
plt.savefig('efficiency')
plt.show()
