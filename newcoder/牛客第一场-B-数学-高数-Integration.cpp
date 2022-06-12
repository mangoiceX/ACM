#include<bits/stdc++.h>
// #include<iostream>
// #include<cstdio>
// #include<vector>
// #include<cstring>
using namespace std;
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
typedef long long LL;
const int maxn = 2e5 + 10;
const LL mod = (1e9 + 7);
#define INF 0x3f3f3f
typedef long long LL;
int n = 0;
LL a[maxn];
LL q_pow(LL x,LL y,LL mod){
	LL res = 1;
	while(y){
		if(y&1){
			res = res * x % mod;
		}
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}
void solve(){
	LL p2 = q_pow(2,mod-2,mod);//求2的逆元
	LL cnt[maxn];
	per(i,1,n){
		cnt[i] = 1;
		per(j,1,n){
			if(i == j){
				continue;
			}
			cnt[i] = cnt[i] * (a[j]*a[j]%mod - a[i]*a[i]%mod) % mod;
		}
		cnt[i] = q_pow(cnt[i],mod-2,mod);
		cnt[i] = cnt[i] * q_pow(a[i],mod-2,mod) % mod;
		cnt[i] = cnt[i] * p2 % mod;
	}

	LL ans = 0;
	per(i,1,n){
		ans = ((ans + cnt[i]) % mod + mod) % mod;//cnt[i]可能为负数
	}
	printf("%lld\n",ans);

}
int main(){
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%lld",&a[i]);
		}
		solve();
	}


	return 0;
}