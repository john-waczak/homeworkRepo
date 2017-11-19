import numpy as np
import matplotlib.pyplot as plt
from scipy import special as sp 
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm 

A0= 1 
kz = 1 #not sure how to define this component of the wavevector
kr = 1 
w = 1

def E2(x,y,z,t):
    #assuming beam is traveling along x axis hence A_x. Thus s depends on y,z 
   # return np.norm2(np.real(sp.jv(1, ks*np.sqrt(y**2+z**2))*np.e**(1j * 1 * np.arctan2(z,y))*np.exp(-1j*w*t)))
    f = A0*np.exp(1j*kz*z)*sp.jv(1,kr*np.sqrt(x**2+y**2))*np.exp(1j*1*np.arctan2(y,x))*np.exp(-1j*w*t)
    f_c = np.conj(f)
    E2 = f*f_c
    print np.isreal(E2)
    E2 = np.real(E2)
    return E2

x = np.linspace(-10,10,500)
y = x
X,Y = np.meshgrid(x,y)
plt.plot()
plt.pcolor(X,Y,E2(X,Y,0,0))

plt.show() 
