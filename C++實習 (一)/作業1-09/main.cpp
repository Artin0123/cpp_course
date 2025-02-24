#include <iostream>
using namespace std;
int main() {
	int a;
	cin >> a;
	for(int i=0;i <= a;i=i+2){
		for(int j=a;j >= 0;j=j-2){
			if(i+1 < j){
				cout << " ";
			}
		}
		for(int k=a;k >= 0;k--){
			if(i >= k){
				cout << "*";
			}
		}
		cout << endl;	
	}
	for(int i=0;i <= a-2;i=i+2){
		for(int j=0;j <= i;j=j+2){
			if(j <= i){
				cout << " ";
			}
		}
		for(int k=a;k >= 0;k--){
			if(k-2 > i){
				cout << "*";
			}
		}
		cout << endl;	
	}
}