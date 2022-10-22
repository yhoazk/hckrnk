# Inverse sligind matrix

the challenge is to create a matrix whose
sliding sum is the matrix given as input.

For example, given the matrix:

```
1  1  1
1 -1  1
1  1  1
```
Ans a sliding window of `2x2` a possible answer is:

```
1  1  3 -2
3 -4  1 -1
1  1  1  0
0 -1  0  0
```

The same matrix would work if the given matrix was


```
 5  2
 0 -2
 3  2
-1 -1
```

and the sliding window is `1x3`

Input for this program is the _output_ matri and a window size. It should
return a matrix whose sliding sum with the given window size is the input.
The window size will be at least 1x1, but there is no max size.

Inputs and outputs will consist only of integers. Note that there are 
arbitrarily many correct solutions for most window sizes.
