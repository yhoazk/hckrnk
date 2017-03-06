

# https://www.hackerrank.com/challenges/grading

def grade(s):
    if s < 38:
        return s
    elif (s % 5) >= 3:
        s = s + (5-(s%5))
    return s

n = int(input())
for e in range(n):
    print(grade(int(input())))
