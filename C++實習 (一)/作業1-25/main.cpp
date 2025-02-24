// 姓名：林育霆 學號：1101538
// 程式說明：我先照題目要求將字串的長度用l到r表示，
// 再利用swap交換字元，
// 我先固定最後一個字元為r，
// 接著往前將前面的字元交換排序，
// 再從r-1個字元開始到第一個字元，
// 將前面的字元交換排序。
#include <iostream>
using namespace std;
void permute(string a,int l,int r){
	if(l == r){
		cout << a << endl;
	}
	else{
		for(int i=l;i <= r;i++){
			permute(a,l,r-1);
			swap(a[i],a[r]);
		}
	}
}
int main() {
	string str;
	while(cin >> str){
		int n=str.size();
		permute(str,0,n-1);
		cout << "=====" << endl;
	}
}