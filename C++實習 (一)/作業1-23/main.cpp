//學號:1101538 姓名:林育霆
//程式說明:我依照範例先建立一個function計算每個村子賣出的鴨子數，
//由於題目的數目要由大到小輸出，
//因此我令了if，
//當數目到達N之前會一直相乘直到i=N，
//最後令一個sum把每次的數目加總。
#include <iostream>
using namespace std;
int duck(int i,int N) {
	int count;
	if (i == N) {
		count = 2;
	}
	else {
		count = (duck(i + 1, N)) * 2;
	}
	return count;
}
int main() {
	int N, sum=0;
	while (cin >> N) {
		for (int i = 1; i <= N; i++) {
			cout << "經過第 " << i << " 個村子時，賣出 " << duck(i, N) << " 隻鴨子\n";
			sum = sum + duck(i, N);
		}
		cout << "總共賣出了 " << sum << " 隻鴨子\n";
		sum = 0;
	}
}