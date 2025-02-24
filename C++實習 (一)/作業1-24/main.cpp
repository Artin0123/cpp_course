// 姓名：林育霆 學號：1101538
// 程式說明：河內塔主要可分成3步驟:
// 1.將(n-1)盤移動到暫存柱(B柱)
// 2.把第n盤(最底下的)移到目標柱(C柱)
// 3.把(n-1)盤移到目標柱(C柱)
// 因此，最終目標是從A柱到C柱，
// 印出時要印出從A到C，
// 在遞迴中的第一項(n-1,A,C,B)就是上述的第一個步驟
// (BC交換變成從A到B)，
// 在遞迴中的第二項cout就是上述的第二個步驟
// (第一步驟執行完後最下面的盤子一定是從A到C)，
// 在遞迴中的第一項(n-1,B,A,C)就是上述的第三個步驟
// (AB交換變成從B到C)，
// 最後只要把執行時的次數加總即可。
#include <iostream>
using namespace std;
int t=0;
void hanoi(int n,char A,char B,char C){
	if(n == 1){
		cout << "移動盤子 " << n << " 從柱 " << A << " 到柱 " << C << endl;
		t++;
	}
	else{
		hanoi(n-1,A,C,B);
		cout << "移動盤子 " << n << " 從柱 " << A << " 到柱 " << C << endl;
		hanoi(n-1,B,A,C);
		t++;
	}
}
int main() {
	int n;
	cout << "請輸入盤數：";
	cin >> n;
	hanoi(n,'A','B','C');
	cout << "總共移動次數：" << t << endl;
}