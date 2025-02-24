#include <iostream>
#include <math.h>
using namespace std;
class twoDPoint {
	double x1, y1;

public:
	twoDPoint(double getx, double gety) {
		x1 = getx;
		y1 = gety;
	}
	double operator-(twoDPoint num) {
		return sqrt(pow(x1 - num.x1, 2) + pow(y1 - num.y1, 2));
	}
};
class threeDPoint {
	double x2, y2, z2;

public:
	threeDPoint(double getx, double gety, double getz) {
		x2 = getx;
		y2 = gety;
		z2 = getz;
	}
	double operator-(threeDPoint num) {
		return sqrt(
			pow(x2 - num.x2, 2) + pow(y2 - num.y2, 2) + pow(z2 - num.z2, 2));
	}
};
int main() {
	twoDPoint p1(5, 0), p2(0, 12);
	cout << p1 - p2 << endl;
	threeDPoint p3(1, 1, 1), p4(2, 3, 4);
	cout << p3 - p4 << endl;
}