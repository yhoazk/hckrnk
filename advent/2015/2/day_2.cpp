#include <bits/stdc++.h>


size_t surface(size_t  l, size_t w, size_t h) {
    std::initializer_list<size_t> s{(l*w),(w*h),(h*l)};

    auto m{ std::min(s) };
    auto n  = std::accumulate(std::begin(s), std::end(s), 0);
    return 2*n + m;
}

size_t ribbon(size_t  l, size_t w, size_t h) {
    std::array<size_t, 3> s{(l),(w),(h)};
    std::sort(s.begin(), s.end());
    auto p = s[0] + s[1]+ s[0] + s[1];
    auto bow = s[0] * s[1] * s[2];
    return p + bow;

}

std::vector<std::array<size_t,3>> loadWords(std::string filename) {
    std::ifstream wordfile(filename);
    std::string word;
    std::vector<std::array<size_t, 3>> wordlist;
    while (getline(wordfile, word)) {
        // input: axbxc
        size_t w,h,l;
        int start{};
        auto end{word.find('x')};
        // w = atol(word.substr(start, end -start));
        w = atol(word.substr(start, end -start).c_str());
        start = end + 1;
        end = word.find('x', start);
        h = atol(word.substr(start, end -start).c_str());
        start = end + 1;
        end = word.find('x', start);
        l = atol(word.substr(start, end -start).c_str());
        wordlist.push_back({w,h,l});
    }
    return wordlist;
}


int main() {
        assert(58 == surface(2,3,4));
        assert(43 == surface(1,1,10));

        std::string input;
        auto vals{loadWords("input")};
        size_t sum{0};
        size_t sum_ribbon{0};

        for(const auto& e: vals) {
            sum += surface(e[0], e[1], e[2]);
            sum_ribbon += ribbon(e[0], e[1],e[2]);
        }
        std::cerr << sum << std::endl;
        std::cerr << sum_ribbon << std::endl;


        return 0;
}