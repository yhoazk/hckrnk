# -*- coding: utf-8 -*-
"""
Created on Sat Jun 22 15:21:09 2019

@author: porko
"""

# Implementation with a binary tree


class tree:
    
    def __init__(self, n):
        self.left = tree()
        self.right = tree()
        self.val = n
        self.decomp = None
        
    def __str__(self):
        return self.val
    
    def ln(self):
        return self.left
    
    def rn(self):
        return self.right

    def first_decomp(self):
        self.decomp = [1 for _ in range(n)]
        
    def full_decomp(self):
        pass
        
            
            

def print_tree(tr):
    print("oo")

def construct_part_tree(n):
    print(type(n))



if "__main__" == __name__:
    k = tree()
    print_tree(construct_part_tree(int(input())))