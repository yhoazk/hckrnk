# Dynamic Time Wrapping

Is an algorithm to measure the similarity between two temporal sequences which
may vary in speed. In general, DTW calculates an optimal match between two
given sequences, the optimal match is denoted by the match that satisfies the
next restrictions and has minimal cost.

- Every index from the seq A must nbe matched with one or more indices from seq
B, and vice versa
- The first index from the sequence A must be matched with the first index of 
seq B. Not necesarily the only match
- The last index of seq A must be matched with the last index of seq B. But not
necesarily the only match
- The mapping of the indices from seq A to the indices of seq B must be monotonical
increasing.

The cost is computed as the sum of absotule differences.
