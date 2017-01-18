#!/usr/bin/python
from collections import Counter

if __name__ == "__main__":
    c = Counter([input().strip() for _ in range(int(input()))])
    [print(c[input().strip()]) for _ in range(int(input()))]
