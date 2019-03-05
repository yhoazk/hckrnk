/*
Gary is an avid hiker. He tracks his hikes meticulously, paying close 
attention to small details like topography. During his last hike he took
exactly n steps. For every step he took, he noted if it was an uphill, `U`, or
`D` a downhill, step. Gary's hikes start and end at sea level and each step up
or down represents a 1 unit change in altitude. We define the following terms:
- A mountain is a sequence of consecutive steps above sea level, starting with
  a step up from sea level and ending with a step down to sea level.
- A valley is a sequence of consecutive steps below sea level, starting with a
step down from sea level and ending with a step up to sea level.

Given Gary's sequence of up and down steps during his last hike, find and print
the number of valleys he walked through.

For example, if Gary's path is DDUUUUDD he first enters a valley 2 units deep.
Then he climbs out an up onto a mountain units high. Finally, he returns to sea
level and ends his hike.

Example:
8
UDDDUDUU

Expected
1
*/

#include <bits/stdc++.h>


int countingValleys(int n, std::string step_seq) {
  int steps;
  signed int level = 0; // we start at sea level
  bool went_up = true; // is only a valley if we went first to a mountain
  int valleys;
  //assert(steps == step_seq.length());

  for(auto c: step_seq){
    switch(c){
      case 'D':
        if(level == 0 && went_up){
          std::cout << "valllley\n";
          valleys++;
          went_up = false;
        }
        --level;
        std::cout << "Down\n";
      break;
      case 'U':
        std::cout << "Up\n";
        if(!went_up && (level == -1)){
          std::cout << "uppp\n";
          went_up = true;
        }
        ++level;
      break;
      default:
        std::cerr << "Undefined char\n";
      break;
    }
  }
return valleys;
}

int main()
{
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string s;
    getline(std::cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}