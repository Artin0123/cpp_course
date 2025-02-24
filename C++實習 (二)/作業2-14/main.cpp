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
	virtual void setNextPin(bool source){};
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
class NorGate : public BinaryGate {
public:
	NorGate(string label) : BinaryGate(label) {
	}
	virtual bool performGateLogic() {
		if (input1 != 1 && input2 != 1) {
			return true;
		} else {
			return false;
		}
	}
};
class SRGate : public LogicGate {
	bool s, r, q;

public:
	SRGate(string label, bool S, bool R) : LogicGate(label) {
		s = S;
		r = R;
		q = 0;
	}
	SRGate(string label, bool S, bool R, bool Q) : LogicGate(label) {
		s = S;
		r = R;
		q = Q;
	}
	virtual bool performGateLogic() {
		NorGate g1("A"), g2("B");
		g1.setNextPin(s);
		g1.setNextPin(q);
		g2.setNextPin(r);
		g2.setNextPin(g1.performGateLogic());
		cout << s << r << q;
		return g2.performGateLogic();
	}
};
int main() {
	SRGate s1("SR", 0, 0);
	bool q1 = s1.getOutput();
	cout << " => " << q1 << endl; // 0
	SRGate s2("SR", 0, 0, q1);
	bool q2 = s2.getOutput();
	cout << " => " << q2 << endl; // 0
	SRGate s3("SR", 1, 0, q2);
	bool q3 = s3.getOutput();
	cout << " => " << q3 << endl; // 1
	SRGate s4("SR", 0, 1, q3);
	bool q4 = s4.getOutput();
	cout << " => " << q4 << endl; // 0
}