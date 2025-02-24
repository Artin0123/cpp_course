#include <iostream>
using namespace std;
int main() {
	int left,right,j;
	cin >> left >> right;
	for(int i=left;i <= right;i++){
		for(j=i;j > 0;){
			if(j%10 == 0){
				break;
			}
			if(i%(j%10) != 0){
				break;
			}
			j=j/10;
		}
		if(j == 0){
			cout << i << " ";
		}
	}
} 