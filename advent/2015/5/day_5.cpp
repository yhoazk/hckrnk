#include <bits/stdc++.h>
#if 0
--- Day 5: Doesnt He Have Intern-Elves For This? ---

Santa needs help figuring out which strings in his text file are naughty or nice.

A nice string is one with all of the following properties:

    It contains at least three vowels (aeiou only), like aei, xazegov, or aeiouaeiouaeiou.
    It contains at least one letter that appears twice in a row, like xx, abcdde (dd), or aabbccdd (aa, bb, cc, or dd).
    It does not contain the strings ab, cd, pq, or xy, even if they are part of one of the other requirements.

For example:

    ugknbfddgicrmopn is nice because it has at least three vowels (u...i...o...), a double letter (...dd...), and none of the disallowed substrings.
    aaa is nice because it has at least three vowels and a double letter, even though the letters used by different rules overlap.
    jchzalrnumimnmhp is naughty because it has no double letter.
    haegwjzuvuyypxyu is naughty because it contains the string xy.
    dvszwmarrgswjxmb is naughty because it contains only one vowel.

How many strings are nice?
--- Part Two ---

Realizing the error of his ways, Santa has switched to a better model of determining whether a string is naughty or nice. None of the old rules apply, as they are all clearly ridiculous.

Now, a nice string is one with all of the following properties:

    It contains a pair of any two letters that appears at least twice in the string without overlapping, like xyxy (xy) or aabcdefgaa (aa), but not like aaa (aa, but it overlaps).
    It contains at least one letter which repeats with exactly one letter between them, like xyx, abcdefeghi (efe), or even aaa.

For example:

    qjhvhtzxzqqjkmpb is nice because is has a pair that appears twice (qj) and a letter that repeats with exactly one letter between them (zxz).
    xxyxx is nice because it has a pair that appears twice and a letter that repeats with one between, even though the letters used by each rule overlap.
    uurcxstgmygtbstg is naughty because it has a pair (tg) but no repeat with a single letter between them.
    ieodomkazucvgmuy is naughty because it has a repeating letter with one between (odo), but no pair that appears twice.

How many strings are nice under these new rules?



#endif

std::vector<std::string> loadStrings(const std::string &fname)
{
    std::ifstream fss{fname};
    // std::istream ss;
    std::string line;
    std::vector<std::string> ans{};

    while (getline(fss, line))
    {
        // std::cerr << << line << std::endl;
        ans.push_back(line);
    }

    return ans;
}

struct vowel_count
{
    size_t a;
    size_t e;
    size_t i;
    size_t o;
    size_t u;
};

vowel_count count_vowel(const std::string &in)
{
    vowel_count vc{};
    for (const auto &c : in)
    {
        if ('a' == c)
        {
            vc.a++;
        }
        else if ('e' == c)
        {
            vc.e++;
        }
        else if ('i' == c)
        {
            vc.i++;
        }
        else if ('o' == c)
        {
            vc.o++;
        }
        else if ('u' == c)
        {
            vc.u++;
        }
    }
    return vc;
}

// return the position where appears and the double letter
// naive version, try find_adjacent
std::pair<ssize_t, char> letter_appears_twice(const std::string &in)
{
    std::pair<ssize_t, char> rv{-1, '^'};
    if (in.size() >= 2)
    {
        auto it{std::begin(in)};
        auto it_next{std::next(it)};
        const auto &eit{std::end(in)};
        while (it_next != eit)
        {
            if (*it == *it_next)
            {
                rv = std::make_pair(std::distance(std::begin(in), it), *it);
                break;
            }
            it = std::next(it);
            it_next = std::next(it_next);
        }
    }

    return rv;
}

std::pair<ssize_t, char> seq_appears(const std::string &in, const std::vector<std::string> &seq)
{
    std::pair<ssize_t, char> rv{-1, '^'};

    if (in.size() >= 2)
    {
        auto it{std::begin(in)};
        auto it_next{std::next(it)};
        const auto &eit{std::end(in)};
        while (it_next != eit)
        {
            std::string s{*it};
            s += *it_next;

            // std::cerr << "painr: " << s <<std::endl;
            for (const auto &r : seq)
            {
                if (s == r)
                {
                    rv = std::make_pair(std::distance(std::begin(in), it), *it);
                    break;
                }
            }
            it = std::next(it);
            it_next = std::next(it_next);
        }
    }

    return rv;
}

bool rule2(const std::string &in)
{
}

int main()
{
    const auto words{loadStrings("input_off")};
    std::vector<std::string> naugthy_seq{
        "ab", "cd", "pq", "xy"};
    // std::cerr << "VC: " << count_vowel("aaaee").a << std::endl;

    // std::cerr << "Dup: " << letter_appears_twice("awerfdsppfwef").second << std::endl;
    // std::cerr << "Dup: " << letter_appears_twice("aa").second << std::endl;

    // std::cerr << "Dup: " << seq_appears("awerfdsppfwef", naugthy_seq).second << std::endl;
    // std::cerr << "Dup: " << seq_appears("aa", naugthy_seq).second << std::endl;
    int nice{};
    for (const auto& w : words) {
        bool naug{false};
        std::cerr << w << " : ";
        auto cv{count_vowel(w)};
        if ((cv.a + cv.e + cv.i + cv.o + cv.u) >= 3) {
            // std::cerr << "Vowel twice: " << w << std::endl;
        } else {
            // std::cerr << "Vowel naug: " << w << std::endl;
            naug = true;
        }

        if (letter_appears_twice(w).first != -1L) {
            // std::cerr << "Appears tw: " << w << std::endl;
        } else {
            // std::cerr << "Does not appears " << w << std::endl;
            naug = true;
        }

        if (seq_appears(w, naugthy_seq).first == -1l) {
            // std::cerr << "Forbidden not found: " << w << std::endl;
        } else {
            // std::cerr << "Forbiden " << w << std::endl;
            naug = true;
        }
        if (naug) {
            std::cerr << "NAUG" << std::endl;
        } else {
            nice++;
            std::cerr << "NICE" << std::endl;

        }

    }
    std::cerr << "Nice: " << nice << std::endl; // not 335 its 238
    return 0;
}

// https://www.amazon.jobs/en/landing_pages/software-development-topics
// https://amazon.jobs/en/jobs/2209500/senior-software-dev-engineer-amazon-smart-vehicle
// https://www.amazon.jobs/en/software-development-interview-prep?INTCMPID=OAAJAZ100026B#/