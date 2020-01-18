# hckrnk
common snippets and soluitions for hacker rank

# Make the pc BEEP for wind and linux
`echo -ne '\007'`

### Quines

A quine is a non-empty program which takes no input and produces a copy if its
own source code as its only output. These programs are also called self-
replicating or self-reproducing programs. Quines are possible in any turing
complete programming language. There's much practical usage in quines.

The Ken Thompson Hack (1984)
http://wiki.c2.com/?TheKenThompsonHack 

Its a hack in the compiler that makes something like this pseudo code:
```
def compile(src):
  if(looksLikeLoginCode(src)):
      generateLoginWithBackDoor()
  else:
    compileNormally(src)
```
But this can be discovered easily, to avoid someone else to noticing it in
the src code then change needs to go in the compiler:

```
def compile(src):
  if (looksLineLoginCode(src):
    generateLoginWithBackdoor(src)
  elif(looksLikeCompierCode(src)):
    generateCompilerWithBackDoorDetection(src)
  else:
    compileNormally(src)
```

What happens is that the c compiler code is modified, so that it compiles itself,
it inserts the backdoor code. So now when the C compier compiles login, it will 
inset the backdoor and when it compiles the C compiler, it will insert the code
that inserts the code into both login and the C compiler.

Now, you compile the C compier with itself, getting a C compiler that includes
the backdoor generation code explicitly. Then you delete the backdoor code from
from the C compiler src. But it's in the binary. So when you use that binary to
produce a new version fo the compiler from src code, it will insert that back
door code into the new version.

So now we have a C compiler that inserts a backdoor when it compiles itself
and the backdoor code appears nowhere in the source code of the compiler, because
it was removed. that means that each successive new version of the C compiler
will pass along the back door. 



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

Since if `d` is greater than `sqrt(n)` and `d` is a divisor of `n`, then `n/d`
is less than `sqrt(n)` and is also a divisor of `n`; therefore, if `n` has a
divisor, you will find it by the time you get to `sqrt(n)`.


#### [Benchmarking progamming languages](http://benchmarksgame.alioth.debian.org/)


#### [Copy On Write or Shadowing or CoW or COW](https://en.wikipedia.org/wiki/Copy-on-write)

Resource management technique used to efficiently implement a "duplicate"
or "copy" operation on modifiable resources. If a resource is duplicated
but NOT modified, it is not necessary to create a new resource.
The original resource is shared between the copy and the original.

Only when the copied resource is modified a copy is created, then the copy
operation is deferred to the first write.


