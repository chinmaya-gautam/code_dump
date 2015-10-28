#!/usr/bin/python

def answer(digest):    
    '''formula
    m[i] = ((256 * x) + d[i]) ^ m[i-1])/129
    '''
    m = list()
    val = 0
    for i in range(0, len(digest)):
        x=0
        rem = 1
        while(rem !=0):
            if i == 0:
                val = ((256 * x) + digest[i])/129
                rem = ((256 * x) + digest[i])%129
                print "digit: %d, val: %d, rem: %d"% (digest[i], val, rem)
            else:
                val = (((256 * x) + digest[i]) ^ m[i-1])/129
                rem = (((256 * x) + digest[i]) ^ m[i-1])%129
            x += 1
        m.append(val)
    return m
        
print answer([0, 129, 3, 129, 7, 129, 3, 129, 15, 129, 3, 129, 7, 129, 3, 129])
print answer([0, 129, 5, 141, 25, 137, 61, 149, 113, 145, 53, 157, 233, 185, 109, 165])
