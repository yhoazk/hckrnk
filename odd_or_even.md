
Given an array of numbers, determine whether the sum of all of the numbers is odd or even.

Give your answer in string format as 'odd' or 'even'.

If the input array is empty consider it as: [0] (array with a zero).

Example:
````js
oddOrEven([0]) returns "even"
oddOrEven([2, 5, 34, 6]) returns "odd"
oddOrEven([0, -1, -5]) returns "even"
````

My Solution

````js
function oddOrEven(array) {
   var odd = array[0] & 0x01;
   for(var i=1; i<array.length; i++){
		odd = (odd & 0x01) ^ (array[i]&0x01);
   }
  if(odd == 1)
  { 
    return "odd";
  }
  else
  { 
    return "even";
   }
}
```

Other solutions implied the `reduce` function for arrays. Here's a short tutorial about `reduce` function.

### [Reduce](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/Reduce)


```js
function oddOrEven(arr) {
  return arr.reduce((a,b)=>a+b,0) % 2 ? 'odd' : 'even';
}
```
