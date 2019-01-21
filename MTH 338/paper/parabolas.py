import numpy as np
import matplotlib.pyplot as plt

def dist(x, y, p):
    sum = np.power(np.abs(x), p)+np.power(np.abs(y), p)
    return np.power(sum, 1.00/p)

def sup(x,y):
    x_abs = np.abs(x)
    y_abs = np.abs(y)
    return np.max(np.array([x_abs,y_abs]))



x = np.linspace(-10,10,250)
y = np.linspace(-2,10,250)
(X,Y) = np.meshgrid(x,y)


focus = [0, 2]
directrix = 0


p = [1.5, 2, 3, 4, 5, 10]
fig,ax = plt.subplots(nrows=2, ncols=4, figsize=(15,10))

D=dist(0,Y-directrix,1)-dist(X-focus[0], Y-focus[1], 1)
xlim =10
ylim =10
ax[0,0].contour(X,Y,D,0,colors='k')
ax[0,0].set_title("taxicab, p=1")
ax[0,0].set_aspect(1)
ax[0,0].set_xlim(-xlim, xlim)
ax[0,0].set_ylim(-2, ylim)

D=dist(0,Y-directrix,p[0])-dist(X-focus[0], Y-focus[1], p[0])
ax[0,1].contour(X,Y,D ,0, colors='k')
ax[0,1].set_title("p={}".format(p[0]))
ax[0,1].set_aspect(1)
ax[0,1].set_xlim(-xlim,xlim)
ax[0,1].set_ylim(-2,ylim)

D=dist(0,Y-directrix,p[1])-dist(X-focus[0], Y-focus[1], p[1])
ax[0,2].contour(X,Y,D ,0, colors='k')
ax[0,2].set_title("p={}".format(p[1]))
ax[0,2].set_aspect(1)
ax[0,2].set_xlim(-xlim,xlim)
ax[0,2].set_ylim(-2,ylim)

D=dist(0,Y-directrix,p[2])-dist(X-focus[0], Y-focus[1], p[2])
ax[0,3].contour(X,Y,D ,0, colors='k')
ax[0,3].set_title("p={}".format(p[2]))
ax[0,3].set_aspect(1)
ax[0,3].set_xlim(-xlim,xlim)
ax[0,3].set_ylim(-2,ylim)

D=dist(0,Y-directrix,p[3])-dist(X-focus[0], Y-focus[1], p[3])
ax[1,0].contour(X,Y,D ,0, colors='k')
ax[1,0].set_title("p={}".format(p[3]))
ax[1,0].set_aspect(1)
ax[1,0].set_xlim(-xlim,xlim)
ax[1,0].set_ylim(-2,ylim)


D=dist(0,Y-directrix,p[4])-dist(X-focus[0], Y-focus[1], p[4])
ax[1,1].contour(X,Y,D ,0, colors='k')
ax[1,1].set_title("p={}".format(p[4]))
ax[1,1].set_aspect(1)
ax[1,1].set_xlim(-xlim,xlim)
ax[1,1].set_ylim(-2,ylim)

D=dist(0,Y-directrix,p[5])-dist(X-focus[0], Y-focus[1], p[5])
ax[1,2].contour(X,Y,D ,0, colors='k')
ax[1,2].set_title("p={}".format(p[5]))
ax[1,2].set_aspect(1)
ax[1,2].set_xlim(-xlim,xlim)
ax[1,2].set_ylim(-2,ylim)

D=dist(0,Y-directrix,100)-dist(X-focus[0], Y-focus[1], 100)
ax[1,3].contour(X,Y,D,0,colors='k')
ax[1,3].set_title("sup, p=$\infty$")
ax[1,3].set_aspect(1)
ax[1,3].set_xlim(-xlim,xlim)
ax[1,3].set_ylim(-2,ylim)

plt.tight_layout()
plt.savefig("./images/parabolas.png")
plt.show()

