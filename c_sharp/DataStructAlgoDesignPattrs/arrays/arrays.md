### Arrays

In C# as in C/C++ exists single-dimensional, multidimensional and a
built-in type called jagged arrays.

Jagged arrays can contain elements of different size. In C/C++ this would
have to be implemented as a reference.

To create an array in `C#`:

```cs
Type[] name;
int[] numbers;
```

As in java this arrays are created empty, we need to assign the memory to 
them and initialize their values.

```cs
int[] numbers;
numbers = new int[8];

int[] more_numbers = new int[9];
// To initialize with values
int[] numbers =  new int[] {-12, 4, 55};
int[] numbers = {5, 0, -45};
```
#### Multidimensional arrays
For two dimensional arrays:
```cs
int[,] array; // an object array with undefined size
int[,] sizedArray = new int[5,5]; // an array object of size 5x5
int[,] array_2d = new int[,] = {9,5,9}, 
                                {-11, 6,7};
```

For three dimensional arrays:
```cs
int[,,] numbers = new int
```

For accessing elements of a multidimensional array:

```cs
int[,] array_2d = new int[,] = {9,5,9}, {}
```




#### Methods of arrays

##### `GetLength(int)`

Returns the length of the dimension given by the argument.


### Jagged Arrays

Array of arrays also can be understood as a single dimensional array, where
each element is another array. Inner arrays may have different lengths or be
uninitialized.

