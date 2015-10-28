#!/usr/bin/python

num = 0

#first time get the number of digits
num_digits = raw_input()

while (True):
    print num
    r = raw_input()
    if r == "success":
        print "The number is ", num
        break
    

print r
