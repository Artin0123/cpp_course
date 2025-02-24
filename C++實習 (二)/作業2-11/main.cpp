// 姓名：林育霆 學號：1101538
// 程式說明：我先將輸入的三種情況做分類，
// 當它是and或or的時候會回到logigate傳入binary做輸入，
// 之後回到and或or用if判斷，
// 當它是not的時候會回到logigate傳入unary做輸入，
// 之後回到not否定他。
#include <iostream>
using namespace std;
class LogiGate {
protected:
	string label;
	bool output;

public:
	LogiGate(string n) {
		label = n;
	}
	void getOutput() {
		cout << "Output: " << output << endl;
	}
};
class BinaryGate : public LogiGate {
protected:
	bool input1, input2;

public:
	BinaryGate(string label) : LogiGate(label) {
		cout << "Enter Pin input for gate " << label << " -->";
		cin >> input1;
		cout << "Enter Pin input for gate " << label << " -->";
		cin >> input2;
	}
};
class AndGate : public BinaryGate {
public:
	AndGate(string label) : BinaryGate(label) {
		if (input1 == input2 && input1 == true) {
			output = true;
		} else {
			output = false;
		}
	}
};
class OrGate : public BinaryGate {
public:
	OrGate(string label) : BinaryGate(label) {
		if (input1 == input2 && input1 == false) {
			output = false;
		} else {
			output = true;
		}
	}
};
class UnaryGate : public LogiGate {
protected:
	bool input;

public:
	UnaryGate(string label) : LogiGate(label) {
		cout << "Enter Pin input for gate " << label << " -->";
		cin >> input;
	}
};
class NotGate : public UnaryGate {
public:
	NotGate(string label) : UnaryGate(label) {
		output = !input;
	}
};
int main() {
	string g;
	while (cin >> g) {
		if (g == "and") {
			AndGate g1(g);
			g1.getOutput();
		}
		if (g == "or") {
			OrGate g2(g);
			g2.getOutput();
		}
		if (g == "not") {
			NotGate g3(g);
			g3.getOutput();
		}
	}
}