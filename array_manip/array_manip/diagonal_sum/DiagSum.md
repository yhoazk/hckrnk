# Statement

Given a "square" array of subarrays, find the sum of values from the first 
array, the second value of the second array, the third value of the third
array, and so on...


## Solution for `JS`




```js
function diagonalSum(matrix){
      tot=0;
        matrix.forEach(function(element, idx) {
              tot += element[idx];
                  
                    });
        return tot;
}
```
