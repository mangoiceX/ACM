#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long LL;
const LL mod = 998244353;
int n = 0;
string s;
LL f(string& s){
	LL res = 0;
	for(auto x : s){
		res = (res * 100 + (x - '0') * 11) % mod;
	}
	return (res*n) % mod;
}
int main(){
	while(cin >> n){
		LL ans = 0;
		per(i,1,n){
			cin >> s;
			ans = (ans + f(s)) % mod;
		}
		cout << ans << "\n";
	}

	return 0;
}