import numpy as np
import matplotlib.pyplot as plt
from scipy import special as sp 
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm 


ks = 1 #not sure how to define this component of the wavevector
w = 1

def A_x(x,y,z,t):
    #assuming beam is traveling along x axis hence A_x. Thus s depends on y,z 
    return np.real(sp.jv(1, ks*np.sqrt(y**2+z**2))*np.e**(1j * 1 * np.arctan2(z,y))*np.exp(-1j*w*t))

y = np.linspace(-10,10,1000)
z = np.linspace(-10,10,1000)

Y,Z = np.meshgrid(y,z)

# plt.figure()
# plt.pcolor(Y,Z, A_x(0, Y,Z))

plt.figure()
plt.pcolor(Y,Z, A_x(0, Y, Z, 3))  


## make the surface plot 
fig = plt.figure()
ax = fig.gca(projection='3d')
# Plot the surface.
surf = ax.plot_surface( Y, Z, A_x(0,Y,Z, 3), cmap=cm.coolwarm)

plt.show() 
