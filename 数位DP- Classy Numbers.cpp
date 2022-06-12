#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e4 + 100;
struct Seg{
	LL r,l;
}; 
LL dp[24][5];
int d[24];
Seg seg[maxn];
LL ans[maxn];
int t = 0;
LL dfs(int pos,int sta,bool uplim){
	if(pos == 0){
		return 1;
	}
	if(!uplim && dp[pos][sta] != -1){
		return dp[pos][sta];
	}
	int up = uplim ? d[pos] : 9;
	LL temp = 0;
	for(int i = 0;i <= up;++i){
		if(i != 0 && sta + 1 > 3){
			continue;
		}
		int flag = (i != 0) ? 1 : 0;
		temp += dfs(pos-1,sta + flag,i == d[pos] && uplim);
	}
	if(!uplim){
		dp[pos][sta] = temp;
	}
	return temp;
}
void init(){
	memset(dp,-1,sizeof(dp));
}
LL solve(LL x){
	LL temp = x;
	int cnt = 0;
	while(temp > 0){
		d[++cnt] = temp % 10;
		temp /= 10;
	}
	d[cnt+1] = 0;
	return dfs(cnt,0,true);
}
int main(){
	while(scanf("%d",&t) != EOF){
		init();
		for(int i = 0;i < t;++i){	
			scanf("%I64d %I64d",&seg[i].l,&seg[i].r);
			ans[i] = solve(seg[i].r) - solve(seg[i].l - 1);
		}
		for(int i = 0;i < t;++i){
			printf("%I64d\n",ans[i]);
		}
	}
	return 0;
}
