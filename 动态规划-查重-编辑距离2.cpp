#include<bits/stdc++.h>
using namespace std;
#define per(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long LL;
#define INF 0x3f3f3f3f
const int maxn = 3e5;
int n = 0,m = 0;
string s1,s2;
int dp[2][maxn+10];
int mis = 1,ctk = 0;
void solve(){
	int size1 = s1.size(),size2 = s2.size();
	dp[0][0] = s1[0] == s2[0] ? 0 : mis;
	per(j,1,size2-1){
		dp[0][j] = (s1[0] == s2[j] ? (j-1)*mis : dp[0][j-1]+1);
	}
	per(i,1,size1-1){
		per(j,1,size2-1){
			dp[i%2][j] = min(dp[(i-1)%2][j-1] + (s1[i] == s2[j] ? 0 : mis) , min(dp[(i-1)%2][j] + mis, dp[i%2][j-1] + mis));
		}
	} 
	printf("%d\n",dp[size1%2][size2-1]);
}
int main(){
	while(cin >> s1 >> s2){
		solve();
	}
	
	return 0;
}
