#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct {
  float pangle;
  float x;
  float y;
  float rad;
}point;

bool comp(const point& x, const point& y)
{
  return (x.pangle < y.pangle);
}

bool comp_d(const point& x, const point& y)
{
  return (x.rad < y.rad);
}

int main()
{
  unsigned int N;
  cin >> N;
  vector<point> points(N);
  for(unsigned int i=0; i<N;++i)
  {
    cin >> points[i].x >> points[i].y;
    // calculate distance
    points[i].rad = sqrt(points[i].x*points[i].x + points[i].y*points[i].y);
    // calculate angle
    auto pang = atan2(points[i].y, points[i].x);
    if(pang < 0){
      pang = 2*3.141592 + pang;
    }
    points[i].pangle = pang;

   // cout << points[i].pangle << endl;
  }

  //stable_sort(points.begin(), points.end(), comp_d);
  stable_sort(points.begin(), points.end(), [](const point& x, const point& y){
        return (x.rad < y.rad);
      });
  //stable_sort(points.begin(), points.end(), comp_d);
  stable_sort(points.begin(), points.end(), [](const point& x, const point& y){
        return (x.pangle < y.pangle);
      });
  //cout << "------\n";
  //for(auto p:points)
 // {
   // cout << "x: " << p.x << " y: " << p.y << " ang: " << p.pangle << "\n";
  //}

  for(auto p:points)
  {
    cout << int(p.x) << " " << int(p.y) << "\n";
  }
  return 0;
}
