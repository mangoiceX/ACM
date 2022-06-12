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
LL n = 0,m = 0;
struct node{
	LL v,fg;
};
node a[maxn];
bool cmp(node x,node y){
	return (x.v == y.v) ? (x.fg < y.fg) : (x.v < y.v); 
}
void solve(){
	LL ans = 0,sum = 0;
	LL L[maxn],R[maxn];
	per(i,1,n){
		sum += a[i].fg;
		if(sum > ans){
			ans = sum;
			L[sum] = a[i].v;
		}
		ans = max(ans,sum);
	}
	sum = ans = 0;
	rep(i,n,1){
		sum -= a[i].fg;
		if(sum > ans){
			ans = sum;
			R[sum] = a[i].v;
		}
		ans = max(ans,sum);
	}
	LL res = 0;
	per(i,1,ans){
		res += (R[i] - L[i]);
	}
	printf("%d %lld\n",ans,res);
}
int main(){
	LL T = 0;
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);	
		per(i,1,n){
			scanf("%lld %lld",&a[i*2-1].v,&a[i*2].v);
			a[i*2-1].fg = 1; a[i*2].fg = -1;
		}
		n *= 2;
		sort(a+1,a+1+n,cmp);
	}
	solve();
	return 0;
}