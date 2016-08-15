#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<climits>
using namespace std;
const long long NEGINF = numeric_limits<long long>::min();
int TestCase;
int N, M;
int A[101];
int B[101];
int memo[101][101];
int solve(int indexA, int indexB){
	int &ret = memo[indexA + 1][indexB + 1];
	if (ret != -1){
		return ret;
	}
	ret = 2;
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]);
	long long maxElement = max(a, b);
	for (int i = indexA + 1; i < N; i++){
		if (maxElement < A[i]){
			ret = max(ret, solve(i, indexB) + 1);
		}
	}
	for (int i = indexB + 1; i < M; i++){
		if (maxElement < B[i]){
			ret = max(ret, solve(indexA, i) + 1);
		}
	}
	return ret;
}
int main(){
	cin >> TestCase;
	while (TestCase--){
		cin >> N; cin >> M;
		for (int i = 0; i < N; i++){
			cin >> A[i];
		}
		for (int j = 0; j < M; j++){
			cin >> B[j];
		}
		memset(memo, -1, sizeof(memo));
		int answer = solve(-1, -1);
		printf("%d\n", answer - 2);
	}
}
