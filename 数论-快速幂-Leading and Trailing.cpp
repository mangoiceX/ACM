#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 1000;
LL n = 0,k = 0;
int mod_pow(LL x,LL n){
	LL res = 1;
	while(n > 0){
		if(n & 1){
			res = res * x % mod;
		}
		x = x * x % mod;
		n >>= 1;
	}
	return (int)res;
}

int main(){
	int T = 0,kase = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%lld %lld",&n,&k);
		int res2 = mod_pow(n,k);	
		double x = 0;
		double y = modf((double)(k*log10(n)),&x);
		int res1 = floor(pow(10,y) * 100);
		printf("Case %d: %d %03d\n",++kase,res1,res2);
	}
	
	
	return 0;
} 
