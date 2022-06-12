#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL dp[25][25][2500];//找状态，太重要了 
//dp[i][j][k],f(i,j,k)表示i位数，支点j，两边和位k（左边为正，右边为负） 
//枚举j，注意减去0的情况，因为0是唯一一个可以变支点依然成立的数 
int d[25];
LL dfs(int pos,int mid,int sum,bool uplim){
	if(sum < 0){//剪枝，提前退出,sum<0时,表示右边的和大于了左边 
		return 0;//利用正负性，只用记录一个值sum即可，而不用记录l_sum和r_sum,之前我就是这样的 
	}
	if(pos <= 0){
		return sum == 0;
	}
	if(!uplim && dp[pos][mid][sum] != -1){
		return dp[pos][mid][sum];
	}
	LL temp = 0;
	int up = uplim ? d[pos] : 9;
	for(int i = 0;i <= up;++i){
		temp += dfs(pos-1,mid,sum + i*(pos-mid),uplim && i == d[pos]);
	}
	if(!uplim){
		dp[pos][mid][sum] = temp;
	}
	return temp;
}
LL solve(LL x){//注意l==0时的情况 
	//if(x < 0){
	//	return 0;
	//}
	LL temp = x;
	int cnt = 0;
	while(temp != 0){//之前是temp > 0,这样不便于-1,即l==0时的情况 
		d[++cnt] = temp % 10;
		temp /= 10;
	}
	d[cnt+1] = 0;
	LL ans = 0;
	for(int mid = 1;mid <= cnt;++mid){//
		ans += dfs(cnt,mid,0,true);
	}
	ans -= (cnt - 1);//减去00,000,0000等情况 
	return ans;
}

void init(){
	memset(dp,-1,sizeof(dp));
}

int main(){
	int T = 0;
	LL l = 0,r = 0;
	cin >> T;
	init();
	while(T--){
		cin >> l >> r;
		cout << solve(r) - solve(l-1) << endl;
	}
	return 0;
}
