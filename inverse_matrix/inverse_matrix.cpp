#include <bits/stdc++.h>
// calculate the size of the resulting mat
// Solve by backtrack on each sliding part
using dim = std::pair<int,int>;
using mat = std::vector<std::vector<int>>;

inline bool operator==(const dim& a, const dim& b) {
    return !!( std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b) );
}

template<class T>
inline bool operator==(const dim& a, const std::initializer_list<T>b) {
    std::cerr << "Initializer list" << std::endl;
    return !!( std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b) );
}

dim calc_out(dim r, dim s) {
    return {std::get<0>(r)-std::get<0>(s) + 1, std::get<1>(r) - std::get<1>(s) + 1};
}

void show(const mat& m ) {

    for(const auto& r : m ) {
        std::cerr << "|";
        for(const auto& c : r) {
            printf("%2d\t", c);
        }
        std::cerr << "|" << std::endl;
    }
}

// inline bool operator==(const mat& a, const mat& b) {
//     for (auto const& r)
// }

inline dim get_dim(const mat& m) {
    return {m.size(), m[0].size()};
}

mat fwd(const mat& m, dim di) {
    mat res{};
    const auto out_dim{calc_out(get_dim(m), di)};
    res.resize(out_dim.first);

    for (auto& row : res) {
        row.resize(out_dim.second);
    }

    for(int j{0}; j < out_dim.first; j++) {
        for (int n{0}; n < out_dim.second; n++) {
            int acc{};
            for(int a{j}; a < j+di.first; a++) {
                for(int b{n}; b < n+di.second; b++) {
                    acc += m[a][b];
                    // std::cerr << "m[" << a << "][" << b << "] = " << m[a][b] << std::endl; 
                }
            }
            res[j][n] = acc;
        }
    }
    return res;
}

int main () {
    auto n{calc_out({1,2},{2,3})};
    mat x {
        { 1, -3, -1,  5},
        { 2,  3,  1,  4},
        {-3,  3,  7,  3},
        { 4, -1,  6,  2},
    };

    show(x);
    auto n2{get_dim(x)};
    assert(std::get<0>(n2) == 4);
    assert(std::get<1>(n2) == 4);

    {
        dim a {calc_out({5,3},{2,2})};
        dim b{4,2};
        assert(a == b );
    }
    {
        dim a {calc_out({4,4},{2,2})};
        dim b{3,3};
        assert(a == b );
    }

    dim w{2,2};

   show ( fwd(x, w) );
    return 0;
}