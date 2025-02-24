// 姓名:林育霆 學號:1101538
// 程式說明:我利用一個陣列將輸入的字母存到ascii碼中
// ，再將它的次數加一
#include <iostream>
using namespace std;
int main() {
	char i,c,s[10]={};
	int n=0;
	int d[200]={};
	cout << " ===== Build ===== \n";
	while(cin >> c){
		if(c == 24){
			break;
		}
		s[n]=c;
		d[int(c)]=n;
		n++;
	}
	cout << " ===== Search ===== \n";
	while(cin >> i){
		cout << "index = " << d[int(i)] << endl;
	}
} 