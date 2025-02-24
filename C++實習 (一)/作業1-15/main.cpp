#include <iostream>
using namespace std;
int main() {
	char a[200];
	int n=0,t=0,count,q;
	do{
		cin >> a[n++];
	}while(cin.get() != '\n');
	for(int i=0;i < n;i++){
		q=0;
		count=0;
		for(int k=0;k < t;k++){
			if(a[i] == a[k]){
				q++;
			}
		}
		if(q != 0){
			continue;
		}
		for(int j=0;j < n;j++){
			if(a[i] == a[j]){
				count++;
			}
		}
		cout << a[i] << " => " << count << endl;
		t++;
	}
} 