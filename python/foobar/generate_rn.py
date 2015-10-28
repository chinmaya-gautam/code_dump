#!/usr/bin/python

import sys

n = int(sys.argv[1])

R = list()
R.extend([1, 1, 2])
print R
for i in range(1, n):
    if i == 1:
        R.append(3)
    else:
        R.append(R[i] + R[i+1] + i)
        R.append(R[i-1] + R[i] + 1)

i_val = [ i for i in range(0, len(R))]
value_pairs = zip(i_val, R)

print value_pairs
