# Lehmer Code

The Lehmer code is a way to encode a possible permutation of a sequence of
`n` items. This code is an instance of a numbering permutation scheme.

This encoding takes the fact that for a sequence of `n` items `n!` permutations
are possible. In this encoding there are `n` positions, where each position 
counts the number of terms to the right that are smaller than itself.

Not every number is a valid Lehmer sequence as every position can only have a 
value less or equal to the number of digits to his right.

## Decoding 

Is easy to get the permutation with the given Lehmer code as is a mapping to
the non-repeating list, i.e. once the item has been used is removed and the 
indexing continues until is empty.

e.g.
```
Seq:12345
Lehmer: 02210
        -----
         _______ 0: No smaller numbers to the right
        / ______ 2: Two numbers to the right, it can only be 3 (5->3, 2->1)
        |/ _____ 2: If it where 3 then 1 2 -> 0
        ||/ ____ 1: only 1 number which is smaller to the right
        |||/ ___ 0: This is always 0 amd is the remaining number
        ||||/
        12532
```

## Encoding

The encoding consists of counting how many elements on the list are smaller
than the one in the current position. See example.

- The last digit is always zero
- The objects need to be orderable