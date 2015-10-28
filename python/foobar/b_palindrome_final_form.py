#!/usr/bin/python

num = input()

def answer(n):
    base = 2
    while(True):
        #convert base
        num = n
        rem = 0
        num_list = []
        while(True):
            rem = num%base
            num = num//base
            num_list.append(rem)
            if num == 0:
                break
        #check if palindrome
        num_list_rev = num_list[::-1]
        for i in range(0, len(num_list)):
            if num_list[i] == num_list_rev[i]:
                continue
            else:
                break
        else:
            return base
        base +=1

print answer(num)
