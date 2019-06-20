
"""
In number theory and combinatorics, a partition of a positive integer n, also
called an integer partition, is a way of writing n as a sum of positive 
integers. 
Two sums that differ only in the order of their summands are considered
the same partition. If order matters, the sum becomes a composition. 

For example, 4 can be partitioned in five distinct ways:

4
3 + 1
2 + 2
2 + 1 + 1
1 + 1 + 1 + 1 

- - - -

For every number we begin with the base case 2 = 1+1
The decomposition(D) of 3 is equal to the decomposition of 2 plus 1.
D3 = D2 +1

Plust the "base cases" which come from the simple -1 decomposition in 2
elements
"""

def basecase(n):
    print("called for {}".format(n))
    bc = []
    counter = 1
    # decrement until the half of the number
    # after that the pairs are repeated
    limit = (n//2)
    
    while(counter <= limit):
        bc.append([n - counter, counter])
        counter += 1
    print(bc)
    return bc


sol = []
def allSums( n ):
    
    if n > 2:
        sol = allSums(n-1)
        # Add +1 to every sublist as it is only a past case
        # Dk = Dn +1
        # k = n-1
        # D = Decomposition
        # D5 = D4 +1
        for i in range(len(sol)):
             sol[i].append(1)
        bc = basecase(n)
        
        for i in range(len(bc)):
            sol.append(bc[i])
        return sol
    else:
        return [[2], [1,1]] # return the base case

if __name__ == "__main__":
    D = allSums(int(input()))
    print("There are {} possible combinations".format(len(D)))
    for s in D:
        print(" + ".join(map(str,s)))
    
    