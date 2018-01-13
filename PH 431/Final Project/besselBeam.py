import numpy as np
import matplotlib.pyplot as plt
from scipy import special as sp 
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
from matplotlib.animation import FuncAnimation 


a = np.pi/4
mu = 1

def rho(x,y):
    return np.sqrt(x**2+y**2) 

def I(x,y, k): 
    return k**2*np.sin(a)**2*sp.jv(1,k*np.sin(a)*rho(x,y))**2
    #return np.sin(a)**2*sp.jv(1,k*np.sin(a)*rho(x,y))**2

# print("generating axes") 
# x = np.linspace(-10,10,300)
# y = x
# FRAMES = 50
# k = np.linspace(1, 2, FRAMES) 
# print("meshing into grid")
# X,Y, K = np.meshgrid(x,y, k)

# print("calculating intensity")
# intensity = I(X,Y,K)

# fig, ax = plt.subplots()

# cax = ax.pcolormesh(x,y, intensity[:-1,:-1,0], cmap='gray')
# fig.colorbar(cax)
# def animate(i):
#     cax.set_array(intensity[:-1,:-1,i].flatten()) 
# ax.set_title('Bessel beam intensity as k increases')
# ax.set_ylabel('y')
# ax.set_xlabel('x') 
# anim = FuncAnimation(
#     fig, animate, frames = FRAMES, repeat=True)

# anim.save('besselBeam_vs_k.gif', writer='imagemagick')

x = np.linspace(-10,10,300)
y = x
X,Y = np.meshgrid(x,y) 
plt.figure()
plt.pcolor(X,Y, I(X,Y,1.5), cmap='gray')
plt.title(r"Bessel beam intensity cross section for $\ell=1$")
ax = plt.gca()
ax.axis('off') 
plt.savefig('tex/images/intensityProfile.jpeg')

plt.show() 


