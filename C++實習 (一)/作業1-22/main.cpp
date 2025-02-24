#include <iostream>
using namespace std;
bool isSelf(int n){
	int j;
		for(j=n;j > 0;){
			if(j%10 == 0){
				return false;
				break;
			}
			if(n%(j%10) != 0){
				return false;
				break;
			}
			j=j/10;
		}
	return true;
}
int main() {
	int left,right;
	cin >> left >> right;
	for(int i=left;i <= right;i++){
		if(isSelf(i)){
			cout << i << " ";
		}
	}
}