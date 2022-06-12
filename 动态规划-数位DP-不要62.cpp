#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n = 0,m = 0;
int dp[25][2];
int d[30];
int dfs(int pos,int pre,bool sta,bool lim){
	if(pos == 0){
		return 1;
	}
	if(!lim && dp[pos][sta] != -1){
		return dp[pos][sta];
	}
	int up = lim ? d[pos] : 9;
	int temp = 0;
	for(int i = 0;i <= up;++i){
		if(i == 4 || (pre == 6 && i == 2)){
			continue;
		}
		temp += dfs(pos-1,i,i == 6,lim && i == d[pos]);
	}
	if(!lim){
		dp[pos][sta] = temp;
	}
	return temp;
}
int solve(int x){
	int temp = x;
	int cnt = 0;
	while(temp > 0){
		d[++cnt] = temp % 10;
		temp /= 10;
	}
	d[cnt+1] = 0;
	return dfs(cnt,-1,0,true);
}
int main(){
	while(~scanf("%d %d",&n,&m) && n && m){
		fill(dp[0],dp[0]+25*2,-1);
		printf("%d\n",solve(m) - solve(n-1));
	}
	return 0;
}
