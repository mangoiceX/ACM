#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
typedef long long LL;
const double eps=1.0e-5;
const int maxn=45000 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int cnt1=0,cnt2=0,cnt3=0,tmp = 0;
LL a[maxn],b[maxn];
int h = 0; 
int mod = 0;
//int mod_pow(int x,int y){//31445
int mod_pow(LL x,LL y){//13195 
	LL res = 1;
	if(y == 0){
		return 1;
	} 
	if(x == 0){
		return 0;
	}
	while(y > 0){
		if(y & 1){
			res = res * x % mod;
		}
		x = x * x % mod;
		y >>= 1;
	}
	
	return res;
}
void solve(){
	LL ans = 0;
	per(i,0,h-1){
		ans = (ans%mod + mod_pow(a[i],b[i]) %mod) % mod;
	}
	printf("%I64d\n",ans);
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&mod);
		scanf("%d",&h);	
		per(i,0,h-1){
			scanf("%I64d %I64d",&a[i],&b[i]);
		}
		solve();
	}
	
	
	return 0; 
}
