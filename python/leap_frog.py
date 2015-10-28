
A = [1, 3, 1, 4, 2, 5]
X = 7
D = 3

OPT_ARR = [-1 for i in range(0,X+1)]
B = []
for i in range(0, X+1):
    B.append(-1)
    
for i in range(0, len(A)):
    if B[A[i]] == -1:
        B[A[i]]=i
B[0] = 0
B[-1] = 0

print "B: ", B

for i in range(0,D+1):
    if i ==0:
        OPT_ARR[i] = 0
    else:
        OPT_ARR[i] = B[i]
OPT_ARR[-1] = 0

def OPT2(j, D):
    if B[j] == -1:
        return -1
    min_val = 10000
    for i in range(j-D, j):
        if OPT_ARR[i] != -1:
            if min_val > OPT_ARR[i]:
                min_val = OPT_ARR[i]
    if min_val == 10000:
        return -1
    else:
        if B[j] > min_val:
            return B[j]
        else:
            return min_val

'''def OPT(j,D):
    if OPT_ARR[j] != -1:
        return OPT_ARR[j]

    min_outer = 1000000 #some large num
    for i in range(j-D,j):
        OPT_VAL = OPT(i, D)
        min_inner = 100000
        if OPT_VAL < min_inner and OPT_VAL != -1:
            min_inner = OPT_VAL
    if min_value != 10000
            if min_inner == -1 or B[j] == -1:
        min_outer = -1
    elif B[j] > min_inner:
        min_outer = B[j]
    else:
        min_outer = min_inner
    return min_outer
'''
for i in range(D+1, X+1):
    OPT_ARR[i] = OPT2(i,D)

print "OPT_ARR: ", OPT_ARR
'''
def solution(A, X, D):
    # write your code in Python 2.7
    B = []
    for i in range(0, X):
        B.append(-1)
    
    for i in range(0, len(A)):
        if B[A[i]] == -1:
            B[A[i]]=i
    
    print B
    if D >= X:
        return 0
    elif D >= A[0] and D>= X-A[0]:
        return 0
    else:
        return -1
print A
print solution(A, X, D)
'''
