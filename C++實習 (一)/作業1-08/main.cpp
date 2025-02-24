// 學號：1101538 姓名：林育霆
// 這個作業中，我利用for迴圈將不斷加1的a乘以b
// ，b會將上一個a*b留起來後加到總和裡
// ，可以想成1+2*1+3*(2*1)+4*(3*2*1)+...的意思
#include <iostream>
using namespace std;
int main() {
	int b=1,n,sum=0;
	cout << "請輸入一個數字：";
	cin >> n;
	for(int a=1;a<=n;a++){
		b=a*b;
		sum=sum+b;
	}
	cout << "1! + 2! + ... + n! = " << sum << endl;
}