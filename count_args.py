# -*- coding: utf-8 -*-
"""
Created on Sat Jun  1 12:58:46 2019

@author: huan xie

How many agruments:
    Create a function that retunrs the count of arguments passed
    
args_cnt(1,2,3) -> 3
args_cnt(1,1,1,1,3) -> 5

To use variable length arguments in python we need to use the special syntax
*args : single asterisk is used for non-keyworded variable length arg list
**kwargs : Double asterisk is used for keyworded variable length arg list


this kind of syntax can also be used when calling a fixed argument function
and pass a list of position based arguments or key indexed args
"""

def four_args(ar1, ar2, ar3, ar4):
    """ This function can also receive the args as a tuple if the tuple
    is given with a * to expand the args, this args will have a position based
    indexing
    """
    print("arg1: {}".format(ar1))
    print("arg2: {}".format(ar2))
    print("arg3: {}".format(ar3))
    print("arg4: {}".format(ar4))


def four_keyed_args(kar1, kar2, kar3, kar4):
    print("Key 1 argument Val argument {}".format(kar1))
    print("Key 2 argument Val argument {}".format(kar2))
    print("Key 3 argument Val argument {}".format(kar3))
    print("Key 4 argument Val argument {}".format(kar4))

def args_cnt(*args):
    """ In python for a function to be able to accept N agrs
    the we have to use a version of variadic from C code.    
    """
    return len(args)


def keyworded_arg_cnt(**kargs):
    for key in kargs:
        print("k {} : v {}".format(key, kargs[key]))

if __name__ == "__main__":
    print(args_cnt(1,2))
        
    
    # The keys are not defined previously, then they are not strings as 
    # in a dictionary
    keyworded_arg_cnt(K=12, n=4)
    # Using the asterisk notation on a function with fixed argument number
    to_expand = (1,"2",3,"4")
    four_args(*to_expand)
    
    keys_to_expand = {"kar1" : "A", "kar2" : "B", "kar3" : "C", "kar4" : "D" }
    four_keyed_args(**keys_to_expand)
    
    


