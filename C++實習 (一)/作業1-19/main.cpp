#include <iostream>
using namespace std;
int main() {
	char a[200]={};
	char c;
	do{
		cin >> c;
		a[int(c)]++;
	}while(cin.get() != '\n');
	for(int i=0;i <= 128;i++){
		if(a[i] > 0){
			cout << char(i) << " => " << int(a[i]) << endl;
		}
	}
} 