from __future__ import division 
import numpy as np
import matplotlib.pyplot as plt

m0 = 4
g = 10
k =1
b = 2
v_ex = 3

T = 10
t = np.linspace(0,T,10000)

v = ((-m0*g/(k-b))-(k*v_ex/b))*(1-k*t/m0)**(b/k)+(m0*g/(k-b))*(1-k*t/m0)+(k*v_ex/b)



plt.figure()
plt.plot(t,v, 'k' )
plt.xlabel('t [s]')
plt.ylabel('v [m/s]') 
plt.title('m0 = %f, k = %f, v_ex = %f, b= %f'%(m0,k,v_ex,b))


 


plt.show()




