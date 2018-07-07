# Hash
[algorithm design and application ch 6](./)

http://www.partow.net/programming/hashfunctions/index.html

The simplest hash was proposed by Knuth in the art of computer programming.
He proposes to take the modulo with a prime number. The problem is that there's
a high probability of collisions.



## Bob Jenkins hash function

http://burtleburtle.net/bob/hash/doobs.html






## Hash vs CRC vs Crypto Hash

By convention, the output value for a CRC is called _checksum_, and the output
value for a hash is called a _digest_.

CRCs are a type of error-detecting code used to implement checksums. CRCs are
specifically designed to satisfy the property that they can detect Tx errors
in the data. The CRC is computed over the data payload and sent as part of
the data transmission. The receiver can recompute the CRC and compare it.
- No other property of the CRC matters other than whether it differs when data
corruption occurs.
- It isnt important if the CRC is biased in any way as long as the Tx error
result in differing CRCs.

An error of a single bit or a sigle byte will guarantee that the CRC checksum
will fail, regardless of any other property of the transmitted data, including
its length. This is a powerful property, since it guards against the most
commont type of Tx errors.

Has functions optimize for a different property they try to optimize for the
case of reducing bias in the output digest value. That is hashes should attempt
to have unbiased output values even when the output is biased. Also they try to
optimize to reduce hash collisions for differing input values.

Cryptographic hash functions have very large digest values compared to what is
typically used in a CRC. For example MD5 has a 128-bit digest and SHA-1 has a 
160-bit digest value.

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
