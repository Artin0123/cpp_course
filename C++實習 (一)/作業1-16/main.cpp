// 姓名:林育霆 學號:1101538
// 文字說明:我利用sort將輸入的數字從小到大輸出
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int a[10]={},n,count=0;
	while(cin >> n){
		a[count++]=n;
	}
	sort(a,a+count);
	for(int i=0;i < count;i++){
		cout << a[i] << " ";
	}
}