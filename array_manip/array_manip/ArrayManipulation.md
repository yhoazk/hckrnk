# Array Manipulation

You are given a list of size `n`, initialized with zeros.
You have to perform `m` operations on the list and output the maximum of final
values of all the `n` elements in the list.
For every operation, you are given three integers `a`, `b` and `k`. You have to
__add__ `k` to all the elements ranging from index `[a,b]`.

For example, consider a list of `n=3`. The initia list would be `[0,0,0]` and 
after performing the update `O(a,b,k) = (2,3,30)` the new list is `[0,30,30]`
Note that the index starts from 1, not from 0 as in C/C++.

## Input format 

The first line will cointain two integers `n` and `m` separated by a single
space. Next `m` lines will contain three integers `a`, `b` and `k` separated
by a single space.
Numbers in list are numbered from `1` to `n`.

## Constraints

* `3 <= n <= 10**7`
* `1 <= m <= 2*10**5`
* `1 <= a <= b <= n`
* `0 <= k <= 10**9`

## Expected output

Print in a single line the maximum value in the updated list.
