from __future__ import division 
import numpy as np
import matplotlib.pyplot as plt

# m0 = 10
# g = -10
# k =100
# b = 10000
# v_ex = 20

# T = 10
# t = np.linspace(0,T,10000)

# v = ((-m0*g/(k-b))-(k*v_ex/b))*(1-k*t/m0)**(b/k)+(m0*g/(k-b))*(1-k*t/m0)+(k*v_ex/b)



# plt.figure()
# plt.plot(t,v, 'k' )
# plt.xlabel('t [s]')
# plt.ylabel('v [m/s]') 
# plt.title('m0 = %f, k = %f, v_ex = %f, b= %f'%(m0,k,v_ex,b))



g = 10
v0 = 5
x0 = 0

t = np.linspace(0, 20, 1000)
x = (1/3)*g*t**2+v0*t+x0

plt.plot(t,x, 'k')
plt.xlabel('t [s]')
plt.ylabel('x [m]')
plt.title('Crude YoYo: v0= %.2f, x0=%.2f'%(v0, x0))

 


plt.show()




