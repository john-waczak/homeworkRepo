import numpy as np
import matplotlib.pyplot as plt

R_top = 37.9




L = 150                     #[m]
R_0 =  R_top/L            #[ohms/m]
C_0 = 93.5085*10**(-12)    #[F/m]
v = 2.00*10**8           #[m/s]
L_0 = 1/(v**2*C_0)  #[H/m]

B = (R_0*C_0*v)/2
print B
r  = np.linspace(0, 400, 1000)
R_id = (r-R_top)/(r+R_top)
T_id =(2*r)/(r+R_top)

Rv = R_id*np.e**(-2*B*L)
Tv = T_id*np.e**(-B*L)



dir = "C:/Users/John/Desktop/homeworkRepo/PH 424/Coax Lab/prelim"
resistances = np.loadtxt(dir+"/resistances.txt")
vref_vinc = np.loadtxt(dir+"/vref_vinc.txt")
vtrans_vinc = np.loadtxt(dir+"/vtrans_vinc.txt")

plt.figure()
plt.plot(resistances, vref_vinc, 'o', color = 'k', label="v_ref/v_inc")
plt.plot(r, R_id, '--', color = 'k', label = "R_id")
plt.plot(r, Rv, color = 'k', label = "Rv")
plt.plot(r, np.zeros(1000),  color= 'k')
plt.plot(resistances, vtrans_vinc, 's', color = 'b',  label="v_trans/v_inc")
plt.plot(r, T_id, '--', color = 'b', label = "T_id")
plt.plot(r, Tv, color = 'b', label = "Tv")
plt.xlabel("Terminal Resistance [$\Omega$]")
plt.ylabel("v/v_inc")
plt.xlim(0,402)
plt.legend(loc = 'lower right')
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
