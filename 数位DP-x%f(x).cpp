#include<bits/stdc++.h>
using namespace std;
int dp[11][82][82][82];//i-pos,j-sum,k-num,l-mod
//前pos位，当前数字和为sum，数值为num ,最终数字和为mod 
//由这4个状态变量确定唯一一个状态，状态的选择要无后效性 
 
int d[11];
int m = 0,n = 0;
int dfs(int pos,int sum,int num,int mod,bool lim){
	if(pos == 0){
		return num == 0 && sum == mod;//
	}
	if(!lim && dp[pos][sum][num][mod] != -1){
		return dp[pos][sum][num][mod];
	}
	int up = lim ? d[pos] : 9;
	int tmp = 0;
	for(int i = 0;i <= up;++i){
		tmp += dfs(pos-1,sum + i,(num*10 + i) % mod,mod,lim && i == d[pos]);
	}
	if(!lim){
		dp[pos][sum][num][mod] = tmp;
	}
	return tmp;
}
int solve(int x){
	//重复初始化了 
	//fill(dp[0][0][0],dp[0][0][0]+11*82*82*82,-1);
	int tmp = x;
	int cnt = 0;
	while(tmp > 0){
		d[++cnt] = tmp % 10;
		tmp /= 10;
	}
	d[cnt+1] = 0;
	int ans = 0;
	for(int i = 1;i <= 81;++i){
		ans += dfs(cnt,0,0,i,true);
	} 
	return ans;
}
int main(){
	int T = 0,kase = 0;
	scanf("%d",&T);
	memset(dp,-1,sizeof(dp));//只需要初始化一次，因为数字满不满足条件是固定的 
	//不会随测试样例改变 
	while(T--){
		scanf("%d %d",&n,&m);
		printf("Case %d: %d\n",++kase,solve(m) - solve(n-1));
	}
	
	return 0;
}
