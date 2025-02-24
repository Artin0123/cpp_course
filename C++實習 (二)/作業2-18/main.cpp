// 姓名：林育霆 學號：1101538
// 程式說明：我依題目說明在建構子中建立一個陣列，
// 接著將陣列經由第二個setValue給值並往後，
// 接著由getValue輸出，
// 底線的是運算時的參數，
// 無底線的是傳入或傳出時的參數，
// 有index的setValue會先將第index+1個的值改變並傳入值，
// 最後一樣由getValue輸出。
#include <iostream>
using namespace std;
template <typename T> class A {
	T *data;
	int _index = 0;

public:
	A(int size) {
		data = new T[size];
	}
	void setValue(int index, T value) {
		_index = index + 1;
		data[index] = value;
	}
	void setValue(T value) {
		data[_index] = value;
		_index++;
	}
	T getValue(int index) {
		return data[index];
	}
};
int main() {
	A<int> intA(3);
	intA.setValue(1);
	intA.setValue(2);
	intA.setValue(3);
	for (int i = 0; i < 3; i++) {
		cout << intA.getValue(i) << " ";
	}
	A<double> doubleA(3);
	doubleA.setValue(1);
	doubleA.setValue(2);
	doubleA.setValue(0, 999);
	doubleA.setValue(3);
	doubleA.setValue(4);
	for (int i = 0; i < 3; i++) {
		cout << doubleA.getValue(i) << " ";
	}
}