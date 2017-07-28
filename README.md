# hckrnk
common snippets and soluitions for hacker rank

# Make the pc BEEP for wind and linux
`echo -ne '\007'`




### Position of the rigthmost set bit
```c
int pos = n ^ (n&(n-1));
```
For example `192 ` == `1100 0000` returns `n=64`

