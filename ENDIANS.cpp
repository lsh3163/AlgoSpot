#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
long long n;
int main(void){
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		vector<long long> v;
		while (n > 0){
			v.push_back(n % 16);
			n /= 16;
		}
		while (v.size() != 8){
			v.push_back(0);
		}
		vector<long long> res;
		int size = v.size();
		int idx = 0;
		while (idx < size){
			if (idx % 2 == 0)
			{
				res.push_back(v[idx + 1]);
				res.push_back(v[idx]);
				idx += 2;
			}
		}
		reverse(res.begin(), res.end());
		long long sum = 0;
		int cnt = 1;
		for (int i = 0; i < 8; i++){
			sum += (cnt*res[i]);
			cnt *= 16;
		}
		printf("%lld\n", sum);
	}
}
