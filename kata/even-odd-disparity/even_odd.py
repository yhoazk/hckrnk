

def solve(a):
    # explicit
    """
    e,o=0,0
    for n in a:
        if type(n) is int:
            if  n%2 == 0:
                e += 1
                print("even:"+ str(e) + ": " + str(n))
            else:
                o += 1
                print("odd:"+ str(o) + ": " + str(n))



    return e-o
    """
    # one-line
    return sum([ 1 if type(odd) is int and odd%2==0 else -1 if type(odd) is int else 0 for odd in a])
"""
Test.it("Basic tests")
Test.assert_equals(solve([0,1,2,3]),0)
Test.assert_equals(solve([0,1,2,3,'a','b']),0)
Test.assert_equals(solve([0, 15,'z',16,'m', 13, 14,'c', 9, 10, 13,'u', 4, 3]),0)
Test.assert_equals(solve([13, 6, 8, 15, 4, 8, 13]),1)
Test.assert_equals(solve([1,'a', 17, 8,'e', 3,'i', 12, 1]),-2)
"""



print(solve([0,1,2,3]))
print(solve([0,1,2,3,'a','b']))
print(solve([0, 15,'z',16,'m', 13, 14,'c', 9, 10, 13,'u', 4, 3]))
print(solve([13, 6, 8, 15, 4, 8, 13]))
print(solve([1,'a', 17, 8,'e', 3,'i', 12, 1]))
