// 姓名：林育霆 學號：1101538
// 程式說明：我先按照題意令了set(),get()和price，
// 並產生10個1000以內的亂數放到set()內，
// set()把他們變成price後由get()回傳，
// 我利用for比較這些數字，
// 如果前者的數值比後者小就交換，
// 最後輸出排序後的數字。
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
struct Book {
private:
  double price;

public:
  void set(double p);
  double get(void);
};
void Book::set(double p) { price = p; };
double Book::get(void) { return price; }

int main() {
  srand(time(NULL));
  int n = 10;
  Book books[n];
  for (int i = 0; i < n; i++) {
    books[i].set(rand() % 1000);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (books[i].get() < books[j].get()) {
        swap(books[i], books[j]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << books[i].get() << endl;
  }
}