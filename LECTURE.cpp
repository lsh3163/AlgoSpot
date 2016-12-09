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
		vector<string> v;
		for (int i = 0; i < s.length(); i += 2){
			string ss="";
			ss += s[i];
			ss += s[i + 1];
			v.push_back(ss);
		}
		sort(v.begin(), v.end());
		int size = v.size();
		for (int i = 0; i < size; i++){
			cout << v[i];
		}
		cout << endl;
	}
}
