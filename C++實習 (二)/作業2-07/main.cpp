#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
class Point {
  static float p1[2], p2[2], distance;
  float x, y;

public:
  void operator-(Point second) {
    float difX;
    float difY;
    float dis;
    difX = second.x - x;
    difY = second.y - y;
    dis = sqrt((difX * difX) + (difY * difY));
    if (dis > distance) {
      distance = dis;
      p1[0] = x;
      p1[1] = y;
      p2[0] = second.x;
      p2[1] = second.y;
    }
  };

  void set(float setx, float sety) {
    x = setx;
    y = sety;
  }
  void show();
};

float Point::distance = 0;
float Point::p1[2] = {};
float Point::p2[2] = {};

void Point::show() {
  cout << "Point: (" << p1[0] << ", " << p1[1] << ")" << endl;
  cout << "Point: (" << p2[0] << ", " << p2[1] << ")" << endl;
  cout << "distance: " << distance << endl;
}
int main() {
  vector<Point> points;
  float x, y;
  Point point;

  while (cin >> x >> y) {
    Point temp;
    temp.set(x, y);
    points.push_back(temp);
  }

  for (int i = 0; i < points.size(); i++) {
    for (int j = i + 1; j < points.size(); j++) {
      points[i].operator-(points[j]);
    }
  }
  points[0].show();
}