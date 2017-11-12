# Hash
[algorithm design and application ch 6](./)


## Maps

**Definition**:
A map stores a collection of key-value pairs, `(k,v)`, which we call items,
where _k_ is the key and _v_ is a value that is associated with that key.




## Look-up table

For a reasonably small value of items to be stored, this is the trivial
way to implement a map. It supports [0, N-1] elements.

We can allocate an array A of size N, where each cell of A is a bucekt that
can hold a single key-elemnt pairs, if we use the index as key placing the
value in the A[k] bucket.

* To perform a put(k,v) operation, we assign (k,v) to A[k].
* To perform a get(k) operation, we return A[k].
* To perform a remove(k) operation, we return A[k] and then assign NULL to A[k]


There are some drawbacks, in terms of space usage, we note that the total amount
of memory used for a Look-up table is O(N). In this case we refer to the size of
N, of the array A as being the capacity of the map implementation. That amount
is reasonable if the number of items, n, being stored in the map is close to N.
But if the N is large relative to n, then most of the cells will be empty,
wasting space.



## Hash functions

If we cannot assume that the keys are unique integers in the range [0,N-1], but
nevertheles still want to store key-value pairs, we need a function that maps
the key to our integer range [0,N-1], where N is the capacity of the array. The
use of such function allows us to treat objects, such as strings as numbers.

### Collisions 193




- - -
how to handle a collision?<br>
For example, if the Hash function gives the same address for
"anita lava la tina" and "anit al aval atina"  the two values must be stored.

in python:
```python
d = {}
d["anita lava la tina"] = 0
# lest suppose the keys collide
d["anit al aval atina"] = 123

```
