#!/usr/bin/python
import random

my_list = []
for i in range(0, 100):
    s =  random.randint(0, 1000000 - 1)
    e = random.randint(1, 1000000)

    while e <= s:
        e = random.randint(1, 1000000)

    my_list.append([s, e])

print my_list
