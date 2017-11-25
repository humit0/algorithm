#include <iostream>
#include <string>
using namespace std;

int main() {
	// using DFA
	int arr[2][10] = {{8, 8, 3, 4, 4, 8, 7, 4, 9, 9},{2, 2, 9, 9, 5, 6, 6, 1, 1, 9}};
	int N, len, STATE=0;
	const char *c_str;
	string str;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> str;
		len = str.length();
		STATE = 0;
		c_str = str.c_str();
		for(int i=0; i<len; i++){
			STATE = arr[c_str[i]-'0'][STATE];
			if(STATE==9){
				break;
			}
		}
		if(STATE==1||STATE==5||STATE==6)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}