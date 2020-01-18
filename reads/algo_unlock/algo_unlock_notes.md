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