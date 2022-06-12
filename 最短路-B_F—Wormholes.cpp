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
const int maxn=500 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n = 0,m = 0,w = 0; 
struct edge{
	int s,e,t;
};
edge ed[maxn*10];//因为同两个点之间可能存在多条路径 
int d[maxn];
int cnt = 0;
void B_F(){
	fill(d,d+maxn,INF);
	per(i,1,n){
		per(j,1,cnt){
			edge e = ed[j];
			if(d[e.e] > d[e.s] + e.t){
				d[e.e] = d[e.s] + e.t;
				if(i == n){
					printf("YES\n");
					return ;
				}
			}
		}
		
	}
	printf("NO\n");
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	int T = 0;
	scanf("%d",&T); 
	while(T--){
		scanf("%d %d %d",&n,&m,&w);
		cnt = 0;
		per(i,1,m){
			int s = 0,e = 0,t = 0;
			scanf("%d %d %d",&s,&e,&t);
			ed[++cnt].s = s,ed[cnt].e = e,ed[cnt].t = t;
			ed[++cnt].s = e,ed[cnt].e = s,ed[cnt].t = t;
		}
		per(i,1,w){
			int s = 0,e = 0,t = 0;
			scanf("%d %d %d",&s,&e,&t);
			ed[++cnt].s = s,ed[cnt].e = e,ed[cnt].t = -t;
		}
		B_F();
	}
	
	return 0; 
}
