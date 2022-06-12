#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

typedef long long LL;

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 3e5;
int n = 0,m = 0,k = 0;
struct Edge{
	int to,w;
	Edge(){
		
	}
	Edge(int x,int y){
		to = x;w = y;
	}

};
bool operator < (Edge a,Edge b){
	return (a.to == b.to) ? a.w < b.w : a.to < b.to;
}
vector<Edge> G[maxn+10];
map<Edge,int> mp;
Edge a[maxn+10];
int d[maxn+10];
bool vis[maxn+10];
struct cmp{
	bool operator () (pii a,pii b){
		return a.second > b.second;//小值优先 
	}
};
void dfs(int s){//**********这个版本是错误的解法 
	priority_queue<pii,vector<pii>,cmp > pq;
	//priority_queue<pii,vector<pii>,greater<pii> > pq;
	//通过指定greater<pii>参数，堆按照从小到大的顺序取出值 
	int ans[maxn+10];
	set<Edge> st;
	fill(d,d+maxn+10,INF);
	fill(vis,vis+maxn,false);
	d[s] = 0;
	pq.push(pii(s,0));
	int cnt = 0;
	while(!pq.empty() && cnt <= k + 1){
		pii p = pq.top();pq.pop();
		int u = p.first;

		if(d[u] < p.second || vis[u] == true){
			continue;
		}
		vis[u] = true;
		ans[++cnt] = u;
		if(ans[cnt-1] != 0){
			st.insert(Edge(ans[cnt-1],u));
		}
		//st.insert(u);
		per(i,0,G[u].size()-1){
		//ans[++cnt].first = u;
			Edge e = G[u][i];
			if(d[e.to] > d[u] + e.w && vis[e.to] == false){
				d[e.to] = d[u] + e.w;
				pq.push(pii(e.to,d[e.to]));
			}
		}
	}
	printf("%d\n",st.size()-1);
	per(i,1,st.size()){
		if(st.find(Edge(a[i].to,a[i].w)) != st.end() || st.find(Edge(a[i].w,a[i].to)) != st.end()){
			printf("%d ",i);
		}
	}
	printf("\n");
}
int main(){
	while(~scanf("%d %d %d",&n,&m,&k)){
		per(i,1,m){
			G[i].clear();
		}
		per(i,1,m){
			int x = 0,y = 0,w = 0;
			scanf("%d %d %d",&x,&y,&w);
			G[x].push_back(Edge(y,w));
			G[y].push_back(Edge(x,w));
			a[i].to = x;a[i].w = y;
		}
		
		dfs(1);
	}
		
	return 0;
}

