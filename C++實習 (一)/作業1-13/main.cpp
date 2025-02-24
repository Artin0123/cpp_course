// 學號：1101538 姓名：林育霆
// 文字說明：我設一個陣列照著費氏數列的規則不段累加並輸出次數，
// 再用一個迴圈輸出範圍內的數字
#include <iostream>
using namespace std;
int main() {
	int n,a[100]={},count=2,left,right;
	a[0]=1;
	a[1]=1;
	cin >> n >> left >> right;
	for(int i=0;a[i+1] < n;i++){
		a[i+2]=a[i+1]+a[i];
		count++;
	}
	cout << count << " ";
	for(int j=left;j <= right;j++){
		cout << a[j] << " ";
	}
} 