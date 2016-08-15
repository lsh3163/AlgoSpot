#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
using namespace std;
int T;
int memo[101];
int N;
const int mod = 1000000007;
int tiling(int width){
	if (width <= 1){
		return 1;
	}
	int &ret = memo[width];
	if (ret != -1){
		return ret;
	}
	ret = tiling(width - 2) + tiling(width - 1);
	ret %= mod;
	return ret;
}
int main(){
	cin >> T;
	while (T--){
		cin >> N;
		memset(memo, -1, sizeof(memo));
		int answer = tiling(N);
		printf("%d\n", answer);
	}
}
