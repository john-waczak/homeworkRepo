from __future__ import division
import numpy as np
import matplotlib.pyplot as plt

dir = "C:/Users/John/Desktop/homeworkRepo/PH 424"
path1 = np.loadtxt(dir+"/1.05kHz_scope.txt", delimiter='\t')
path2 = np.loadtxt(dir+"/1.23kHz_scope.txt", delimiter='\t')
path3 = np.loadtxt(dir+"/1.510kHz_scope.txt", delimiter='\t')

time1 = np.zeros(600)
v11 = np.zeros(600)
v21 = np.zeros(600)
time2 = np.zeros(600)
v12 = np.zeros(600)
v22 = np.zeros(600)
time3 = np.zeros(600)
v13 = np.zeros(600)
v23 = np.zeros(600)


for i in range(0, 600):
    time1[i] =path1[i, 0]
    v11[i] = path1[i,1]
    v21[i] =path1[i,2]

    time2[i] =path2[i, 0]
    v12[i] = path2[i,1]
    v22[i] =path2[i,2]

    time3[i] =path3[i, 0]
    v13[i] = path3[i,1]
    v23[i] =path3[i,2]


plt.figure()
plt.scatter(time1, v11, color='r')
plt.scatter(time1,v21, color='k')
plt.xlim(-0.0012, 0.0012)
plt.title("1.05kHz circuit response")
plt.xlabel("time [s]")
plt.ylabel("Voltage [V]")
plt.grid(True)

plt.figure()
plt.scatter(time2, v12, color='r')
plt.scatter(time2,v22, color='k')
plt.xlim(-0.0012, 0.0012)
plt.title("1.23 kHz circuit response")
plt.xlabel("time [s]")
plt.ylabel("Voltage [V]")
plt.grid(True)

plt.figure()
plt.scatter(time3, v13, color='r')
plt.scatter(time3,v23, color='k')
plt.xlim(-0.0012, 0.0012)
plt.title("1.51 kHz circuit response")
plt.xlabel("time [s]")
plt.ylabel("Voltage [V]")
plt.grid(True)

plt.show()
