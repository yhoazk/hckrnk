#include <iostream>
#include <vector>
using namespace std;
#define BASE_2 (4)
/*
 * input -> base conversion -> LUT -> format -> print
 * */
/* {} initialization only for C++11 >  */
vector<vector<char>> code_lut = {{' ', '|', ' '}, /*0*/
                                 {'|', '|', ' '}, /*1*/
                                 {' ', '|', '|'}, /*2*/
                                 {'|', '|', '|'}}; /*3*/

/* NOTE: there is no guarantee of contiguous array data in this case */
vector<vector<char>> solution;

/* This is a generic conversion function to convert from int to any 2^n base */
void convert_base4(int value, vector<char>& conv)
{
   
  while(value >= BASE_2) 
  {
//    cout << (int)(value & 0x03) << ' ';
    conv.push_back((char)value & 0x3);
    value >>= 2; // divide by 4
  }
  conv.push_back((char)value & 0x3);
//  cout << conv.size();
}

int main()
{
  int input;
  cin >> input;
  
  vector<char> base4;
  convert_base4(input, base4);
  /* add mark */
  base4.insert(base4.begin(),1);
  base4.insert(base4.begin(),0);
  base4.push_back(0);
  base4.push_back(1);
  solution.resize(base4.size());
  int i = 0;
  for(auto& v : solution) // remember to add the & to affect the referenced vector
  {
    v.resize(code_lut[0].size());
    auto curr_char = code_lut[(int)base4[i]].begin();
    copy(curr_char, curr_char+3,  v.begin());
    ++i;
  }
  /* Traverse the solution array */
  char* sol = &solution[0][0];
 
/*
  for(auto r: solution)
  {

    for(auto c: r)
    {
      cout << c << " ";
    }
      cout << "\n";
  }
  cout << "\n\n";
*/
  //for(int i = 2; i >= 0; --i)
  for(int i = 0; i < 3; ++i)
  {
    for(int j = solution.size()-1; j >=0; --j)
    {
      cout << solution[j][i] << " ";  
    }
    sol += sizeof(char);
  cout << "\n";
  }
  return 0;
}
