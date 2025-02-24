#include <iostream>
#include <vector>
using namespace std;
class Set {
  vector<int> elements;

public:
  Set operator|(Set s) {
    Set temp;
    for (int i = 0; i < elements.size(); i++) {
      temp.elements.push_back(elements[i]);
    }
      for (int j = 0; j < s.elements.size(); j++) {
        if (!contain(s.elements[j])) {
          temp.elements.push_back(s.elements[j]);
        }
      }
    return temp;
  }
  Set operator&(Set s) {
    Set temp;
      for (int j = 0; j < s.elements.size(); j++) {
        if (contain(s.elements[j])) {
          temp.elements.push_back(s.elements[j]);
        }
      }
    return temp;
  }
  void show();
  bool contain(int s);
  void add(int s);
};
void Set::show() {
  for (int i = 0; i < elements.size(); i++) {
    cout << elements[i] << " ";
  }
  cout << endl;
}
void Set::add(int s) { elements.push_back(s); }
bool Set::contain(int s) {
  for (int i = 0; i < elements.size(); i++) {
    if (elements[i] == s) {
      return true;
    }
  }
  return false;
}
int main() {
  Set A;
  Set B;
  A.add(1);
  A.add(2);
  B.add(2);
  B.add(4);
  Set C = A | B;
  C.show();
  Set D = A & B;
  D.show();
}