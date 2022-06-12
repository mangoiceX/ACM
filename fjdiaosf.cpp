#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
LL n = 0,m = 0,k = 0;
const LL mod = 998244353;
LL f[100];
LL cal(LL x){
	LL res = (n+1)/2;
	per(i,2,n-1){
		res = res * i * i % mod; 
	}
	return res;
}
LL q_power(LL x,LL y,LL mod){
	LL res = 1;
	while(y > 0){
		if(y  & 1){
			res = (res * x)  % mod;
		}
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}

int main(){
	while(~scanf("%lld",&n)){

		LL b = q_power(9,mod-2,mod) % mod;
		LL a = n*n-1;
		printf("%lld\n",a*b%mod);
	}

	return 0;
}