import numpy as np
import matplotlib.pyplot as plt

R_top = 37.9
r  = np.linspace(0, 400, 1000)
R_id = (r-R_top)/(r+R_top)
T_id =(2*r)/(r+R_top)

dir = "C:/Users/John/Desktop/homeworkRepo/PH 424/Coax Lab/prelim"
resistances = np.loadtxt(dir+"/resistances.txt")
vref_vinc = np.loadtxt(dir+"/vref_vinc.txt")
vtrans_vinc = np.loadtxt(dir+"/vtrans_vinc.txt")

plt.figure()
plt.plot(resistances, vref_vinc, 'o', color = 'k', label="v_ref/v_inc")
plt.plot(r, R_id, '--', color = 'k', label = "R_id, Rtop = 37.9 $\Omega$")
plt.plot(r, np.zeros(1000),  color= 'k')
plt.plot(resistances, vtrans_vinc, 's', color = 'b',  label="v_trans/v_inc")
plt.plot(r, T_id, '--', color = 'b', label = "T_id, Rtop = 37.9 $\Omega$")
plt.xlabel("Terminal Resistance [$\Omega$]")
plt.ylabel("v/v_inc")
plt.xlim(0,402)
plt.legend(loc = 'lowerright')
plt.grid(True)


plt.figure()
times = np.loadtxt(dir+"/scopeOutput/times.txt")
ch1 = np.loadtxt(dir+"/scopeOutput/ch1.txt")
ch2 = np.loadtxt(dir+"/scopeOutput/ch2.txt")
plt.plot(times, ch1, color = 'k', label = "ch1 response")
plt.plot(times, ch2, color ='b', label = "ch2 response")
plt.xlabel("Time [s]")
plt.ylabel("Voltage[volts]")
plt.legend(loc = 'upper left')
plt.grid(True)
plt.xlim(-.000004, 0.000006)
plt.show()
