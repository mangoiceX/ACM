#include<bits/stdc++.h>
using namespace std;
int dp[11][82][10000];//i-pos,j-sum,k-num,l-mod
//前pos位，当前数字和为sum，数值为num ,最终数字和为mod 
//由这4个状态变量确定唯一一个状态，状态的选择要无后效性 
//可以有这3个状态变量确定唯一一个状态，但是由于num的范围太大所以需要确定另外的状态 
int d[11];
int m = 0,n = 0;
int dfs(int pos,int sum,int num,bool lim){
	if(pos == 0){
		if(sum == 0){
			return 0;
		}
		return num % sum == 0 ;//
	}
	if(!lim && dp[pos][sum][num] != -1){
		return dp[pos][sum][num];
	}
	int up = lim ? d[pos] : 9;
	int tmp = 0;
	for(int i = 0;i <= up;++i){
		tmp += dfs(pos-1,sum + i,(num*10 + i),lim && i == d[pos]);
	}
	if(!lim){
		dp[pos][sum][num] = tmp;
	}
	return tmp;
}
int solve(int x){
	if(x == 0){
		return 0;
	}
	fill(dp[0][0],dp[0][0]+11*82*10000,-1);
	int tmp = x;
	int cnt = 0;
	while(tmp > 0){
		d[++cnt] = tmp % 10;
		tmp /= 10;
	}
	d[cnt+1] = 0;
	int ans = 0;
	//for(int i = 1;i <= 81;++i){
		ans += dfs(cnt,0,0,true);
	//} 
	return ans;
}
int main(){
	int T = 0,kase = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		printf("Case %d: %d\n",++kase,solve(m) - solve(n-1));
	}
	
	return 0;
}
