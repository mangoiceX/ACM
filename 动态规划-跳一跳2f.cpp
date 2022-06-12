#include<bits/stdc++.h> 
using namespace std;
#define per(i,a,b) for(int i=(a);i<=(b);i++)
int n = 0,m = 0,h = 0;
int r[10][10];
int dp[10][10][10];
void solve(){
	memset(dp,0,sizeof(dp));
	per(i,1,m){
		per(k,0,h){//h循环要放在列循环前面，因为列循环每一次都要用到第k-1的结果 
			per(j,1,n){
				dp[i][j][k] = max(dp[i-1][j-1][k],max(dp[i-1][j][k],dp[i-1][j+1][k])) + r[i][j];
				if(k == 0){
					continue;
				}
				dp[i][j][k] = max(dp[i][j][k],max(dp[i][j-1][k-1],dp[i][j+1][k-1]) + r[i][j]);
			}	
		}
	}
	int maxv = -1,loc = 0,times = 0;
	per(i,1,n){
		if(dp[m][i][h] > maxv){
			maxv = dp[m][i][h];
			loc = i;
		}
	}
	printf("The starting position is %d, The maximum bonus you can get is %d\n",loc,maxv);
}
int main(){
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	while(~scanf("%d %d %d",&m,&n,&h)){
		per(i,1,m){
			per(j,1,n){
				scanf("%d",&r[i][j]);
			}
		}
		solve();
	}
	return 0;
}
