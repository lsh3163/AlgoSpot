#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<climits>
#include<string>
using namespace std;
int T;
const int INF = 987654321;
string N;
int memo[10002];
int classify(int a, int b){
	string M = N.substr(a, b - a + 1);
	if (M == string(M.size(), M[0])){
		return 1;
	}
	bool progressive = true;
	for (int i = 0; i < M.size() - 1; i++){
		if (M[i + 1] - M[i] != M[1] - M[0]){
			progressive = false;
		}
	}
	if (progressive && abs(M[1] - M[0]) == 1){
		return 2;
	}
	bool alternating = true;
	for (int i = 0; i < M.size(); i++){
		if (M[i] != M[i % 2]){
			alternating = false;
		}
	}
	if (alternating){
		return 4;
	}
	if (progressive){
		return 5;
	}
	return 10;
}
int memorize(int begin){
	if (begin == N.size()){
		return 0;
	}
	int &ret = memo[begin];
	if (ret != -1){
		return ret;
	}
	ret = INF;
	for (int i = 3; i <= 5; i++){
		if (begin + i <= N.size()){
			ret = min(ret, memorize(begin + i) + classify(begin, begin + i - 1));
		}
	}
	return ret;
}
int main(){
	cin >> T;
	while (T--){
		cin >> N;
		memset(memo, -1, sizeof(memo));
		printf("%d\n", memorize(0));
	}
}
