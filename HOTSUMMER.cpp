#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
	int T;
	cin >> T;
	while (T--){
		int sum = 0;
		int tar;
		cin >> tar;
		for (int i = 0; i < 9; i++){
			int x;
			cin >> x;
			sum += x;
		}
		if (sum <= tar){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}
