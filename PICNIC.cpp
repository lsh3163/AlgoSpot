#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;
int n;
bool areFriends[10][10];
int countPairings(bool taken[10]){
	int firstFree = -1;
	//선택 받지 않은 가장 빠른 i 를 고름
	for (int i = 0; i < n; i++){
		if (!taken[i]){
			firstFree = i;
			break;
		}
	}
	//다 선택받았다는 뜻이므로 return 1
	if (firstFree == -1){
		return 1;
	}
	int ret = 0;
	for (int pairwith = firstFree + 1; pairwith < n; pairwith++){
		//다음 만드려는 친구가 골라진 적 없고 간선이 존재할 때
		if (!taken[pairwith] && areFriends[firstFree][pairwith]){
			taken[pairwith] = taken[firstFree] = true;
			ret += countPairings(taken);
			taken[pairwith] = taken[firstFree] = false;
		}
	}
	return ret;
}
int main(){
	int T;
	cin >> T;
	while (T--){
		cin >> n;
		int m;
		cin >> m;
		while (m--){
			int u, v;
			cin >> u; cin >> v;
			areFriends[u][v] = areFriends[v][u] = true;
		}
		bool taken[10];
		memset(taken, false, sizeof(taken));
		int answer = countPairings(taken);
		printf("%d\n", answer);
		memset(areFriends, 0, sizeof(areFriends));
	}
}
