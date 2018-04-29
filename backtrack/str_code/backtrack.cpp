#include <iostream>
#include <vector>
#include <string>

// here the backtrack algorithm is useful as there are combinations which are
// not valid in a simple combinatorial tree example 9999
// only produces
// iiii
// there is no char with 3 
int main ()
{
  std::string in;
  std::cin >> in;
  std::cout << in.length();
  return 0;
}
