#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int T;
int N;
int memo[101];
int cache[101];
const int mod = 1000000007;
int tiling(int width){
	if (width <= 1){
		return 1;
	}
	int &ret = cache[width];
	if (ret != -1){
		return ret;
	}
	return ret = (tiling(width - 1) + tiling(width - 2)) % mod;
}
int solve(int width){
	if (width <= 2){
		return 0;
	}
	int &ret = memo[width];
	if (ret != -1){
		return ret;
	}
	ret = solve(width - 2) % mod;
	ret = (ret + solve(width - 4)) % mod;
	ret = (ret + tiling(width - 3)) % mod;
	ret = (ret + tiling(width - 3)) % mod;
	return ret;
}
int main(){
	cin >> T;
	while (T--){
		cin >> N;
		memset(memo, -1, sizeof(memo));
		memset(cache, -1, sizeof(cache));
		printf("%d\n", solve(N));
	}
}
