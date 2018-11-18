# Find 0

Given a number with all bits except one set to zero, find the position of the 1 counting from left to rigth.

To find which version of the templated function is being instantiated:

```sh
objdump -t find_0.exe | grep <name_of_fnc> | c++filt
```

`c++filt` is a name demangler.
