

t= int(input())
for _ in range(t):
    n,c,m= map(int, input().split())
    bars = n//c
    wraps = bars
    while wraps >= m:
        bars += wraps//m
        wraps = (wraps % m) + wraps//m

    print(bars)
