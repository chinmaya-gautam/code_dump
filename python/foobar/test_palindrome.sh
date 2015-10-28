#!/bin/bash

for i in {0..1000}
do
#echo $i
echo -n "$i "
echo $i | python b_palindrome_final_form.py
done
