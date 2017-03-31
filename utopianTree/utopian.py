import sys


t = int(raw_input().strip())
for a0 in xrange(t):
    n = int(raw_input().strip())
    h = 1
    #comenzando con una altura de 1
    for c in xrange(n):
        if (c % 2) == 1:
            h = h + 1
        else:
            h = h * 2
    print str(h)


