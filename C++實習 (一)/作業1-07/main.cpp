#include <iostream>
using namespace std;
int main() {
  int year;
  cout << "輸入年份：";
  cin >> year;
  if(year%400 == 0){
    cout << "閏";
  }
  else{
    if(year%100 == 0){
      cout << "平";
    }
    else{
      if(year%4 == 0){
        cout << "閏";
      }
      else{
        cout << "平";
      }
    }
  }
}