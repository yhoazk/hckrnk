#include "gmock/gmock.h"
#include <string>
#include <array>
/*
 * establish an order from big to small
 * if the order is inverse, then change the sign of the unit in reverse order
 * If the order is always descendent all sum. If there is an instance which
 * goes in inverse order it should substract
 * */

using testing::Eq;

//Desingnates initi
std::map<char, int> LUT {
  {'I', 1},
  {'V', 5},
  {'X', 10},
  {'L', 50},
  {'C', 100},
  {'D', 500},
  {'M', 1000},
};

class Solution {
  public:
    int romanToInt(const std::string s) {
      int total{0};

      for (size_t i = 0; i < s.size()-1; i++)
      {
        int next_val{LUT[s[i + 1]]};
        int this_val = LUT[s[i]];
        // std::cout << "this: " << this_val;
        // std::cout << " last: " << last_val << '\n';
        if(this_val < next_val) {
          total -= this_val;
        } else {
          total += this_val;
        }
      }
  
      return total + LUT[s.back()];
    }

    std::string IntToRoman(const int i) {
      return "";
    }
};

TEST(Ok,I){
  Solution s;
  ASSERT_THAT(s.romanToInt("I"), Eq(1));
}


TEST(Ok,III){
  Solution s;
  ASSERT_THAT(s.romanToInt("III"), Eq(3));
}

TEST(Ok,IV){
  Solution s;
  ASSERT_THAT(s.romanToInt("IV"), Eq(4));
}

TEST(Ok,LVIII){
  Solution s;
  ASSERT_THAT(s.romanToInt("LVIII"), Eq(58));
}


TEST(Ok,MCMXCIV){
  Solution s;
  ASSERT_THAT(s.romanToInt("MCMXCIV"), Eq(1994));
}