#  [Rectangular Game](https://www.hackerrank.com/challenges/rectangular-game/problem)

You are given an infinite 2-d grid with the bottom left cell referenced as (1,1). All the cells contain a value of zero initially. Let's play a game?

The game consists of **N** steps, wherei in each step you are given two integers **a** and **b**.
The value of each of the cells in the co-ordinate __(u,v)__ statisfying `1 <= u <= a` and
`1 <= v <= b` is increase by 1.

After **N** suche steps, if **X** is the largest number amongst all the cells in the rectangular
board, can you print the number of **X**'s in the board?

## Input Format

The first line of input contains a single integer **N**, **N** lines follow.
Each line contains two integers __a__ and __b__ separated by a single space.

## Output format:

A single integer - the number of **X**'s

## Constraints:

1 <= N <= 100
1 <= a <= 10<sup>6</sup>
1 <= b <= 10<sup>6</sup>

Example:

Input
```
3
2 3
3 7
4 1
```

Sample output:

```
2
```

Explanation:

Assume that the following board corresponds to cells (i, j) where 1 ≤ i ≤ 4 and 1 ≤ j ≤ 7.

At the beginning board is in the following state:

```
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0 
```
After the first step we will obtain:

```
0 0 0 0 0 0 0
0 0 0 0 0 0 0
1 1 1 0 0 0 0
1 1 1 0 0 0 0 
```
After the second step we will obtain:

```
0 0 0 0 0 0 0
1 1 1 1 1 1 1
2 2 2 1 1 1 1
2 2 2 1 1 1 1 
```
Finally, after the last step:
```
1 0 0 0 0 0 0
2 1 1 1 1 1 1
3 2 2 1 1 1 1
3 2 2 1 1 1 1 
```

So, the maximum number is 3 and there are exactly two cells which correspond to 3. Hence 2.
