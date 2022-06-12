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
#define INF 0x3f3f3f3f
typedef long long LL;
const double eps=1.0e-5;
const int maxn=3e5 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n = 0,k = 0,m = 0; 
int a[maxn];
void solve(){
	double res = 0;
	per(i,1,k){
		res += 1.0 / double( double(m - i + 1) / (n - i + 1));
	}
	printf("%.7lf\n",res);
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	int T = 0,kase = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&n,&m,&k);
		printf("Case #%d: ",++kase);
		solve();
	}
	
	return 0; 
}
