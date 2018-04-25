#if 01
#include <iostream>
#include <string>
#include <gtest/gtest.h>
using namespace std;
double square_root(double x)
{
  return x/2;
}

enum log_level {
  FATAL = 0,
  ERROR,
  WARN,
  INFO,
  DEBUG,
  VERBOSE
};

bool is_true(bool t)
{
  return t;
}


string convert_test(unsigned int x)
{
  constexpr unsigned int b = 1 << (sizeof(unsigned int)*8)-1;
  string out;
  bool f1 = false; // to start to concatenate with the first 1
  while(x)
  {
    if(x & (b))
    {
      f1 = true;
      out += "1";
      cout << "1";
    }
    else if(f1){
      out += "0";
      cout << "0"; // the last 0 is not being added to the string. WHYYYY?
    }
    cout << (f1? "+":"-");
    x <<=1;
  }
  out += "b0";

  return out; // what happens with out if only lives here?
}

void log_test(string id, string cntx, string msg, log_level lvl) noexcept;

void log_test(string id, string cntx, string msg, log_level lvl) noexcept
{
  std::cout << id << cntx << msg << ":" << lvl << '\n';
}
TEST(SquareRootTest, PositiveNos)
{
    EXPECT_EQ (18.0, square_root (324.0));
    EXPECT_EQ (25.4, square_root (645.16));
    EXPECT_EQ (50.3321, square_root (2533.310224));
}

TEST(SquareRootTest, SWS_DTL_0001)
{
  ASSERT_EQ (true, true);
}

/*
String comparison

ASSERT_STREQ     EXPECT_STREQ   THE TWO STRINGS HAVE THE SAME CONTENT
ASSERT_STRNE     EXPECT_STRNE
ASSERT_STRCASEEQ EXPECT_STRCASEEQ
ASSERT_STRCASENE EXPECT_STRCASENE
*/

TEST(STRING_TEST, _0001)
{
  EXPECT_TRUE(strcmp("This", "This") == 0);
}

TEST(STRING_TEST, _0002)
{
  const char one[] = "String test";
  const char two[] = "string test";
  EXPECT_STREQ(one, two);
}


TEST(DLT, SWS_DTL_00013)
{
  ASSERT_EQ (true, is_true(true));

}

TEST(DLT, SWS_DTL_00033)
{
  ASSERT_EQ ("10101010", convert_test(0xAA));

}


TEST (SquareRootTest, ZeroAndNegativeNos)
{
    ASSERT_EQ (0.0, square_root (0.0));
    ASSERT_EQ (-1, square_root (-22.0));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#else
#include <iostream>
#include "gtest/gtest.h"

class TestFixture : public ::testing::Test {
protected:
    void SetUp(){
	std::cout << "SetUp()" << std::endl;
    }

    void TearDown(){
	std::cout << "TearDown()" << std::endl;
    }
};



TEST_F (TestFixture, shouldCompile) {
    std::cout << "shouldCompile" << std::endl;
    ASSERT_TRUE(true); // works, maybe optimized out?

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif
