#!/bin/python

import sys

dic = {}
n = int(raw_input().strip())
for val in range(n):
    name,num = raw_input().strip().split(' ')
    dic[name] = int(num)
    

for val in range(n):

