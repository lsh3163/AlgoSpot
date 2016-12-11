#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
double board[9][9];
int main(void){
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		vector<int> v;
		for (int i = 1; i <= n; i++){
			v.push_back(i);
			for (int j = 1; j <= n; j++){
				cin >> board[i][j];
			}
		}
		double ans = 20000;
		do{
			bool check = false;
			double ret = 0;
			for (int i = 1; i < n; i++){
				if (board[v[i - 1]][v[i]] == 0){
					check = true;
				}
				ret += board[v[i - 1]][v[i]];

			}
			if (!check) ans = min(ans, ret);
		} while (next_permutation(v.begin(), v.end()));
		printf("%.10lf\n", ans);
	}
}
