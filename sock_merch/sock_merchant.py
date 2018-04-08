#!/bin/python3

_ = int(input().strip())
ar = list(map(int, input().strip().split(' ')))
print(sum([int(y/2) for y in [ar.count(x) for x in set(ar)]]))

