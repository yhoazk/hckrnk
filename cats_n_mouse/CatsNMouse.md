# Cats and Mouse

Two cats and a mouse are at various position in a line. You will be given
their starting positions. Your task is to determine which catl will reach
the mouse first, assuming the mouse doesn't move and that cats  travel at
equal speed. If the cats arrive at the same time, the mouse will be allowed
to scape.

You are given `q` queries in the form of `x`, `y` and
equal speed. If the cats arrive at the same time, the mouse will be allowed
to scape.

You are given `q` queries in the form of `x`, `y` and `z` representing the
respective positions of the cats `A` and `B` and for the mouse `C`.

* If a cat `A` catches the mouse first, print `Cat A`.
* If a cat `B` catches the mouse first, print `Cat B
* If both cats reach the mouse at the same time, print `Mouse C`.

## Input format

the first line contains a single integer `q`, denoting the number of 
queries. Each of the `q` subsequent lines contain three space-separated
integers describing the respective values of cats and mouse location.

## Constraints

* `1 <= q <= 100`
* `1 <= x,y,z <= 100`

## Output format

For each query, return `Cat A` if a cat `A` catches the mouse first, 
`Cat B` if cat `B` catches the mouse first, or `Mouse C` if the mouse
scapes.


