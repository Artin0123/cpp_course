#include <iostream>
#include <vector>
using namespace std;
template <class T> class Stack {
	vector<T> elems;
	int topIndex = 0;

public:
	void push(T);
	T pop();
	T top();
};
template <class T> void Stack<T>::push(T elem) {
	elems.push_back(elem);
	topIndex++;
}
template <class T> T Stack<T>::pop() {
	T value = elems[--topIndex];
	elems.pop_back();
	return value;
}
template <class T> T Stack<T>::top() {
	return elems.back();
}
int main() {
	Stack<int> intStack;
	intStack.push(1);
	intStack.push(2);
	intStack.push(3);
	cout << intStack.pop() << endl;
	cout << intStack.top() << endl;
	Stack<string> stringStack;
	stringStack.push("hello");
	stringStack.push("world");
	cout << stringStack.top() << endl;
}