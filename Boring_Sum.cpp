// #include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
const int maxn = 1e5 + 10;
typedef long long LL;
int n = 0,m = 0;
int a[maxn],b[maxn],c[maxn];
int pre_pos[maxn],suf[maxn];
void solve(LL x,int p){
	// pre_pos[x] = p;
	for(int i = 1;i * i <= x;++i){
		if(x % i == 0){
			pre_pos[i] = p; pre_pos[x/i] = p;
		}
	}
}
void solve2(LL x,int p){
	// suf[x] = p;
	for(int i = 1;i * i <= x;++i){
		if(x % i == 0){
			suf[i] = p; suf[x/i] = p;
		}
	}
}
// LL q_mul(int x,int y){
// 	LL res = 0;
// 	while(y > 0){
// 		if(y & 1){
// 			res += x;
// 		}
// 		x = x + x;
// 		y >>= 1;
// 	}
// 	return res;
// }
void init(){
	per(i,1,n){
		pre_pos[a[i]] = i;
		suf[a[i]] = i;
	}
}
int main(){
	while(~scanf("%d",&n) && n){
		// memset(pre_pos,0,sizeof(pre_pos)); memset(suf,0,sizeof(suf));
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		init();
		per(i,1,n){
			b[i] = a[pre_pos[a[i]]];
			solve(a[i],i);
		}
		rep(i,n,1){
			c[i] = a[suf[a[i]]];
			solve2(a[i],i);
		}
		// per(i,1,n){
		// 	printf("%d %d\n",b[i],c[i]);
		// }
		LL sum = 0;
		per(i,1,n){
			// sum += (q_mul(b[i],c[i]));
			sum += (1ll*b[i]*c[i]);
		}
		printf("%lld\n",sum);
	}

	return 0;
}