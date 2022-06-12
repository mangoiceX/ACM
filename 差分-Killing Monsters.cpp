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
int tower[maxn];
int suf[maxn];
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		per(i,1,n){
			tower[i] = 0;
		}
		per(i,1,m){
			int l = 0,r = 0,w = 0;
			scanf("%d %d %d",&l,&r,&w);
			tower[l] += w; tower[r+1] -= w; 
		}
		per(i,1,n){
			tower[i] += tower[i-1];
		}
		rep(i,n,1){
			suf[i] = suf[i+1] + tower[i];
		}
		int k = 0,ans = 0;
		scanf("%d",&k);
		per(i,1,k){
			int h = 0,x = 0;
			scanf("%d %d",&h,&x);
			if(h > suf[x]){
				++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}