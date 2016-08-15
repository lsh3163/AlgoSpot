#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int T;
int N;
int memo[501];
int Sequence[501];
int solve(int idx){
	if (idx > N){
		return 0;
	}
	int &ret = memo[idx];
	if (ret != -1){
		return ret;
	}
	ret = 1;
	for (int i = idx + 1; i <= N; i++){
		if (Sequence[idx] < Sequence[i]){
			ret = max(ret, solve(i) + 1);
		}
	}
	return ret;
}
int main(){
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 1; i <= N; i++){
			cin >> Sequence[i];
		}
		memset(memo, -1, sizeof(memo));
		int answer = 0;
		for (int i = 1; i <= N; i++){
			answer = max(answer, solve(i));
		}
		printf("%d\n", answer);
	}
}
