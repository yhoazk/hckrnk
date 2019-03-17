#!/usr/env python3

def is_leap(year):
    leap = False

    if (((year)%4)==0) and (((year)%100 == 0) and (((year%400)) == 0)):
        leap = True

    return leap


leap = lambda y : (((y)%4)==0) and (((y)%100 == 0) and (((y%400)) == 0))

#year = int(input())

# =============================================================================
# print(is_leap(year))
# 
# print(leap(year))
# 
# =============================================================================

for n in range(1800, 3030):
    if leap(n) != is_leap(n):
        print("Error: {} leap: {} is_leap {}".format(n, leap(n), is_leap(n) ))
        break