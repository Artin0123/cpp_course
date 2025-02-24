// 姓名：林育霆 學號：1101538
// 程式說明：我在Book的constructor內將title, price, author初始化並存起來，
// 接著將得到的price和p1比較，
// 由於p1和t1有加上static，
// 因此最大的值會保留並由f()輸出。
#include <ctime>
#include <iostream>
using namespace std;
class Book {
  string title, author;
  int price;
  static string t1;
  static int p1;
  void compare();

public:
  void f() { cout << "Max Price Book is " << t1 << " ( " << p1 << " ) "; }
  Book(string t = "", int p = -1, string a = "") {
    srand(time(NULL));
    if (p == -1) {
      p = rand() % 900 + 100;
    }
    title = t;
    price = p;
    author = a;
    compare();
  }
};
string Book::t1 = "";
int Book::p1 = 0;
void Book::compare() {
  if (price > p1) {
    p1 = price;
    t1 = title;
  }
}
int main() {
  Book b1("AAA");
  Book *b2 = new Book("BBB", 123);
  Book *b3 = new Book("CCC", 369, "Bob");
  b3->f();
}