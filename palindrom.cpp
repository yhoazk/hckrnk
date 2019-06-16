/* Solution to problem number one */

#include <string>
#include <stdexcept>
#include <iostream>

class Palindrome
{
    public:
        static bool isPalindrome(const std::string& word){
            int m = (word.size() % 2)  + (word.size() >> 1);
            bool palindrom = true;
            auto l2r = word.begin();
            auto r2l = word.rbegin();
            char diff;
            while(m--){
                if(*l2r != *r2l){
                    // they differ, now check if it's only the case
                    diff = (*l2r > *r2l)? (*l2r-*r2l):(*r2l-*l2r);

                    if(diff != ('a' - 'A')){
                        palindrom = false;
                        break;
                    }
                }
                *l2r++; *r2l++;
            }
            return palindrom;
        }

        static bool v2Palindrom(const std::string& word){
            int m = (word.length() %2) + (word.length() >> 1u);
            bool result = true;
            auto l2r = word.begin();
            auto r2l = word.rbegin();
            while(m--){
                if(std::abs((*l2r - *r2l)) != std::abs('a' -'A') && (std::abs(*l2r - *r2l) != 0))
                {
                    result = false;
                    break;
                }
                l2r++;
                r2l++;
            }
            return result;
        }

};

int main()
{
    std::cout << Palindrome::isPalindrome("Deleveled") << "True\n";
    std::cout << Palindrome::isPalindrome("Deliveled") << "false\n";
    std::cout << Palindrome::isPalindrome("Delereled") << "True\n";
    std::cout << Palindrome::isPalindrome("Delewrweled") << "True\n";
    std::cout << Palindrome::isPalindrome("Deleveler") << "False\n";
    std::cout << Palindrome::isPalindrome("DelevELED") << "true\n";
    std::cout << Palindrome::isPalindrome("DeleELED") << "True\n";
    std::cout << Palindrome::isPalindrome("Anitalavalatina") << "True\n";
    std::cout << Palindrome::isPalindrome("PerroRabioso De caca ") << "False\n";
    std::cout << Palindrome::isPalindrome("                 ") << "True?\n";

    std::cout << Palindrome::v2Palindrom("Deleveled") << "True\n";
    std::cout << Palindrome::v2Palindrom("Delireled") << "false\n";
    std::cout << Palindrome::v2Palindrom("Delewrweled") << "True\n";
    std::cout << Palindrome::v2Palindrom("Deleveler") << "False\n";
    std::cout << Palindrome::v2Palindrom("DelevELED") << "true\n";
    std::cout << Palindrome::v2Palindrom("DeleELED") << "True\n";
    std::cout << Palindrome::v2Palindrom("Anitalavalatina") << "True\n";
    std::cout << Palindrome::v2Palindrom("PerroRabioso De caca ") << "False\n";
    return 0;
}
