We want two things from a computer algorithm: given an input to a problem, it should
always produce a correct solution to the problem, and it should use com-
putational resources efficiently while doing so.

Correctness is not always easy to define specially in approximation algorithms.
Approximation algorithms apply to optimization problems, in which the __best__
solution is needed according to some quantitative measure. For some problems
there is no optimal solution in any reasonable amount of time, but approximations
exists. An approximation is optimal if it is within some known factor of the
optimal solution. As long as we specifiy what is the desired factor we can
say that the solution is optimal.



## Improvements to linear search

Linear search checks every element in the list with `2N+1` comparisons.
(N comparisons agains the element and the searched element and N+1 for the loop)
The first improvement is to stop when the element is found. Still the worst
case is `2N+1`.
The next improvement is to remove the check for boundaries. This is called 
__linear search with sentinel__. This works by replacing the last element of
the list with the item being search, then we loop through the list to find a
copy of it. When the index points to the item itself we break and return. The 
indexer is incremented unconditionally. This adds an extra check at the end 
of the algorithm to check two conditions:
- If the element we search for was not the last element
- If the element was __not__ in the list. In this case the index == size


```cpp
#include <vector>
#include <iostream>

int main(int argc, char const *argv[]) {
    using namespace std;
    vector<int> seach_space{19, 45, 67, 89, 42, 56, 43, 99, 101, 15};
    int item = 15; // item to be found
    int i = 0; // index var
    int last = seach_space[seach_space.size() - 1]; // store the last element
    
    // Here is where the sentinel is set and is used as limit
    seach_space[seach_space.size() - 1] = item;
    
    // find a copy of the item
    while(seach_space[i] != item){ i++; }
    // restore the last element to keep the original list
    seach_space[seach_space.size() - 1] = last;

    if( (i < (seach_space.size() - 1)) || (item == last)){
        cout << "Item found @" << i <<'\n';
    } else {
        cout << "Item not found\n";
    }

    return 0;
}
```

Note that this algorithm still has complexity `O(n)`, but the number of
comparisons is now `N+2` (`N` comparisons in the loop and 2 in the if)


## Big-oh vs theta

O-notation is used to indicate that a running time is never worse than a
constant times some function of `n`.

For indicating that the running time is __never better__ than a constant times
some function of `n` we use Omega notation.

O-notation gives an upper bound, omega notation gives a lower bound, and theta
notation gives both upper and lower bounds. All this notations together are
referred as asymptotic notation.

## Loop invariants

One method of showing correctnes is to show _loop invariant_. For this to
help us argue correctness, we have to show three things about it:

### Initialization

Is true before the first iteration.

### Maintenance

If it's true before an iteration, it remains true before the next iteration.

### Termination

The loop terminates and gives a useful property at the end.

## Recursion

For recursion to work, there must be one or more base cases, where the solution
can be computed w/o recursion AND each recursion must be a sub-problem that will
eventually reach the base case.


- - -

Statement contrapositive: 
`if a then b` contrapositive `if not b then not a`. The contrapositive
of a statement is true _iff_ the statement is true.

## Sorting and searching

When the elements in the list are not ordered, a search will take `O(n)`.
Only when the elements have an order the search can get to `O(lg n)`.

In order to sort elements, the elements have to be comparable and have a notion
of "less than".

All of the next following algorithms take either `Theta(n^2)` or `Theta(n lg n)`.

## Binary search

Requires the list to be sorted. It takes `O(lg n)` to search an n-element.
Pseudo code:

```
def bin_search(A, n, x): A->list; n-> size of list; x-> element to find
1)    set p = 0 and set r = n-1
2)    while p <= r:
2a)     q = floor((p+r)/2)
2b)     if A[q] == x
            return q
        else:
2c)       if A[q] > x:
            r = q - 1
          else:
2d)         p = q + 1
    
3)  return None # The item was not found
```

#### Loop invariant
    > At the start of each loop of step 2, if `x` is in the array `A`, then is
    > somewhere in the subarray `A[p..r]`

#### Initialization

Step 1) initializes the indices `p` and `r` to `0` and `n-1` respectively.
Then the loop invariant is true when the procedure first enters the loop.


#### Maintenance:

Steps 2C and 2D adjust either `p` or `r` correclty.

#### Termination

If `x` is not in the array, then eventually `p` and `r` will be equal then the
step 2a will assign to `q` the same value of `p` or `r`.  If step 2c sets r to
`q-1`, then at the start of the next iteration, `r == p - 1` and the next 
iteration will p > r. 

### Recursive form 

```
def recursive_bin_search(A,p,r,x):
    if p > r return None
    q = floor((p+r)/2)
    if A[q] == x return q

    if A[q] > x:
        return recursive_bin_search(A, p, q-1, x)
    else
        return recursive_bin_search(A, q+1, r, x)
```



### Selection sort
 This algorithm divides the list into sorted and unsorted. At the start, the 
 sorted subset is empty, then it linearly searched the smallest element in the
 unsortedset and places this in the first index of the sorted subset.
 Then searches again the smallest element in the unsorted set and places it in
 the second index of the sorted set. This procedure is repeated until the 
 unsorted set is empty.

```
Inputs:
    A: an array
    n: cardinality of the array
Result: The elements in A are sorted in nondecreasing order
def selection_sort(A, n)
    for i = 1 to n-1:
        indx_of_smallest = i
        for j = i+1 to n:
            if A[j] < A[indx_of_smallest]:
                indx_of_smallest = j
        swap A[i] with A[indx_of_smallest]
```

 The run time is `Theta(n^2)` given that every in order to get an element in the
 sorted list we need to traverse the unsorted list, every time an element less
 this means the number of operations is given by the aritmetic series:

 ```
 (n-1) + (n-2) + (n-3) + ... + 2 + 1  = n(n+1) / 2 
 ```

 As the asynptotic notation disregards the lower and constant terms `n²` 
 remains as the order.

The big-Oh and Omega order is also `n²`.  This is the worst of the 4 sorting
algorithms listed here. But it has the advantage that it noves the elements
only `Theta(n)`. If moving array elements is time-consuming then selection sort
might be a reasonable choice.


### Insertion sort

### merge sort

### quick sort`