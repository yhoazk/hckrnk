# Birthday Chocolate

Lily has a chocolate bar that she wants to share with Jose for his bday.
Each of the squares has an integer on it. She decides to share a contiguous
segment of the bar selected sich tat the length of the segment matches JOses
birth month and the sum of the integers on the squares is equal to his birthday
day. Determine how many waya she can divide the chocolate.

Consider the chocolate bar as an array of squares `s = [2,2,1,3,1]`. She wants
to find segments summing to Joses birthday, `d= 4` with a length equalling his
birth month `m =2 `. In this case, there are two segments meeting the criteria:
`[2,2]` and `[1,3]`.

## Function description
Complete the bday function, it should return an integer denotign the number of
ways lily can divide the chocolate bar. This function has the next params:

* `s`: An array of integers, the number on each of the squares of chocolate
* `d`: An integer, Joses birth day
* `m`: An integer, Joses birth month

## Input format 

The first line contains an integer `n`, the number of squares in the chocolate
bat. The second line contains `n` space separated integers `s[i]`, the nubmers
on the chocolate squaeres where `0 <= < n`.
The third line contains two space-separated integers. `d` and `m`. Joses birth
day and month.

## output format

Print an integer denoting the total number of ways that lily can portion her
chocolate var to share with Jose

