import numpy as np

noPar=np.genfromtxt("noParallel/nopar.txt",dtype=np.float32,delimiter=',')
Par=np.genfromtxt("Parallel/par.txt",dtype=np.float32,delimiter=',')

Smean = np.nanmean(noPar)
Pmean = np.nanmean(Par)

print("\n============Serial Algorithm================")
print("\nThere are {} entries".format(len(noPar)))
print("The mean is {} and the standard deviation is {}".format(Smean, np.nanstd(noPar)))

print("\n============Parallel Algorithm==============")
print("\nThere are {} entries".format(len(Par)))
print("The mean is {} and the standard deviation is {}".format(Pmean, np.nanstd(Par)))

print("\n============Algorithm Comparison============")
print("\nParallel is {} times faster than Serial\n".format(Smean/Pmean))