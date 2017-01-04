
#!/bin/python3
#https://www.hackerrank.com/challenges/plus-minus
import sys


n = int(input().strip())
arr = [int(arr_temp) for arr_temp in input().strip().split(' ')]

print(len([k for k in arr if k > 0]) / len(arr))
print(len([k for k in arr if k < 0]) / len(arr))
print(len([k for k in arr if k == 0]) / len(arr))
