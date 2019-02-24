# -*- coding: utf-8 -*-
"""
Created on Sun Feb 24 17:57:42 2019

"""

comb = "34215"


def get_lehmer_naive(c):
    lehmer = []
    c = [int(i) for i in c]
    while len(c) > 0:
        n = c.pop(0)
        lehmer.append(len([x for x in c if n > x]))
    print(lehmer)
    
get_lehmer_naive(comb) # expected 22100
get_lehmer_naive("53214") # expected 42100
get_lehmer_naive("15342") # expected 03110    