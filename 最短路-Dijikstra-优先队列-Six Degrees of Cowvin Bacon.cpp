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

//#define pii pair<int, int>
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
const int maxn=300 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n = 0,m = 0; 
bool vis[maxn];
int adj[maxn][maxn];
int a[maxn];
int d[maxn];
typedef  pair<int, int> pii;
struct cmp{
	bool operator()(const pii a,const pii b){
		return a.second > b.second;
	}
};
void dijikstra(int s){
	priority_queue<pii,vector<pii>,cmp > que;
	que.push(pii(s,0));
	d[s] = 0;//不要忘记设置初始值了 
	while(!que.empty()){
		pii p = que.top();
		que.pop();
		int u = p.first,v = p.second;
		if(d[u] < v || vis[u] == true){
			continue;
		}
		vis[u] = true;
		for(int i = 1;i <= n;++i){
			if(d[u] + adj[u][i] < d[i] && vis[i] == false){
				d[i] = d[u] + adj[u][i];
				que.push(pii(i,d[i]));
			}
		}
	}
}
void solve(){
	int minv = INF;
	per(i,1,n){
		fill(d,d+maxn,INF);
		fill(vis,vis+maxn,false);
		dijikstra(i);
		int sum = 0;
		per(j,1,n){
			sum += d[j];
		}
		minv = min(minv,sum*100/(n-1));
	}
	printf("%d\n",minv);
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%d %d",&n,&m)){
		fill(adj[0],adj[0]+maxn*maxn,INF);
		per(i,1,m){
			int num = 0;
			scanf("%d",&num);
			per(j,1,num){
				scanf("%d",&a[j]);
			}
			per(j,1,num){//建图 
				per(k,j+1,num){
					adj[a[j]][a[k]] = adj[a[k]][a[j]] = 1;
				}
			}
		} 
		solve();
	}
	
	return 0; 
}
