// 學號：1101538 姓名：林育霆
// 這個作業我定義了C和F兩個變數分別代表攝氏溫度和華氏溫度，
// 並輸出C和計算後的F
#include <iostream>
using namespace std;
int main() {
  double C,F;
  cout << "請輸入一個攝氏溫度： ";
  cin >> C;
  F=C*9/5+32;
  cout << "你輸入的攝氏溫度是： " << C << endl;
  cout << "轉換為華氏溫度是： " << F << endl;
  return 0;
}