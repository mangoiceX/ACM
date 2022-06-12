#include<bits/stdc++.h>
using namespace std;
int d[20];
int dp[20][3][13];
int n = 0;
int dfs(int pos,int pre,int sta,int sum,bool lim){
	if(pos == 0){
		return (sum == 0 && sta == 2) ? 1 : 0;
	}
	if(!lim && dp[pos][sta][sum] != -1){
		return dp[pos][sta][sum];
	}
	int up = lim ? d[pos] : 9;
	int tmp = 0;
	for(int i = 0;i <= up;++i){
		int flag = sta;
		/*
		if(sta == 1 || (pre == 1 && i == 3)){
			flag = 1;
		}
		*/
		if(sta == 0 && i == 1){
			flag = 1;
		}
		if(sta == 1 && i != 1){
			flag = 0;
		}
		if(sta == 1 && i == 3){
			flag = 2;
		}
		tmp += dfs(pos-1,i,flag,(sum*10+i) % 13, lim && i == d[pos]);
	}
	if(!lim){
		dp[pos][sta][sum] = tmp;
	}
	return tmp;
}
int solve(int x){
	fill(dp[0][0],dp[0][0]+20*3*13,-1);
	int tmp = x;
	int cnt = 0;
	while(tmp > 0){
		d[++cnt] = tmp % 10;
		tmp /= 10;
	}
	d[cnt+1] = 0;
	return dfs(cnt,-1,0,0,true);
}
int main(){
	while(~scanf("%d",&n)){
		printf("%d\n",solve(n));
	}
	
	return 0;
} 
