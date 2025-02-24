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
class NandGate : public BinaryGate {
public:
	NandGate(string label) : BinaryGate(label) {
	}
	virtual bool performGateLogic() {
		if (input1 == 1 && input2 == 1) {
			return false;
		} else {
			return true;
		}
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
		NotGate g1("A"), g2("B");
		NandGate g3("C"), g4("D");
		g1.setNextPin(s);
		g3.setNextPin(g1.performGateLogic());
		g2.setNextPin(r);
		g4.setNextPin(g2.performGateLogic());
		g4.setNextPin(q);
		g3.setNextPin(g4.performGateLogic());
		cout << s << r << q;
		return g3.performGateLogic();
	}
	string confirm(bool ans) {
		if (s == 1 && r == 1) {
			return "undefined";
		} else {
			return to_string(ans);
		}
	}
};
int main() {
	SRGate s1("SR", 0, 0);
	bool q1 = s1.getOutput();
	cout << " => " << s1.confirm(q1) << endl; // 0
	SRGate s2("SR", 0, 0, 1);
	bool q2 = s2.getOutput();
	cout << " => " << s2.confirm(q2) << endl; // 1
	SRGate s3("SR", 0, 1);
	bool q3 = s3.getOutput();
	cout << " => " << s3.confirm(q3) << endl; // 0
	SRGate s4("SR", 0, 1, 1);
	bool q4 = s4.getOutput();
	cout << " => " << s4.confirm(q4) << endl; // 0
	SRGate s5("SR", 1, 0);
	bool q5 = s5.getOutput();
	cout << " => " << s5.confirm(q5) << endl; // 1
	SRGate s6("SR", 1, 0, 1);
	bool q6 = s6.getOutput();
	cout << " => " << s6.confirm(q6) << endl; // 1
	SRGate s7("SR", 1, 1);
	bool q7 = s7.getOutput();
	cout << " => " << s7.confirm(q7) << endl; // undefined
	SRGate s8("SR", 1, 1, 1);
	bool q8 = s8.getOutput();
	cout << " => " << s8.confirm(q8) << endl; // undefined
}