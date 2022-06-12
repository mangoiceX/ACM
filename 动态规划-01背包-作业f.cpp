#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
const int maxn = 1e3;
int dp[20][maxn+10];
int n = 0,w = 0;
int ww[maxn+10];
void solve(){
	int rest = w;
	vector<int> ans;
	rep(i,n,1){
		while(i >= 1 && dp[i][rest] == dp[i-1][rest]){
			--i;
		}
		if(i >= 1){
			ans.push_back(i);
		}
		rest -= ww[i];
	}
	per(i,0,ans.size()-1){
		printf("%d%c",ans[i],i == ans.size()-1 ? '\n' : ' ');
	}
}
int main(){
	while(~scanf("%d %d",&n,&w)){
		per(i,1,n){
			per(j,1,w){
				scanf("%d",&dp[i][j]);
			}
		}
		//假设题目中提供了第i种商品的重量
		per(i,1,n){
			scanf("%d",&ww[i]);
		} 
		solve();
	}
	
	return 0;
} 
