// 姓名:林育霆 學號:1101538
// 程式說明:我利用getline保留輸入的空格，
// 再利用一個陣列將其轉換並保留，
// 最後只要比較兩者即可
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string s;
	char a[100]={};
	while(getline(cin,s)){
		int i=0,t=0;
		cout << "Input: " << s << endl;
		for(i=0;i <= s.length();i++){
			a[i]=s[i];
		}
		reverse(a,a+i-1);
		for(int k=0;k <= s.length();k++){
			if(a[k] != s[k]){
				t++;
			}
		}
		if(t != 0){
			cout << "isn't Palindrome." << endl;
		}
		else{
			cout << "is Palindrome." << endl;
		}
	}
} 