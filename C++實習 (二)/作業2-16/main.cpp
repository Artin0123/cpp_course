// 姓名：林育霆 學號：1101538
// 程式說明：我依照題目的要求先將人員類型用動態陣列存取並分類，
// 之後輸入姓名和年紀，
// 如果是學生則多輸入mark並加總，
// 最後將資料輸出。
#include <iostream>
#include <string>
using namespace std;
class Person {
	string name;
	int age;

public:
	Person() {
		name = "";
		age = 0;
	}
	virtual void getdata() {
		cout << name << " " << age << " ";
	};
	virtual void putdata() {
		cin >> name;
		cin >> age;
	};
};

class Professor : public Person {
	int publications;

public:
	Professor() {
		publications = 0;
	};
	void putdata() {
		Person::putdata();
		cin >> publications;
	};
	void getdata() {
		Person::getdata();
		cout << publications << " 1 " << endl;
	};
};

class Student : public Person {
	int mark[6];

public:
	Student() {
		for (int i = 0; i < 6; i++) {
			mark[i] = 0;
		}
	};
	void putdata() {
		Person::putdata();
		for (int i = 0; i < 6; i++) {
			cin >> mark[i];
		}
	};
	void getdata() {
		Person::getdata();
		int ans = 0;
		for (int i = 0; i < 6; i++) {
			ans += mark[i];
		}
		cout << ans << " 2 " << endl;
	};
};

int main() {
	int n, type;
	cout << " ===== Input =====" << endl;
	cin >> n;
	Person **per = new Person *[n];
	for (int i = 0; i < n; i++) {
		cin >> type;
		if (type == 1) {
			per[i] = new Professor;
		} else {
			per[i] = new Student;
		}
		per[i]->putdata();
	}
	cout << " ===== Output =====" << endl;
	for (int i = 0; i < n; i++) {
		per[i]->getdata();
	}
	return 0;
}
