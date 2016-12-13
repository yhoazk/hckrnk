#!/usr/bin/python

def isFunny(instr):
    revInStr = instr[::-1]
    x = len(instr) - 1
    for i in range(x):
        #print abs(ord(instr[i+1]) - ord(instr[i]))
        #print abs(ord(revInStr[i+1]) - ord(revInStr[i]))
        #print "diff: " + str(abs(ord(instr[i+1]) - ord(instr[i])) == abs(ord(revInStr[i+1]) - ord(revInStr[i])))

        if abs(ord(instr[i+1]) - ord(instr[i])) == abs(ord(revInStr[i+1]) - ord(revInStr[i])):
            pass
        else:
            return False
    return True


def main():
    T= int(raw_input())
    for x in range(T):
        tstStr = raw_input()
        if isFunny(tstStr):
            print "Funny"
        else:
            print "Not Funny"


if __name__ == '__main__':
    main()
