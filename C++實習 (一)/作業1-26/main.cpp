#include <iostream>
using namespace std;
int t = 0;
void hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        cout << "移動盤子從柱 " << A << " 到柱 " << C << endl;
        t++;
        cout << "移動盤子從柱 " << A << " 到柱 " << C << endl;
        t++;
    } else {
        hanoi(n - 1, A, C, B);
        hanoi(1, A, B, C);
        hanoi(n - 1, B, A, C);
    }
}
void hanoi2(int n, char A, char B, char C) {
    for (int i = n / 2; i > 1; i--) {
        hanoi(i - 1, A, B, C);
        cout << "移動盤子從柱 " << A << " 到柱 " << B << endl;
        t++;
        cout << "移動盤子從柱 " << A << " 到柱 " << B << endl;
        t++;
        hanoi(i - 1, C, B, A);
        cout << "移動盤子從柱 " << B << " 到柱 " << C << endl;
        t++;
    }
    cout << "移動盤子從柱 " << A << " 到柱 " << B << endl;
    t++;
    cout << "移動盤子從柱 " << A << " 到柱 " << C << endl;
    t++;
}
int main() {
    int n;
    cout << "請輸入盤數：";
    cin >> n;
    hanoi2(n, 'A', 'B', 'C');
    cout << "總共移動次數：" << t << endl;
}