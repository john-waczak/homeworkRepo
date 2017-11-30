import numpy as np
import matplotlib.pyplot as plt


a0 = 0
a1 = 1

N = 12 

a = np.zeros(N)
a[0] = a0
a[1] = a1

for n in range(0, N-2):

    a[n+2] = (2*a[n+1]*(n+1)-a[n])/((n+2)*(n+1))
    


print a

    

