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
		string s;
		cin >> s;
		int i = 0;
		while(i < s.length()){
			if (s[i] == '%' && s[i+1] == '2'){
				i++;
				if (i + 1 >= s.length()) continue;
				if (s[i + 1] == '0'){
					printf(" ");
					i++;
				}
				else if (s[i + 1] == '1'){
					printf("!");
					i++;
				}
				else if (s[i + 1] == '4'){
					printf("$");
					i++;
				}
				else if (s[i + 1] == '5'){
					printf("%%");
					i++;
				}
				else if (s[i + 1] == '8'){
					printf("(");
					i++;
				}
				else if (s[i + 1] == '9'){
					printf(")");
					i++;
				}
				else if (s[i + 1] == 'a'){
					printf("*");
					i++;
				}
				else{
					printf("%%2%c",s[i+1]);
					i++;
				}
			}
			else{
				printf("%c", s[i]);
			}
			i++;
		}
		printf("\n");
	}
}
