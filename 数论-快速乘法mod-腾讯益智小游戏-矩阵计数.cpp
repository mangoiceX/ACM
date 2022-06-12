#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f
const LL mod = 998244353;
const int maxn = 1e5;
LL n = 0,m = 0;
LL q_mul(LL a,LL b){
	LL res = 0;
	while(b > 0){
		if(b & 1){
			res = (res + a) % mod;
		}
		a = (a + a);
		b >>= 1;
	}
	return res;
}

LL inv(LL x){
	LL b = mod - 2,ans = 1;
	while(b){
		if(b&1){
			ans = ans * x % mod;
		}
		b >>= 1;
	}
	return ans;
}
LL fac(LL x){
	LL ans = 1;
	for(LL i = 2;i <= x;++i){
		ans = q_mul(ans,i);
	}
	return ans;
}
int main(){
	while(~scanf("%lld %lld",&n,&m)){
		if(n == 1 && m == 1){
			printf("1\n");
			continue;
		}
		LL a = fac(n*m);
		LL b = (q_mul(m,m-1) + q_mul(n,n-1)) % mod;
		//LL ans = q_mul(a,inv(b)) % mod;
		///cout << a << endl;
		//cout << b <<endl;
		//cout << inv(b) << endl;
		printf("%lld\n",a/b);
	}
}