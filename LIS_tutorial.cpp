#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int n;
int num[501];
int memo[501];
int solve(int idx){
	if (idx == n){
		return 0;
	}
	int &ret = memo[idx];
	if (ret != -1){
		return ret;
	}
	ret = 1;
	for (int i = idx + 1; i < n; i++){
		if (num[idx] < num[i]){
			ret = max(ret, solve(i) + 1);
		}
	}
	return ret;
}
int main(void){
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> num[i];
		}
		memset(memo, -1, sizeof(memo));
		int ans = 0;
		for (int i = 0; i < n; i++){
			ans = max(ans, solve(i));
		}
		printf("%d\n", ans);
	}
}
