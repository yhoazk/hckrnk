# hckrnk
common snippets and soluitions for hacker rank

# Make the pc BEEP for wind and linux
`echo -ne '\007'`




### Position of the rigthmost set bit
```c
int pos = n ^ (n&(n-1));
```
For example `192 ` == `1100 0000` returns `n=64`


## Problems with prime numbers:

**Remember** `1` is **not** a prime. Then for any prime decomposition or
prime factor count, remove it.

#### Why is `1` not prime?

Because of the [fudamental theorem of arithmetic](https://en.wikipedia.org/wiki/Fundamental_theorem_of_arithmetic).
This theorem defines that:
> Any integet >1 is prime or is a product of a unique combination of prime numbers.

If `1` is prime then this combination is not unique, for example:

`6 = 3 x 2`

But is also true for:

`6 = 3 x 2 x 1`

#### Why the primality test should get only up-to `sqrt(n)` for any integer `n`
