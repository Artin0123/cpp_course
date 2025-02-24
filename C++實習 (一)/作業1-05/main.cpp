#include <iostream>
using namespace std;
int main() {
  int taiwan,tw2;
  cout << "請輸入台灣時間：";
  cin >> taiwan;
  if(taiwan < 15){
    taiwan=taiwan+9;
  }
  else{
    taiwan=taiwan-15;
  }
  cout << "美國時間：" << taiwan << endl;
  cout << "請輸入台灣時間：";
  cin >> taiwan;
  taiwan=taiwan+9;
  tw2=taiwan%24;
  cout << "美國時間：" << tw2 << endl;
}