#include<bits/stdc++.h>
// #include<iostream>
// #include<cstdio>
// #include<vector>
// #include<cstring>
using namespace std;
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
const int maxn = 2e5 + 10;
typedef long long LL;
int n = 0,m = 0;
int a[maxn];
int pre_pos[maxn],suf[maxn];
void solve(int x,int p){
	pre_pos[p] = p;
	for(int i = 1;i * i <= x;++i){
		if(x % i == 0){
			pre_pos[i] = p;
		}
	}
}
void solve2(int x,int p){
	suf[p] = p;
	for(int i = 1;i * i <= x;++i){
		if(x % i == 0){
			suf[i] = p;
		}
	}
}
LL q_mul(int x,int y){
	LL res = 0;
	while(y > 0){
		if(y & 1){
			res += x;
		}
		x = x + x;
		y >>= 1;
	}
	return res;
}
int main(){
	while(~scanf("%d",&n)){
		memset(pre_pos,0,sizeof(pre_pos)); memset(suf,0,sizeof(suf));
		per(i,1,n){
			scanf("%d",&a[i]);
			solve(a[i],i);
		}
		rep(i,n,1){
			solve2(a[i],i);
		}
		LL sum = 0;
		per(i,1,n){
			sum += (q_mul(a[pre_pos[i]],a[suf[i]]));
		}
		printf("%lld\n",sum);
	}

	return 0;
}