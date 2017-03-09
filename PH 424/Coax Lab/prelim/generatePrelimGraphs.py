import numpy as np
import matplotlib.pyplot as plt

R_top = 58.1
r  = np.linspace(0, 275, 1000)
R_id = (r-R_top)/(r+R_top)
T_id =(2*r)/(r+R_top)

dir = "C:/Users/John/Desktop/homeworkRepo/PH 424/Coax Lab/prelim"
resistances = np.loadtxt(dir+"/resistances.txt")
vref_vinc = np.loadtxt(dir+"/vref_vinc.txt")
vtrans_vinc = np.loadtxt(dir+"/vtrans_vinc.txt")

plt.figure()
plt.plot(resistances, vref_vinc, 'o', color = 'k', label="v_ref/v_inc")
plt.plot(r, R_id, '--', color = 'k', label = "R_id")
plt.plot(r, np.zeros(1000),  color= 'k')
plt.xlabel("Potentiometer Resistance [$\Omega$]")
plt.ylabel("v/v_inc")
plt.xlim(0,275)
plt.legend(loc = 7)
plt.grid(True)

plt.figure()
plt.plot(resistances, vtrans_vinc, 's', color = 'b',  label="v_trans/v_inc")
plt.plot(r, T_id, '--', color = 'b', label = "T_id")
plt.plot(r, np.zeros(1000),  color= 'k')
plt.xlabel("Potentiometer Resistance [$\Omega$]")
plt.ylabel("v/v_inc")
plt.xlim(0,275)
plt.legend(loc = 7)
plt.grid(True)

plt.show()
