#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;
//-1은 답이 아직 계산 X
//1은 해당 입력들이 서로 대응됨
//0은 입력들이 대응 x
int memo[101][101];
//W는 패턴 S는 문자열
string W, S;
//W[w..]와 S[s..]이 대응되는 지 여부 판단
bool matchMemoized(int w, int s){
	int &ret = memo[w][s];
	if (ret != -1){
		return ret;
	}
	//W[w]와 S[s]를 맞춰나간다
	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])){
		w++;
		s++;
	}
	if (w == W.size()){
		return ret = (s == S.size());
	}
	if (W[w] == '*'){
		for (int skip = 0; skip + s <= S.size(); ++skip){
			if (matchMemoized(w + 1, s + skip)){
				return ret = 1;
			}
		}
	}
	return 0;
}
vector<string> answer;
int main(){
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> W;
		cin >> N;
		answer.clear();
		while (N--){
			memset(memo, -1, sizeof(memo));
			cin >> S;
			if (matchMemoized(0, 0)){
				answer.push_back(S);
			}
		}
		sort(answer.begin(), answer.end());
		int len = answer.size();
		for (int i = 0; i < len; i++){
			cout << answer[i] << endl;
		}
	}
}
