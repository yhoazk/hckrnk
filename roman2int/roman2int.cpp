#include "gmock/gmock.h"
#include <string>
#include <array>
/*
 * establish an order from big to small
 * if the order is inverse, then change the sign of the unit in reverse order
 * If the order is always descendent all sum. If there is an instance which
 * goes in inverse order it should substract
 * */

/*
 Int to roman
 467  = CDLXVII
 Roman numerals are usually written largest to smallest from left to right.
 However, the numeral for four is not IIII. Instead, the number four is written
 as IV. Because the one is before the five we subtract it making four.
 The same principle applies to the number nine, which is written as IX.
 There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9.
    X can be placed before L (50) and C (100) to make 40 and 90.
    C can be placed before D (500) and M (1000) to make 400 and 900
  Expected 1..3999
*/
using testing::Eq;

// Desingnates initi
std::map<char, int> FWD_LUT{
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};

std::map<int, char> REV_LUT{
    {1, 'I'},
    {5, 'V'},
    {10, 'X'},
    {50, 'L'},
    {100, 'C'},
    {500, 'D'},
    {1000, 'M'},
};

std::array<int, 7> rom_vals{
    1000,
    500,
    100,
    50,
    10,
    5,
    1,
};

// wg21.link/P1152r0
class Solution
{
  std::array<size_t, 7> units{};

public:
  int romanToInt(const std::string s)
  {
    int total{0};

    for (size_t i = 0; i < s.size() - 1; i++)
    {
      int next_val{FWD_LUT[s[i + 1]]};
      int this_val = FWD_LUT[s[i]];
      // std::cout << "this: " << this_val;
      // std::cout << " last: " << last_val << '\n';
      if (this_val < next_val)
      {
        total -= this_val;
      }
      else
      {
        total += this_val;
      }
    }

    return total + FWD_LUT[s.back()];
  }

  std::string IntToRoman(const int i)
  {
    int val{i};
    units.fill(0);
    size_t n{0};
    std::string result;
    for (auto v : rom_vals)
    {
      // std::cout << "k: " << k << " v: " << v << '\n';
      std::cout << "N: " << n << " val: " << val << " v: " << v << " val/k:" << val / v << '\n';
      units[n] = val / v;
      val -= (units[n++] * v);
    }
    for (int x{0}; x < rom_vals.size(); ++x)
    {
      std::cout << "N:" << std::to_string(units[x]) << '\n';
      auto val{rom_vals[x]};
      if(val == 4 or val == 9) {

      } else {
        result += std::string(units[x], REV_LUT[rom_vals[x]]);
      }
    }

    return result;
  }
};

TEST(RomanToInt, I)
{
  Solution s;
  ASSERT_THAT(s.romanToInt("I"), Eq(1));
}

TEST(RomanToInt, III)
{
  Solution s;
  ASSERT_THAT(s.romanToInt("III"), Eq(3));
}

TEST(RomanToInt, IV)
{
  Solution s;
  ASSERT_THAT(s.romanToInt("IV"), Eq(4));
}

TEST(RomanToInt, LVIII)
{
  Solution s;
  ASSERT_THAT(s.romanToInt("LVIII"), Eq(58));
}

TEST(RomanToInt, CDXLVII)
{
  Solution s;
  ASSERT_THAT(s.romanToInt("CDLXVII"), Eq(467));
}

TEST(RomanToInt, MCMXCIV)
{
  Solution s;
  ASSERT_THAT(s.romanToInt("MCMXCIV"), Eq(1994));
}

TEST(RomanToInt, CCCLXXVII)
{
  Solution s;
  ASSERT_THAT(s.romanToInt("CCCLXXVII"), Eq(377));
}

TEST(IntToRoman, One)
{
  Solution s;
  ASSERT_THAT(s.IntToRoman(1), Eq("I"));
}

TEST(IntToRoman, Four)
{
  Solution s;
  ASSERT_THAT(s.IntToRoman(377), Eq(std::string("CCCLXXVII")));
}