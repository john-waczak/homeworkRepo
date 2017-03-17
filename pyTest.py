import numpy as np 
import sys 


cmdArgs = sys.argv[1:]
file = cmdArgs[0]
values = np.loadtxt(file, delimiter=',', comments='#')


print values.shape
print values.ndim



#~ keys = ['ls', 'lt', 'k_b', 'k_ub', 'T', 'cb', 'cm', 'ct']
runs = []


if values.ndim != 1: 
	for i in range(0, values.shape[0]):
		runs.append({"ls":values[i,0], "lt":values[i,1], "k_b":values[i,2], "k_ub":values[i,3],
	"T":values[i,4], "cb":values[i,5], "cm":values[i,6], "ct":values[i,7]})
else: 
	runs.append({"ls":values[0], "lt":values[1], "k_b":values[2], "k_ub":values[3],
	"T":values[4], "cb":values[5], "cm":values[6], "ct":values[7]})

print "\n" 
print runs
