from __future__ import division
import numpy as np
import matplotlib.pyplot as plt

def dist(x, y, p):
    sum = np.power(np.abs(x), p)+np.power(np.abs(y), p)
    return np.power(sum, 1.00/p)

def sup(x,y):
    x_abs = np.abs(x)
    y_abs = np.abs(y)
    return np.max(np.array([x_abs,y_abs]))



x = np.linspace(-2,2,100)
y = np.linspace(-2,2,100)
(X,Y) = np.meshgrid(x,y)


p = [1.5, 2, 3, 4, 5] 
fig,ax = plt.subplots(nrows=1, ncols=len(p)+2, figsize=(25,5))

D=dist(X,Y,1)
xlim =1
ylim =1
ax[0].contour(X,Y,D-1,0,colors='k')
ax[0].set_title("taxicab, p=1")
ax[0].set_aspect(1)
ax[0].set_xlim(-xlim, xlim)
ax[0].set_ylim(-ylim, ylim)
ax[0].axis('off')

for i in range(len(p)):
    D =dist(X, Y, p[i])
    ax[i+1].contour(X,Y,D-1 ,0, colors='k')
    ax[i+1].set_title("p={}".format(p[i]))
    ax[i+1].set_aspect(1)
    ax[i+1].set_xlim(-xlim,xlim)
    ax[i+1].set_ylim(-ylim,ylim)
    ax[i+1].axis('off')


D = np.ones_like(X)
for i in range(len(x)):
    for j in range(len(y)):
        D[i,j] = sup(x[i],y[j])

ax[len(p)+1].contour(X,Y,D,1,colors='k')
ax[len(p)+1].set_title("sup, p=$\infty$")
ax[len(p)+1].set_aspect(1)
ax[len(p)+1].set_xlim(-xlim,xlim)
ax[len(p)+1].set_ylim(-ylim,ylim)
ax[len(p)+1].axis('off')


def hyperbolic(z1, z2):
    return np.arctanh(np.linalg.norm(z2-z1)/np.linalg.norm(1-np.conj(z1)*z2))

x = np.linspace(-2,2,100)
y = np.linspace(-2,2,100)
(X,Y) = np.meshgrid(x,y)


origin = 0.3*j
D = np.ones_like(X)
for i in range(len(x)):
    for j in range(len(y)):
        D[i,j] = hyperbolic(origin, X+Y*j)
        print(D[i,j])

plt.figure()
plt.contour(X,Y,D-0.01, 0, colors='k')
plt.show()
