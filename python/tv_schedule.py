#!/usr/bin/python
#tv_schedule.py

import itertools

n = input()                                                 #number of slots
ratings_a = [ int(x) for x in raw_input().split(" ")]
ratings_b = [ int(x) for x in raw_input().split(" ")]

perms_a = list(itertools.permutations(ratings_a))
perms_b = list(itertools.permutations(ratings_b) )

num_perms = len(perms_a)

for i in range(0, num_perms):
    for j in range(0, num_perms):
        print perms_a
        print perms_b
        print " "

        
        
