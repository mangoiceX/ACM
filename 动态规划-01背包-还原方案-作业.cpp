#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3; 
int n = 0,w = 0;
struct node{
	int w,v;
}; 
node a[maxn+10];
int dp[20][maxn+10];
void solve(){
	for(int i = 0;i <= n;++i){
		dp[i][0] = 0;
	}
	for(int i = 0;i <= w;++i){
		dp[0][i] = 0;
	}
	for(int i = 1;i <= n;++i){
		for(int j = 0;j <= w;++j){
			dp[i][j] = (j >= a[i].w) ? max(dp[i-1][j],dp[i-1][j-a[i].w] + a[i].v) : dp[i-1][j];
		}
	}
	printf("%d\n",dp[n][w]);
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= w;++j){
			printf("%d%c",dp[i][j],j == w ? '\n' : ' ');
		}
	}
	int rest = w;
	map<int,int> mp;
	for(int i = n;i >= 1;--i){
		while(i-1 >= 0 && dp[i-1][rest] == dp[i][rest]){
			--i;
		}
		++mp[i];
		rest -= a[i].w;
		if(rest == 0){
			break;
		} 
	}
	map<int,int>::iterator it = mp.begin();
	for(it = mp.begin();it != mp.end();++it){
		printf("You should choose %d peices of the %dth item!\n",it->second,it->first);
	}
}
int main(){
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	while(~scanf("%d",&n)){
		memset(dp,0,sizeof(dp));
		for(int i = 1;i <= n;++i){
			scanf("%d %d",&a[i].w,&a[i].v);
		}
		scanf("%d",&w);
		solve();
	}
	
	return 0;
}
