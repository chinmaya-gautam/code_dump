#!/usr/bin/python

import socket
import time

def connect_server(host, port):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((host, port))
    return sock

sock = connect_server("127.0.0.1", 8000)
sock.send("chinmaya.gatuam@gmail.com")

num_len = int(sock.recv(2048))
num = "0123456789"[:num_len]
num_final = "_" * num_len
num2 = num

break_flag = 0

sock.send(str(num))
a, b  = sock.recv(2048).split(", ")
a = int(a)
b = int(b)
print a, b
time.sleep(1)
i = num_len
j = 0
a2 = 0
b2 = 0

for i in range(num_len, 10):
    if break_flag == 1:
        break
    for j in range(0, num_len):
        num2 = num[:j] + str(i) + num[j+1:]
        sock.send(str(num2))
        a2, b2 = sock.recv(2048). split(", ")
        a2 = int(a2)
        b2 = int(b2)
#        print "checking number: ", num2
#        print "a2: ", a2, "b2: ", b2
#        print "num_len: " , num_len
        if a2 + b2 == num_len:
            num = num[:j] + str(i) + num[j+1:]
            break_flat = 1
            break
        if a2 + b2 > a + b:
            num = num[:j] + str(i) + num[j+1:]
            a = a2
            b = b2
            if a2 > a:
                num_final = num_final[:j] + str(i) + num_final[j+1:]
            break

print num_final
print num
print "a: ", a, "b: ", b
print "**********************"

num_final = "_" * num_len
num_temp = list(num)
a_max = a
for i in range (0, num_len):
    for j in range(0, num_len):
        index1 = num_temp.index(num[i])
        if j == index1:
            continue
        temp = num_temp[j]
        num_temp[j] = num_temp[index1]
        num_temp[index1] = temp
        print " >> ", ''.join(num_temp), a_max
        sock.send(''.join(num_temp))
        a2, b2 = sock.recv(2048).split(", ")
        if a2 > a_max:
            num_final = num_temp
            a_max = a2
            
print num_final
