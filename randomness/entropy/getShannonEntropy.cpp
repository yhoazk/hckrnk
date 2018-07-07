#include <bits/stdc++.h>
#if 0
Descritption:
The formula well apply is H2 to have the bits/symbol entropy
Sum((Counti/N) * log2(counti*N))

For the string 1223334444 = 1.84644
#endif



using namespace std;

float  getShannonEntropy(std::string str){
  float entropy = 0;
  /* get length */
  int n = str.length();
  map<char, int> counti;
  /* get count of symbols per symbol */
  for(auto c: str){
    //cout << c << "-";
      counti[c]++; // the pair is initialized with 0
  }
  // N is the symbols in the given string or in the alphabeth?
  // answer: the amount of different symbols in the given string
  /* sum the log2s  */
  for(auto p : counti){
    entropy -= (p.second/static_cast<float>(n)) * (log2(p.second/static_cast<float>(n)));
  }

  /*for(auto s : counti){
    cout << s.first << ":" << s.second << endl;
  }*/
  // to veerify that a map initsthe second element of the pair with 0
  //cout << counti['a'];
  return entropy;
}


int main(int argc, char const *argv[]) {
  std::string input;
  //cin >> input; // this reads words not lines
  getline(cin, input);
  cout << "Entropy of  " << input << " is: " << getShannonEntropy(input) << endl;
  assert(abs(getShannonEntropy("1223334444") - 1.84644) < 0.0001);
  return 0;
}
