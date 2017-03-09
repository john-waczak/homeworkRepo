import numpy as np
import matplotlib.pyplot as plt

dir = "C:/Users/John/Desktop/homeworkRepo/PH 424/Coax Lab/prelim"
resistances = np.loadtxt(dir+"/resistances.txt")
vref_vinc = np.loadtxt(dir+"/vref_vinc.txt")
vtrans_vinc = np.loadtxt(dir+"/vtrans_vinc.txt")

x  = np.linspace(0, 275, 1000)
plt.plot(resistances, vref_vinc, 'o', color = 'k', label="v_ref/v_inc")
plt.plot(resistances, vtrans_vinc, 's', color = 'k',  label="v_trans/v_inc")
plt.plot(x, np.zeros(1000),  color= 'k')
plt.xlabel("Potentiometer Resistance [$\Omega$]")
plt.ylabel("v/v_inc")
plt.xlim(0,275)
plt.legend(loc = 7)
plt.grid(True)
plt.show()
