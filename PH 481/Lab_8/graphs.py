import matplotlib.pyplot as plt
import numpy as np

from scipy import stats

data = np.loadtxt('data.txt', delimiter=',')

c = data[:,0]
beta = data[:,1]
beta = np.rad2deg(beta)

m, b, r_value, p_value, std_err = stats.linregress(c,beta)
print(m, b, r_value)

x = np.linspace(0.5, 1.5, 1000)
f = m*x+b

plt.figure()
plt.plot(c, beta, 'bo', label='data')
plt.plot(x, f, color='k', label="y={0:.5f}x+{1:.5f}".format(m,b))
plt.legend()
plt.xlabel('c [g/cm3]')
plt.ylabel(r'$\beta$')
plt.xlim(0.65, 1.35) 
plt.show()
