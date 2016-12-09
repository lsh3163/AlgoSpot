#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
	int T;
	cin >> T;
	while (T--){
		string s;
		cin >> s;
		vector<char> even;
		vector<char> odd;
		for (int i = 0; i < s.length(); i++){
			if (i % 2 == 0){
				even.push_back(s[i]);
			}
			else{
				odd.push_back(s[i]);
			}
		}
		int size = even.size();
		for (int i = 0; i < size; i++){
			printf("%c", even[i]);
		}
		size = odd.size();
		for (int i = 0; i < size; i++){
			printf("%c", odd[i]);
		}
		printf("\n");
	}
}
