// 學號：1101538 姓名：林育霆
// 文字說明：輸入一個數字，
// 當它不等於0的時候執行從1到那個數字的輸出，
// 其中是1的話由於題目的格式要求就先輸出1 * 1並跳出，
// 其他正整數則一直被1以上的數字除，若餘數為0則輸出，
// 程式中會遇到變數一直改變的問題，
// 於是我令一個變數將其保留。
#include <iostream>
using namespace std;
int main() {
	int n,temp;
	while(cin >> n){
		if(n != 0){
			for(int j=1;j <= n;j++){
			temp=j;
			cout << j << " = ";
				for(int i=1;i <= n;i++){
					if(j == 1 && i == 1){
						cout << "1 * 1";
						break;
					}
					if(j%i == 0){
						j=j/i;
						if(i == 1){
							cout << "1";
						}
						if(i > 1){
							cout << " * " << i;
						}
						i=1;
					}
				}
				j=temp;
				cout << endl;
			}
		}
	}
}