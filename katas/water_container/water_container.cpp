#include <bits/stdc++.h>
#include <gtest/gtest.h>

/**
 * 
 * @brief 
 * # Water container
 * calculate the amount of water a container with the shape
 * of the given numbers kn = number of levels
 * and kv=levels. 
 * for example: 
 * 4
 * 3,0,0,3
 * #    #
 * #    #
 * #    #
 * ---------
 * 6 units of water can be contained in that shape, so the 
 * expected output is 6
 */


struct solution {
    struct max_vals {
        size_t ml;
        size_t mr;
        size_t min() {
            return std::min(ml, mr);
        }
    };
    size_t solve(size_t kn, std::vector<size_t> kvs) {
        std::vector<max_vals> mvs{kn};
        size_t curr_m{kvs[0]};
        size_t idx{0};
        size_t acc{0};
        for(const auto& kv : kvs) {
            if (curr_m < kv){
                curr_m = kv;
            }
            mvs[idx++].ml = curr_m;
        }
        idx--;
        curr_m = kvs[idx];
        auto rb{std::rbegin(kvs)};
        auto re{std::rend(kvs)};
        while(rb != re) {
            if (curr_m < *rb){
                curr_m = *rb;
            }
            mvs[idx--].mr = curr_m;
            rb++;
        }
        idx = 0;
        for (auto& e : mvs) {
            // std::cerr << "ml:" << e.ml << " mr:" << e.mr << " kv:" << kvs[idx];
            // std::cerr <<  "| min() - currh: " << e.min() - kvs[idx] << std::endl;
            acc += e.min() - kvs[idx++];
        }
        return acc;
    }
};


TEST(water_container, sample1) {
    solution s{};
    std::vector<size_t> v{1,2,1,1};
    ASSERT_EQ(s.solve(v.size(), v), 0);
}

TEST(water_container, sample2) {
    solution s{};
    std::vector<size_t> v{1,0,1,1};
    ASSERT_EQ(s.solve(v.size(), v), 1);
}

TEST(water_container, sample3) {
    solution s{};
    std::vector<size_t> v{3,0,2,0,3};
    ASSERT_EQ(s.solve(v.size(), v), 7);
}

TEST(water_container, sample4) {
    solution s{};
    std::vector<size_t> v{4,4,3,0,4,1,4,4};
    ASSERT_EQ(s.solve(v.size(), v), 8);
}

TEST(water_container, sample5) {
    solution s{};
    std::vector<size_t> v{0,0,0,0,7,0,0,0,0};
    ASSERT_EQ(s.solve(v.size(), v), 0);
}

TEST(water_container, sample6) {
    solution s{};
    std::vector<size_t> v{0,2,3,1,2,1,1,3,1};
    ASSERT_EQ(s.solve(v.size(), v), 7);
}