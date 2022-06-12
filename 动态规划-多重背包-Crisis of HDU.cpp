#include<bits/stdc++.h>
using namespace std;
const int  maxn = 100 + 10;
int dp[maxn][10000+100];
int n = 0,sum = 0;
struct node{
	int num,val;
};
node ar[maxn];
void solve(){
	fill(dp[0],dp[0]+maxn*(10000 + 10),0);
	//dp[0][0] = 1;
	for(int i = 0;i <= n;++i){//合法状态初始化 
		dp[i][0] = 1;
	}
	bool flag = false;
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= sum;++j){
			for(int k = 0;k <= ar[i].num &&  k * ar[i].val <= j;++k){
				if(j == sum && dp[i][j] + dp[i-1][j-k*ar[i].val] > 0){//因为上面%1000可能会是0 
					flag = true;
				}
				dp[i][j] = (dp[i][j] + dp[i-1][j-k*ar[i].val]) % 10000;
				/* 
				if(j == sum && dp[i][j] != 0){//因为上面%1000可能会是0 
					flag = true;
				}
				*/
			}
		} 
	}
	if(flag == false){
		printf("sorry\n");
		return ;
	}
	printf("%d\n",dp[n][sum]);
}
int main(){
	while(~scanf("%d",&n) && n){
		sum = 0;
		for(int i = 1;i <= n;++i){
			scanf("%d %d",&ar[i].val,&ar[i].num);
			sum += ar[i].num * ar[i].val;
		}
		if(sum % 3 != 0){
			puts("sorry");
			continue;
		}
		sum /= 3;
		solve();
	}
	
	return 0;
} 
