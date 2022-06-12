#include<bits/stdc++.h>
using namespace std;
const int maxn = 32768;
long long dp[maxn+10];
void solve(){
	fill(dp,dp+maxn+10,0);
	dp[0] = 0;dp[1] = 1;dp[2] = 2;dp[3] = 3;
	for(int i = 4;i <= maxn;++i){
		if(i & 1){
			//if(i % 3 == 1){
				dp[i] = dp[i-1] + dp[(i-2)/2]  - dp[(i-2)/4]+ dp[(i-3)/3] - dp[(i-3)/9];
				if((i-2) % 6 == 0){
					dp[i] -= dp[(i-2)/6];
				}
				if((i-3) % 6 == 0){
					dp[i] -= dp[(i-3)/3];
				}
				if((i-1)%6 == 0){
					dp[i] -= dp[i/6];
				}
			//}else if(i % 3 == 2){
				//dp[i] += dp[i-1] + dp[(i-3)/3] + dp[(i-2)/2];
		//	}
			//if(i % 3 == 0){
			//	dp[i] += dp[i/3];
			//}
		}else{
			//dp[i] = dp[(i-2)/2] + dp[i/2];
			//dp[i] = dp[i-1] + 2;//dp[(i-2)/2] + dp[(i-3)/3];
			dp[i] = dp[i-1] + dp[(i-2)/2]  - dp[(i-2)/4]+ dp[(i-3)/3] - dp[(i-3)/9];
			if((i-2) % 6 == 0){
					dp[i] -= dp[(i-2)/6];
			}
			if((i-3) % 6 == 0){
				dp[i] -= dp[(i-3)/3];
			}
			if((i-1) %6 == 0){
				dp[i] -= dp[i/6];
			}
			if((i-4) % 6 == 0){
				dp[i] -= dp[i/6];
			}
			//if(i % 3 == 0){
			//	dp[i] += dp[i/3];
		//	}
		}
	}
}
int main(){
	solve();
	int n = 0;
	while(~scanf("%d",&n)){
		printf("%I64d\n",dp[n]);
	}
	return 0;
} 
