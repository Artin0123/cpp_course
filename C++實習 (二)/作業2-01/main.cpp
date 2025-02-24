#include <iostream>
using namespace std;
int main() {
  char c;
  char *a;
  a = new char[200];
  int count = 0;
  while (cin >> c) {
    a[int(c)] = 1;
    if (c == '0') {
      break;
    }
  }
  cout << " ----- " << endl;
  while (cin >> c) {
		if (a[int(c)] == 0) {
      cout << c << " 不存在" << endl;
    }
    if (a[int(c)] == 1) {
      cout << c << " 有存在" << endl;
      a[int(c)]--;
    }
  }
  delete[] a;
}