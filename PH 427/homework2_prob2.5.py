import numpy as np
import math
iA = (1/np.sqrt(3))*np.array([[0,1,-1],[-1,0,1],[1,-1,0]])
theta = 2*np.pi/3

def exponential(N):
    M = np.ones((3,3), dtype=np.float)
    for n in range(1, N+1):
        M = M+ (1/math.factorial(n))*(iA*theta)**n
    return M
print exponential(200)
