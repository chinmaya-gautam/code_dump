#!/usr/bin/python
#gale_shapley.py
#author: cgautam

import random

def print_pref_list(pref_list, N):
    for i in range(0, N):
        print pref_list[i]
    print ""

def gale_shapley(M_pref_list, W_pref_list, N):
    #pick one list randomly
    my_rand_ind = random.randint(0, N-1)
    unpaired_list = W_pref_list[my_rand_ind]
    proposed_list = [-1 for i in range(0, N)]                                 #proposed_list[i] = last lady mi proposed to
    engaged_list = ["" for i in range(0, N)]                                  #engaged_list[i] = the man to which lady wi is engaged
    while(len(unpaired_list) > 0):
        m = unpaired_list.pop()
        m_index = int(m[1]) - 1
        to_propose = proposed_list[m_index] + 1
        w_index = int(M_pref_list[m_index][to_propose][1]) -1
        proposed_list[m_index] += 1
        if engaged_list[w_index] == "":
            engaged_list[w_index]= m
        else:
            print "checking for woman %s against man %s currently engaged to %s, w_index: %d" % (M_pref_list[m_index][to_propose], m, engaged_list[w_index], w_index)
            print "%s's preference list: " % (M_pref_list[m_index][to_propose]),
            print W_pref_list[w_index]
            print W_pref_list[w_index].index(engaged_list[w_index]) 
            print W_pref_list[w_index].index(m)
            if W_pref_list[w_index].index(engaged_list[w_index]) < W_pref_list[w_index].index(m):
                unpaired_list.append(m)
            else:
                unpaired_list.append(engaged_list[w_index])
                engaged_list[w_index] = m
    
    #create matching set 
    S = []
    for i in range(0, N):
        woman = "w" + str(i+1)
        S.append([engaged_list[i], woman])
    return S
                      
                          
                             
T = input()

while (T):
    T-= 1
    N = input()
    #get preference lists 
    M_pref_list = []
    W_pref_list = []
    temp = []
    for i in range(0, N):
        temp = [x for x in raw_input().split(" ")]
        M_pref_list.append(temp)

    for i in range(0, N):
        temp = [x for x in raw_input().split(" ")]
        W_pref_list.append(temp)

    print_pref_list(M_pref_list, N)
    print_pref_list(W_pref_list, N)

    S = gale_shapley(M_pref_list, W_pref_list, N)
    print S

             
