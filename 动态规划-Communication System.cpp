#include<iostream> 
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#define INF 1e6
using namespace std;
const int maxn = 100 + 10;
struct Device{
	int b,p;
};
Device dev[maxn][12];
int dp[maxn][1200];
int main(){
	int T = 0;
	int num = 0,par[maxn];
	cin >> T;
	while(T--){
		fill(dp[0],dp[0]+maxn*maxn,INF);
		cin >> num;
		for(int i = 1;i <= num;++i){
			
			cin >> par[i];
			for(int j = 1;j <= par[i];++j){
				cin >> dev[i][j].b >> dev[i][j].p;
				if(i == 1){
					dp[i][dev[i][j].b] = min(dev[i][j].p,dp[i][dev[i][j].b]);
				}else{
					for(int k = 0;k < 1200;++k){
						if(dp[i-1][k] != INF){
							if(k < dev[i][j].b){
								dp[i][k] = min( dp[i-1][k] + dev[i][j].p,dp[i][k]);
							}else{
								dp[i][dev[i][j].b] = min( dp[i-1][k] + dev[i][j].p,dp[i][dev[i][j].b]);
							}
						}
					}
					
					
					
				}
				
				
				
			}
		}
			double ans = 0;
			for(int i = 0;i < 1200;++i){
				if(dp[num][i] != INF){
					ans = max ( double(i/dp[num][i] ) , ans);
				}
			}
			cout << ans << endl; 
		}
		/*
		double maxv = dev[1][j].b / double(dev[1][j].p);
		int minb = dev[1][j].b,minp = dev[1][j].p;
		for(int j = 2;j <= par[1];++j){
			double mv = dev[1][j].b / double(dev[1][j].p);
			if(mv > maxv && (dev[1][j].b >= minb){
				
			}
		}
		*/
		//for(int j = 1;j <= par[1];++j){
		//	dp[1][dev[1][j].b] = min(dev[1][j].p,dp[1][dev[1][j].b]);
	//	}
		/*
		for(int i = 1;i <= num;++i){
			
			for(int j = 1;j <= par[i];++j){
				if(i == 1){
					dp[1][dev[1][j].b] = min(dev[1][j].p,dp[1][dev[1][j].b]);
				}
				
				if(dp[i-1][] > dev[i][])
			}
			
		}
		
		*/
	
	
	return 0;
}
