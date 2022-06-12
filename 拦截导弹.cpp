#include<bits/stdc++.h>
using namespace std;
#define per(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long LL;
#define INF 0x3f3f3f3f
const int maxn = 3e5;
int n = 0,m = 0;
struct node{
	int num,ma;
};
int dp[maxn+10];
int a[maxn+10];
bool vis[maxn+10];
void solve(){
	memset(dp,0,sizeof(dp));	memset(vis,false,sizeof(vis));
	int res = 0;
	per(i,1,n){
		dp[i] = 1;
		per(j,1,i-1){
			if(a[j] >= a[i]){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
		res = max(res,dp[i]);
	}
	printf("%d\n",res);
	
	/* 
	multiset<int> st;
	int cnt = 0,mi = INF;
	a[0] = INF;
	per(i,1,n){
		st.insert(a[i]);
	}
	
	while(!st.empty()){
		mi = INF;
		per(i,1,n){
			if(!vis[i] && a[i] <= mi){
				vis[i] = true;
				mi = a[i];
				st.erase(a[i]);
			}
		}
		++cnt;
	}
	printf("%d\n",cnt);
	*/
	memset(dp,0,sizeof(dp));
	dp[1] = 1;
	per(i,1,n){
		per(j,1,i-1){
			if(a[i] > a[j] && dp[i] <= dp[j]){
				
			}
		}
	}
}
int main(){
	n = 1;
	while(~scanf("%d",&a[n])){
		++n;
	}
	n -= 1;
	solve();
	
	return 0;
}
