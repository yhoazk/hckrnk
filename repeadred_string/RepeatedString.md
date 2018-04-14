# [Repeated String](https://www.hackerrank.com/challenges/repeated-string/problem)

someone has a string _s_ of lowercase English letters that repeats infinitely
many times. 

Given an integer _n_, find and print the number of "a"s in the first letters of
the infinite string.

For example, if the string _s_ = "abcac" and _n_ = 10, the subtring we consider
is "abcacabcac" the firsts 10 charactes of that string contain 4 occurrences of
_a_.

## Input format:

The firsts line contains a single string _s_.

The second line contains an integer _n_.

## Constraints:

* `1 <= |s| <= 100`
* `1 <= n <= 10^12`

## Output format

Print a single integer denoting the number of _a_s in the first n letters of the 
infinite string created by repeatating _s_ infinite many times.
