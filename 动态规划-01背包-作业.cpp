#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3; 
int n = 0,w = 0;
int dp[20][maxn+10];
void solve(){
	per(i,1,nd) 
	
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
	while(~scanf("%d %d",&n,&w)){
		for(int i = 0;i <= n;++i){
			for(int j = 0;j <= w;++j){
			scanf("%d",&dp[i][j]);
		}
		solve();
	}
	
	return 0;
}
