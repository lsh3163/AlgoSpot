#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main(void){
	int T;
	cin >> T;
	int cnt = 1;
	while (T--){
		int check;
		cin >> check;
		check--;
		string s;
		cin >> s;
		printf("%d ", cnt);
		cnt++;
		for (int i = 0; i < s.length(); i++){
			if (i == check) continue;
			printf("%c", s[i]);
		}
		printf("\n");
	}
}
