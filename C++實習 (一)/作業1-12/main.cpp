// 學號：1101538 姓名：林育霆
// 文字說明：我設了一個題目要求的陣列並利用迴圈和判斷式找出當陣列中兩數相加符合輸入的數字時的數字
#include <iostream>
using namespace std;
int main() {
	int a[4]={2,7,11,15},n,i,j;
	cin >> n;
	for(i=0,j=i+1;a[i]+a[j] < n;){
		if(j == 3){
			i++;
			j=i;
		}
		j++;	
	}
	cout << i << "," << j << endl;
} 