#!/usr/bin/python

num = input()

def is_palindrome(num_list):
    num_list_rev = num_list[::-1]
    for i in range(0, len(num_list)):
        if num_list[i] == num_list_rev[i]:
                       continue
        else:
                       return False
    else:
        print num_list,
        return True

def convert_base(num, base):
    rem = 0
    num_list = []
    while(True):
        rem = num%base
        num = num//base
        num_list.append(rem)
        if num == 0:
            break

#    print "num", num_list ," for base %d" %(base)
    return num_list


base = 2
while(True):
    if is_palindrome(convert_base(num, base)):
        print base
        break
    else:
        base +=1
