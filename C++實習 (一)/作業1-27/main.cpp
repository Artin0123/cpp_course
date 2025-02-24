#include <iostream>
#include <cstring>
using namespace std;
void reversestring(char* str) {
	char * begin_ptr = str; // str 第一個位址
	char * end_ptr = str+strlen(str)-1; // str 最後一個位址
	for(int i=0;i < strlen(str)/2;i++){
	char tmp = *begin_ptr;
	*begin_ptr = *end_ptr;
	*end_ptr = tmp;
	begin_ptr++;
	end_ptr--;
	}
} 
int main() {
	char str[100];
	cin.getline(str,100);
	cout << "Input:" << str << endl;
	reversestring(str);
	cout << "Output:" << str << endl;
} 