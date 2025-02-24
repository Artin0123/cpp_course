#include <iostream>
using namespace std;
class LogicGate {
protected:
	string label;
	bool output, temp = 1;

public:
	LogicGate(string n) {
		label = n;
	}
	bool getOutput() {
		output = performGateLogic();
		return output;
	}
	virtual bool performGateLogic() = 0;
	virtual void setNextPin(bool source) = 0;
};
class BinaryGate : public LogicGate {
protected:
	bool input1, input2;

public:
	BinaryGate(string label) : LogicGate(label) {
	}
	virtual void setNextPin(bool source) {
		if (temp == 1) {
			input1 = source;
			temp = 0;
		} else {
			input2 = source;
		}
	}
};
class AndGate : public BinaryGate {
public:
	AndGate(string label) : BinaryGate(label) {
	}
	virtual bool performGateLogic() {
		if (input1 == 1 && input2 == 1) {
			return true;
		} else {
			return false;
		}
	}
};
class OrGate : public BinaryGate {
public:
	OrGate(string label) : BinaryGate(label) {
	}
	virtual bool performGateLogic() {
		if (input1 == 1 || input2 == 1) {
			return true;
		} else {
			return false;
		}
	}
};
class UnaryGate : public LogicGate {
protected:
	bool input;

public:
	UnaryGate(string label) : LogicGate(label) {
	}
	virtual void setNextPin(bool source) {
		input = source;
	}
};
class NotGate : public UnaryGate {
public:
	NotGate(string label) : UnaryGate(label) {
	}
	virtual bool performGateLogic() {
		return !input;
	}
};
class Connector {
	LogicGate *fromgate, *togate;

public:
	Connector(LogicGate *fgate, LogicGate *tgate) {
		fromgate = fgate;
		togate = tgate;
		tgate->setNextPin(fromgate->getOutput());
	}
};
int main() {
	AndGate g1("A");
	OrGate g2("B");
	OrGate g3("C");
	NotGate g4("D");
	g1.setNextPin(1);
	g1.setNextPin(0);
	g2.setNextPin(0);
	g2.setNextPin(0);
	Connector c1(&g1, &g3);
	Connector c2(&g2, &g3);
	Connector c3(&g3, &g4);
	cout << "Output: " << g4.getOutput() << endl;
	return 0;
}