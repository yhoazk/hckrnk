#!/usr/bin/env python3

if "__main__" == __name__:
    n_test = int(input())
    i,j = 999999999,9999999999
    for _ in range(n_test):
        i_n,j_n = map(int, input().split(" "))
        i = min(i,i_n)
        j = min(j,j_n)
    print(i*j)
