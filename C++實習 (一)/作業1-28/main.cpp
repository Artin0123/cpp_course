#include <iostream>
using namespace std;
int *sortasc(int *p, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (*(p + i) > *(p + j)) {
				int temp;
				temp = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = temp;
			}
		}
	}
	return p;
}
int main() {
	int n;
	while (cin >> n) {
		int *arr;
		arr = new int[20];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int *p = sortasc(arr, n);
		cout << "sorted: " << endl;
		for (int j = 0; j < n; j++) {
			cout << *(p + j);
		}
		cout << endl;
		delete[] arr;
	}
}