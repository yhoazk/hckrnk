# Mocking

A mock object implements the same interface as a real object so it can be used
as one, but lets you specify at run time how it will be used and what it should
do.

Mock objects are not fake objects.

* *Fake* objects have working implementations, but usually take some shortcut.
* *Mocks* are objects pre-programmed with expectations, which form a 
specification of the calls they are expected to receive. Mock allows you to 
check the interaction between itself and the code that uses it. 

Using Google Mock involves three basic steps:

1. Use some simple macros to describe the interface you want to mock, and they
will expand to the implementation of your mock class.
2. Create some mock object and specify its expectations and behaviour
3. Exercise code that uses the mock objects, google mock will catch any 
violation.

### Getting started
    bazel build --strategy=CppCompile=standalone --strategy=CppLink=standalone 
To use google mock, just include the files `"gtest/gtest.h"` and `"gmock/gmock.h"`.




 - - -

 Note on virtual destructructors: On an interface the destructor has to be virtual
 as is the case for all clases you intend to inherit from - otherwise the 
 destructor of the derived class will not be called when you delete an object
 through a base pointer, and you'll get corrupted program states like memory 
 leaks.