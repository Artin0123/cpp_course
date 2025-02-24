/*學號:1101538，姓名:林育霆
*文字說明:這個作業當中，我利用4個變數name,birth,level,reason分別存放名*字、生日、對程式的熟悉度、選擇資工系的原因並利用cout做印出。
*/
#include <iostream>
using namespace std;
int main() {
  string name = "林育霆";
  int birth = 18;
  int level = 2;
  string reason = "想要創作遊戲發大財";
  cout << "Hi，我的名字是 " << name;
  cout << "，今年 " << birth << " 歲\n";
  cout << "對於程式的熟悉程度 " << level << " 分，";
  cout << "會填資工系是因為： " << reason << "。";
}