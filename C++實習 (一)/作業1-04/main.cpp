// 學號：1101538 姓名：林育霆
// 這個作業我定義了a,b,c,d，我將a和b的輸入的數值交換並輸出
#include <iostream>
using namespace std;
int main() {
  int a,b,c,d;
  cin >> a >> b;
  cout << "(交換前) a = " << a << ", b = " << b << endl;
  c=a;
  d=b;
  b=c;
  a=d;
  cout << "(交換後) a = " << a << ", b = " << b << endl;
  return 0;
}