# Introduction to Google C++ Testing Framework

Google test framework has built-in assertions that are deployable in software
where expection handling is disabled. Thus the assertions can be used safely in
destructors too.

Running the tests is simple. Just call the macro `RUN_ALL_TESTS` as opposed to
creating or deriving a separate runner class for test execution. Difference to
frameworks as `CppUnit`

Generating a XML report is wasy, just pass the switch --getst_output="<xml:filename>"`.



## Creating a basic test

Function to test:
```cpp
double square_root(const double);
```
For negative numbers, this routine returns `-1`. It's useful to have both positive
and negative tests here, so you do both.

```cpp
#include "gtest/gtest.h"
TEST (SquareRootTest, PositiveNos){
    EXPECT_EQ (18.0, square_root(324.0));
    EXPECT_EQ (24.5, square_root(645.16));
    EXPECT_EQ (50.3321, square_root(2533.310224));
} // EXPECT_EQ continues even if there is a failure

TEST(SquareRootTest, ZeroAndNegativeNos){
    ASSERT_EQ (0.0, square_root(0.0));
    ASSERT_EQ (-1, square_root(-22.0));
} // ASSERT_EQ aborts the exectuion if there's a failure

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

## Installing google test

1. Get the sources from [github](https://github.com/google/googletest.git)
2. Extract the contents in a tmp directory. `tar -xvf <googletest-version>`
3. Create the build directoy and go there `mkdir build && cd build`
4. Generate the makefiles `cmake -DMAKE_INSTALL_PREFIX:PATH=../../DIR ../googletest` the prefix is
   relative.
5. make
6. make install


After this step the generated directory is in the specified path


http://www.yolinux.com/TUTORIALS/Cpp-GoogleTest.html
