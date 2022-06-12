#include<bits/stdc++.h>

#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f
typedef long long LL;

using namespace std;
const int maxn = 3e5;
int n = 0,m  = 0,k = 0;
int a[maxn+10];
int dp[maxn+10];
int pre[maxn+10],pres[maxn+10];
int pos[maxn+10];
int q_mul(int x,int y){
	int ans = 0;
	while(y > 0){
		if(y&1){
			ans += x;
		}
		x = x+x;
		y >>= 1;
	}
	return ans;
}
int main(){
	while(~scanf("%d",&n)){
		map<int,int> mp;
		per(i,1,n){
			scanf("%d",&a[i]);
			pre[i] = pre[i-1] + a[i];
			pres[i] = pres[i-1] + q_mul(i,a[i]);
		}
		per(i,1,n){
			int loc = 0;
			if(a[i] >= 0){
				loc = i;
				mp[loc] = loc;
			}
			while(i <= n && a[i] >= 0){
				++i;
			}
			if(i-1 <= n && i-1 >= 1 && a[loc] >= 0){
				mp[i-1] = loc;
			}
		}
		a[n+1] = -1;
		int time = 0;
		rep(i,n,1){
			if(a[i] > 0 && a[i+1] <= 0){
				pos[++time] = i;
			}
		}
		
		int maxv = 0;
		per(i,1,time){
			per(j,1,mp[pos[i]]){
				int minus = a[j] + pre[pos[i]] - pre[j];
				if(minus < 0){//Ñ¡ºóÃæ 
					pres[pos[i]] += (-minus);
				}
				maxv = max(maxv,pres[pos[i]]);
			}
		} 
		printf("%d\n",maxv);
	}	
	
	return 0;
} 
