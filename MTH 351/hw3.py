from __future__ import division
import numpy as np
import matplotlib.pyplot as plt

x0 = 1.5
x1 = 0

for i in range(20):
    x1 = x0 - 0.148*(x0**3-5)
    print(x1)
    x0 = x1 
print(5**(1/3))
