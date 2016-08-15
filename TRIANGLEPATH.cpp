#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;
int board[101][101];
int memo[101][101];
int N;
int solve(int x, int y){
	if (x > N){
		return 0;
	}
	int &ret = memo[x][y];
	if (ret != -1){
		return ret;
	}
	ret = max(solve(x + 1, y), solve(x + 1, y + 1)) + board[x][y];
	return ret;
}
int main(){
	int T;
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= i; j++){
				cin >> board[i][j];
			}
		}
		memset(memo, -1, sizeof(memo));
		printf("%d\n", solve(1, 1));
	}
}
