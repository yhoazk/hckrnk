#if 0
--- Day 3: Perfectly Spherical Houses in a Vacuum ---

Santa is delivering presents to an infinite two-dimensional grid of houses.

He begins by delivering a present to the house at his starting location, and then an elf at the North Pole calls him via radio and tells him where to move next. Moves are always exactly one house to the north (^), south (v), east (>), or west (<). After each move, he delivers another present to the house at his new location.

However, the elf back at the north pole has had a little too much eggnog, and so his directions are a little off, and Santa ends up visiting some houses more than once. How many houses receive at least one present?

For example:

    > delivers presents to 2 houses: one at the starting location, and one to the east.
    ^>v< delivers presents to 4 houses in a square, including twice to the house at his starting/ending location.
    ^v^v^v^v^v delivers a bunch of presents to some very lucky children at only 2 houses.

--- Part Two ---

The next year, to speed up the process, Santa creates a robot version of himself, Robo-Santa, to deliver presents with him.

Santa and Robo-Santa start at the same location (delivering two presents to the same starting house), then take turns moving based on instructions from the elf, who is eggnoggedly reading from the same script as the previous year.

This year, how many houses receive at least one present?

For example:

    ^v delivers presents to 3 houses, because Santa goes north, and then Robo-Santa goes south.
    ^>v< now delivers presents to 3 houses, and Santa and Robo-Santa end up back where they started.
    ^v^v^v^v^v now delivers presents to 11 houses, with Santa going one direction and Robo-Santa going the other.



#endif

#include <bits/stdc++.h>

std::vector<std::string> loadWords(std::string filename)
{
    std::ifstream wordfile(filename);
    std::string word;
    std::vector<std::string> wordlist;
    while (getline(wordfile, word))
    {
        wordlist.push_back(word);
    }
    return wordlist;
}

// using a map to store a pair
// each time the it reaches the location increase by 1

// for first step size is the ans
using locations = std::map<std::pair<size_t, size_t>, size_t>;
using uniq_locations = std::set<std::pair<size_t, size_t>>;

std::map<char, std::pair<size_t, size_t>> moves{
    {'^', {1, 0}},
    {'v', {-1, 0}},
    {'<', {0, -1}},
    {'>', {0, 1}},
};

size_t visited_houses(std::string mvs)
{
    size_t x{0};
    size_t y{0};
    locations loc{{{0, 0}, 1}}; // first location starts with 1
    for (const auto &m : mvs)
    {
        const auto[incx, incy] = moves[m];
        x += incx;
        y += incy;
        loc[{x,y}] += 1;
    }
    return loc.size();
}


size_t visited_houses_robot(std::string mvs)
{
    size_t x_santa{0};
    size_t y_santa{0};
    size_t x_robot{0};
    size_t y_robot{0};
    locations loc_santa{{{0, 0}, 1}}; // first location starts with 1
    locations loc_robot{}; // first location starts with 1
    uniq_locations ulocs;
    int santa_or_robot{1};
    for (const auto &m : mvs)
    {
        const auto[incx, incy] = moves[m];
        if(santa_or_robot) {
            x_santa += incx;
            y_santa += incy;
            loc_santa[{x_santa, y_santa}] += 1;
        } else {
            x_robot += incx;
            y_robot += incy;
            loc_robot[{x_robot, y_robot}] += 1;
        }
        santa_or_robot ^= 1;
    }
    // get the unique locations
    for(const auto& [k,v] : loc_santa) {
        ulocs.insert(k);
    }
    for(const auto& [k,v] : loc_robot) {
        ulocs.insert(k);
    }

    return ulocs.size();
}

int main()
{

    std::string input;
    auto vals{loadWords("input.orig")};
    size_t sum{0};
    for (auto const& seq : vals) {
        std::cout << visited_houses(seq) << std::endl; //2081
        std::cout << visited_houses_robot(seq) << std::endl; // 2341
    }

    assert(2 == visited_houses(">"));
    assert(4 == visited_houses("^>v<"));
    assert(2 == visited_houses("^v^v^v^v^v"));
    // 2081
    // part 2
    assert(3 ==  visited_houses_robot("^v"));
    assert(3 ==  visited_houses_robot("^>v<"));
    assert(11 == visited_houses_robot("^v^v^v^v^v"));
    // 2081


    return 0;
}