#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
	int T;
	cin >> T;
	int cnt = 1;
	while (T--){
		double x;
		cin >> x;
		string s;
		cin >> s;
		printf("%d ", cnt);
		cnt++;
		if (s == "kg"){
			printf("%.4lf lb\n", x*2.2046);
		}
		if (s == "lb"){
			printf("%.4lf kg\n", x*0.4536);
		}
		if (s == "l"){
			printf("%.4lf g\n", x*0.2642);
		}
		if (s == "g"){
			printf("%.4lf l\n", x*3.7854);
		}
	}
}
