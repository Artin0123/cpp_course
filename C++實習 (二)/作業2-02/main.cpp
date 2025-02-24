// 學號：1101538 姓名：林育霆
// 程式說明：我先將字串的每一個字元去比較是否在英文字母的ascii code內，
// 再將它們轉換到nodes的52個空間內，並記錄出現的次數和存取他們的字元，
// 最後輸出nodes。
#include <iostream>
#include <string>
using namespace std;
struct Node {
  char c;
  int ascii;
  int count = 0;
};
int main() {
  string s;
  while (getline(cin, s)) {
    Node nodes[52];
    for (int i = 0; i < s.length(); i++) {
      if (int(s[i]) >= 65 && int(s[i]) <= 90) {
        nodes[int(s[i]) - 65].count++;
        nodes[int(s[i]) - 65].c = s[i];
      }
      if (int(s[i]) >= 97 && int(s[i]) <= 122) {
        nodes[int(s[i]) - 97 + 26].count++;
        nodes[int(s[i]) - 97 + 26].c = s[i];
      }
    }
    for (int j = 0; j < 52; j++) {
      if (nodes[j].count > 0) {
        cout << nodes[j].c << " => " << nodes[j].count << endl;
      }
    }
  }
}