#include <gtest/gtest.h>
#include "solar/solar_doomsday.h"
/* Parametrized test  */

static std::vector<std::pair<unsigned long, std::vector<unsigned long> > > sols{
    std::pair<unsigned long, std::vector<unsigned long>>(30UL, {25UL,4UL,1UL}),
    std::pair<unsigned long, std::vector<unsigned long>>(45UL, {36UL,9UL}),
};


class solar_test : public ::testing::TestWithParam<std::pair<unsigned long, std::vector<unsigned long> > >{

};

TEST(solar_test, ONE){
    auto res = naive_answer(30);
    std::vector<unsigned long> correct_30{25,4,1};
    EXPECT_EQ(correct_30, res);
}

TEST_P(solar_test, TWO){
    auto p = GetParam();
    EXPECT_EQ(naive_answer(p.first), p.second);
}


INSTANTIATE_TEST_CASE_P(GRp, solar_test, testing::ValuesIn(sols));