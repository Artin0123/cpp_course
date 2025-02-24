#include <iostream>
using namespace std;
class X {
  int n;

public:
  X(int getx) { n = getx; }
  int operator-(X x) {
    n = n - x.n;
    return n;
  }
  int operator-() {
    n = -n;
    return n;
  }
  bool operator!() {
    if (n > 10) {
      return true;
    } else {
      return false;
    }
  }
};
int main() {
  X x1(16);
  X x2(7);

  cout << "x1 - x2 > 10 ? " << !x1 << endl;
  cout << "x1 - x2 = " << x1 - x2 << endl;
  cout << "x1 - x2 > 10 ? " << !x1 << endl;
  cout << "x1 - x2 = " << x1 - (-x2) << endl;
  cout << "x1 - x2 > 10 ? " << !x1 << endl;
}