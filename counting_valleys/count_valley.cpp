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

Given Gary's sequence of up and down steps during his last hike, find and print the number of valleys he walked through.

For example, if Gary's path is 
*/

#include <bits/stdc++.h>


int main(){
  int steps;
  std::string step_seq;

  std::cin >> steps;
  std::cin >> step_seq;
  std::cout << "Trip len: " << step_seq.length();
  return 0;
}