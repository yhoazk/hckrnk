# compute the convolution of two strings

example of the convolution of the next strigs `Hello` and `World`.
First combine all pairs of letters with indices that add up to the
same number (ordered by the index of the first element)

- pairs of chars
- need to add up to the same number

```
indx number -> convolution result
    0      -> "HW"
    1      -> "Ho" "eW" ([])
    2      -> "Hr" "eo" "lW"
    3      -> "Hl" "er" "lo" "lW"
    4       -> "Hd" "el" "lr" "lo" "oW"
    5       -> "ed" "ll" "lr" "oo"
    6       -> "ld" "ll" "or"
    7       -> "ld" "ol"
    8       -> "od"
```

## Examples

```
"" "Empty" -> ""         // empty string
"Hello" "World" -> "HWHoeWHreolWHlerlolWHdellrlooWedlllrooldllorldolod"
"Code" "Golf" -> "CGCooGCloodGCfoldoeGofdleodfelef"
"123" "ABC" -> "1A1B2A1C2B3A2C3B3C"
"split" " " -> "s p l i t " // note the trailing whitespace
"+-" "12345" -> "+1+2-1+3-2+4-3+5-4-5"
```