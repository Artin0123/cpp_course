#include <iostream>
using namespace std;
int main() {
  int count1,chinese,math;
  cin >> count1;
  chinese=(count1+2)/3;
  math=((count1+2)%3)+1;
  cout << chinese << "," << math;
}
// 120120120
// 342342342
// 012012012
// 123123123