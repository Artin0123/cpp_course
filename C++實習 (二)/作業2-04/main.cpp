// 姓名：林育霆 學號：1101538
// 程式說明：我在main()中令了length, width，
// 他們會經由set()轉換成Rectangle的length和width並回傳，
// 這樣draw()就可以讀取length和width，
// 最後利用for印出圖形，
// 其中的條件是在矩形的內部是空白。
#include <iostream>
using namespace std;
class Rectangle {
  int length;
  int width;

public:
  int set(int length, int width);
  void draw();
};
int Rectangle::set(int l, int w) {
  length = l;
  width = w;
  return length, width;
}
void Rectangle::draw() {
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < length; j++) {
      if ((i > 0 && j > 0) && (i < width - 1 && j < length - 1)) {
        cout << " ";
      } else {
        cout << "*";
      }
    }
    cout << endl;
  }
}
int main() {
  int length, width;
  Rectangle rectangle;
  while (cin >> length >> width) {
    rectangle.set(length, width);
    rectangle.draw();
  }
}