// 姓名：林育霆 學號：1101538
// 程式說明：我先依照提供的程式碼將傳入class的值放進建構子的參數中，
// 再將他們分別計算出面積和體積後，
// 令一個get_size的函式取代Shape中的get_size後輸出體積。
#include <iostream>
#include <math.h>
using namespace std;
class Shape {
protected:
	int size;

public:
	virtual void get_size() {
		cout << "Parent class area" << endl;
	}
};
class Point {
public:
	int x, y;
	Point(int a, int b) {
		x = a;
		y = b;
	}
};
class Square {
protected:
	int area1;

public:
	Square(Point A, Point B) {
		area1 = pow((A.x - B.x), 2) + pow((A.y - B.y), 2);
	}
};
class Cube : public Square, public Shape {
public:
	Cube(Point A, Point B, Point C) : Square(A, B) {
		size = area1 * sqrt((pow(A.x - C.x, 2) + pow(A.y - C.y, 2)));
	}
	void get_size() {
		cout << "Cube size: " << size << endl;
	}
};
class Circle {
protected:
	int area2;

public:
	Circle(Point A, Point B) {
		area2 = (pow(A.x - B.x, 2) + pow(A.y - B.y, 2)) * 3.14;
	}
};
class Cylinder : public Circle, public Shape {
public:
	Cylinder(Point A, Point B, Point C) : Circle(A, B) {
		size = area2 * sqrt((pow(A.x - C.x, 2) + pow(A.y - C.y, 2)));
	}
	void get_size() {
		cout << "Cylinder size: " << size << endl;
	}
};
int main() {
	Cube cube(Point(0, 0), Point(0, 5), Point(5, 0));
	Shape *s1 = &cube;
	s1->get_size();
	Cylinder cylinder(Point(0, 0), Point(0, 5), Point(5, 0));
	Shape *s2 = &cylinder;
	s2->get_size();
}