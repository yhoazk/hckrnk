#include <bits/stdc++.h>
// calculate the size of the resulting mat
// Solve by backtrack on each sliding part
using dim = std::pair<int, int>;
using mat = std::vector<std::vector<int>>;

inline bool operator==(const dim &a, const dim &b)
{
    return !!(std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b));
}

template <class T>
inline bool operator==(const dim &a, const std::initializer_list<T> b)
{
    std::cerr << "Initializer list" << std::endl;
    return !!(std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b));
}

// Calculate fwd dimensions
dim calc_out(dim r, dim s)
{
    return {std::get<0>(r) - std::get<0>(s) + 1, std::get<1>(r) - std::get<1>(s) + 1};
}

// calculate reverse dimensions
dim calc_out_rev(dim r, dim s)
{
    return {std::get<0>(r) + std::get<0>(s) - 1, std::get<1>(r) + std::get<1>(s) - 1};
    // dim d{std::get<0>(r) + std::get<0>(s) - 1, std::get<1>(r) + std::get<1>(s) - 1};
    // std::cerr << "{ " << d.first << ", " << d.second << " }" << std::endl;
    // return d;
}

void show(const mat &m)
{

    for (const auto &r : m)
    {
        std::cerr << "|";
        for (const auto &c : r)
        {
            printf("%2d\t", c);
        }
        std::cerr << "|" << std::endl;
    }
}

inline dim get_dim(const mat &m)
{
    return {m.size(), m[0].size()};
}

mat fwd(const mat &m, const dim &di)
{
    mat res{};
    const auto out_dim{calc_out(get_dim(m), di)};
    res.resize(out_dim.first);

    for (auto &row : res)
    {
        row.resize(out_dim.second);
    }

    for (int j{0}; j < out_dim.first; j++)
    {
        for (int n{0}; n < out_dim.second; n++)
        {
            int acc{};
            for (int a{j}; a < j + di.first; a++)
            {
                for (int b{n}; b < n + di.second; b++)
                {
                    acc += m[a][b];
                    // std::cerr << "m[" << a << "][" << b << "] = " << m[a][b] << std::endl;
                }
            }
            res[j][n] = acc;
        }
    }
    return res;
}

int eval(mat &m, int goal_val)
{
    int acc{};
    const auto d{get_dim(m)};
    for (int i{0}; i < d.first; i++)
    {
        for (int j{0}; j < d.second; j++)
        {
            // std::cerr << "m[" << i << "][" << j << "] = " << m[i][j] << std::endl;
            acc += m[i][j];
        }
    }

    // std::cerr << "eval: " << goal_val - (acc - m[d.first - 1][d.second - 1]) << std::endl;
    return goal_val - (acc - m[d.first - 1][d.second - 1]);
}

mat rev(const mat &m, const dim &d)
{
    mat rev{};
    mat win{};

    const auto out_dim{calc_out_rev(get_dim(m), d)};
    win.resize(d.first);
    for (auto &row : win)
    {
        row.resize(d.second);
    }
    rev.resize(out_dim.first);
    for (auto &row : rev)
    {
        row.resize(out_dim.second);
    }

    const auto in_dim{get_dim(m)};

    for (int j{0}; j < in_dim.first; j++)
    {
        for (int n{0}; n < in_dim.second; n++)
        {
            int goal{m[j][n]};
            // std::cerr << ">m[" << j << "][" << n << "] = " << m[j][n] << std::endl;
            mat rev_win{};
            rev_win.resize(d.first);
            for (auto &r : rev_win)
            {
                r.resize(d.second);
            }
            // copy rev values to temp window
            // std::cerr << "=========" << std::endl;
            for (int x{0}; x < d.first; x++)
            {
                for (int y{0}; y < d.second; y++)
                {
                    rev_win[x][y] = rev[j + x][n + y];
                }
            }
            // show(rev_win);
            // std::cerr << "=========" << std::endl;
            // done
            for (int a{j + d.first-1}; a < out_dim.first; a++)
            {
                for (int b{n + d.second-1}; b < out_dim.second; b++)
                {

                    rev[a][b] = eval(rev_win, goal);
                    // std::cerr << "rev[" << a << "][" << b << "] = " << m[a][b] << std::endl;
                }
            }
            // rev[j][n] = goal;
        }
    }

    return rev;
}

int main()
{
    auto n{calc_out({1, 2}, {2, 3})};
    mat x{
        {1, -3, -1, 5},
        {2, 3, 1, 4},
        {-3, 3, 7, 3},
        {4, -1, 6, 2},
    };

    mat k{
        {1, 1, 3, 7, 6, -7, 4},
        {0, 9, 3, 0, 11, 9, 2},
        {2, 7, 8, 1, 14, 9, 6},
    };

    // show(x);
    // auto n2{get_dim(x)};
    // assert(std::get<0>(n2) == 4);
    // assert(std::get<1>(n2) == 4);

    // {
    //     dim a{calc_out({5, 3}, {2, 2})};
    //     dim b{4, 2};
    //     assert(a == b);
    // }
    // {
    //     dim a{calc_out({4, 4}, {2, 2})};
    //     dim b{3, 3};
    //     assert(a == b);
    // }
    // {
    //     dim a{calc_out_rev({3, 3}, {2, 2})};
    //     dim b{4, 4};
    //     assert(a == b);
    // }
    // {
    //     dim a{calc_out_rev({2, 4}, {2, 2})};
    //     dim b{3, 5};
    //     assert(a.first == b.first);
    //     assert(a.second == b.second);
    //     assert(a == b);
    // }

    // {
    //     mat r{
    //         {11, -5},
    //         {1, 1}};
    //     int goal{18};
    //     assert(eval(r, goal) == 11);
    // }

    // dim w{2, 2};

    // auto f{fwd(x, w)};
    // show(f);

    // std::cerr << "-------------------" << std::endl;

    // auto r{rev(f, w)};
    // show(r);
    // assert(f == fwd(r, w));

    std::cerr << "\n-------------------\n" << std::endl;
    dim kw{2, 3};
    auto kfwd{fwd(k, kw)};
    show(kfwd);

    auto kr{rev(kfwd, kw)};
    show(kr);
    assert(kfwd == fwd(kr, kw));

    return 0;
}