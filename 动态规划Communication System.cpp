#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#define INF 1e6
using namespace std;
const int maxn = 100 + 10;

int dp[maxn][1200];
//dp[i][j]表示的是选了i个devices，最小宽带是j时的最小花费
//两个变量相互制约，不妨固定i不变，贪心求j，也就是质量一定时，花费的最小值 
int main(){
	
	int T = 0,q = 0,num = 0,b = 0,p = 0;
	//cin >> T;
	scanf("%d",&T);
	while(T--){
		fill(dp[0],dp[0] + maxn*1200,INF);
		scanf("%d",&q);
		for(int i = 1;i <= q;++i){	
			//cin >> num;
			scanf("%d",&num);
			for(int j = 1;j <= num;++j){
				//cin >> b >> p;
				scanf("%d %d",&b,&p);
				if(i == 1){
					dp[i][b] = min(dp[i][b],p);
				}else{
					for(int k = 0;k < 1200;++k){//寻找有重量记录的情况 
						
						if(dp[i-1][k] != INF){//假设每种情况，都选择当前的device
						//但是，当到达的宽带相同时，要比较 ，选较小值 
							if(b >= k){
								dp[i][k] = min( dp[i-1][k] + p,dp[i][k]);
							}else{
								dp[i][b] = min( dp[i-1][k] + p,dp[i][b]);
							}
						}
						
					}	
				}
				
			}
		}	
		double ans = 0;
		for(int j = 0;j < 1200;++j){
			if(dp[q][j] != INF){
				ans = max(double(j)/dp[q][j],ans);
			}
			
		}	
		printf("%.3lf\n",ans);
		//cout << ans << endl;
	}
	
	return 0;
}
