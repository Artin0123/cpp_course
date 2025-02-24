#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;
string suits[4] = {"黑桃", "梅花", "愛心", "方塊"};
string faces[13] = {"A", "2", "3",  "4", "5", "6", "7",
                    "8", "9", "10", "J", "Q", "K"};
class Card {
  int suit, face;

public:
  int getsuit();
  int getface();
  Card(int s, int f) {
    suit = s;
    face = f;
  };
};
int Card::getsuit() { return suit; }
int Card::getface() { return face; }
class Cards {
  vector<Card> cards;

public:
  Cards() {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 13; j++) {
        Card temp(i, j);
        cards.push_back(temp);
      }
    }
  };
  void shuffle();
  void show();
};
void Cards::show() {
  for (int i = 0; i < 52; i++) {
    int m = cards[i].getsuit();
    int n = cards[i].getface();
    cout << suits[m] << " " << faces[n] << endl;
  }
}
void Cards::shuffle() {
  for (int i = 0; i < 1000; i++) {
    int n1 = rand() % 52;
    int n2 = rand() % 52;
    Card temp = cards[n1];
    cards[n1] = cards[n2];
    cards[n2] = temp;
  }
}
int main() {
  srand(time(NULL));
  Cards cards;
  cout << "========洗牌前=========" << endl;
  cards.show();
  cout << "========洗牌後=========" << endl;
  cards.shuffle();
  cards.show();
}