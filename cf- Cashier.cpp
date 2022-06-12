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
const int maxn=1e5 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
struct node{
	int s,e;
	int time;
};
int n = 0,lo = 0,a = 0; 
node nod[maxn];
node fre[maxn];
void solve(){
	int ans = 0;
	per(i,1,n+1){
		ans += (nod[i].s - nod[i-1].e) / a;
	}
	printf("%d\n",ans);
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%d %d %d",&n,&lo,&a)){
		nod[0].s = nod[0].e = nod[0].time = 0;
		per(i,1,n){
			scanf("%d %d",&nod[i].s,&nod[i].time);
			nod[i].e = nod[i].s + nod[i].time;
		} 
		nod[n+1].s = lo; 
		solve();
	}
	
	return 0; 
}
