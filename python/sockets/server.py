#!/usr/bin/python

import socket
import random

user_email = ""
user_num = 123456
user_num_digits = 0


def get_random_number(n):
    digits = [0,1,2,3,4,5,6,7,8,9]
    num = 0
    while(n):
        len_digits = len(digits)
        pos = random.randint(0,len_digits-1)
        num = num * 10 + digits[pos]
        digits.remove(digits[pos])
        n -=1
    return num

def create_socket ():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.bind(("127.0.0.1", 8000))
    sock.listen(2)
    (client, (ip, port)) = sock.accept()
    return (client, ip, port)


def get_info(client):
        global user_email
        user_email = client.recv(2048)
        global user_num_digits
        user_num_digits = random.randint(6, 9)
        global user_num
        user_num = get_random_number(user_num_digits)

        print "user_email" + user_email,
        print "user_num_digits:", user_num_digits
        print "user_num:", user_num


def find_ab(num):
        unum_str = str(user_num)
        num_str =  str(num)
        a = 0
        b = 0
        for i,c in enumerate(num_str):
#            print "i: ", i
            pos = unum_str.find(c)
#            print "pos: ", pos
            if pos == -1:
                pass
            elif  pos == i:
                a+= 1
            else:
                b+= 1
        print unum_str
        print num_str
        return (a, b)

client, ip, port = create_socket()
print client, ip, port
get_info(client)
client.send(str(user_num_digits))

while(True):
        num = client.recv(2048)
        a, b = find_ab(num)
        response = "%d, %d" % (a, b)
        client.send(response)
        

