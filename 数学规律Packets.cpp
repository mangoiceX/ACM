#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 100;
int n = 0;
int main(){
	while(cin >> n){
		//cout << log(2,n) + 1 << endl;
		int cnt = 0;
		while(n > 0){
			n /= 2;
			++cnt;
		}
		cout << cnt << endl;
	}
	return 0;
} 
