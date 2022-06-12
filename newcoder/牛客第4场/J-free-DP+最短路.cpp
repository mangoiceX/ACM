#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
#define INF 1e9
const int maxn = 1e5 + 10;
int n = 0,m = 0,s = 0,t = 0,k = 0;
int head[maxn],cnt = 0;
int dist[maxn];
struct node{
	int v,dis,kk;
	bool operator < (const node& c)const{
		return c.dis > this->dis;
	}
};
struct Edge{
	int to,w,nex;
}e[maxn];
void init(){
	cnt = 0;
	per(i,1,n){
		head[i] = -1; dist[i] = INF;
	}
}
void add_edge(int from,int to,int w){
	e[++cnt].to = to;
	e[cnt].w = w;
	e[cnt].nex = head[from];
	head[from] = cnt;
}
int dijikstra(){//将DP嵌入最短路中，或者说最短路就是DP，还有要使用这种写法，才能将DP嵌入
	dist[s] = 0;//最短路还有次短路都要储存
	priority_queue<node> pq;
	pq.push(node{s,0,0});
	while(!pq.empty()){
		node u = pq.top(); pq.pop();
		for(int i = head[u.v];i != -1;i = e[i].nex){
			int to = e[i].to;
			if(dist[u.v] + e[i].w < dist[to]){//这条边不选为免费边
				dist[to] = dist[u.v] + e[i].w;
				pq.push(node{to,dist[to],u.kk});
			}
			if(u.kk < k){//可行性判断
				if(dist[to] > u.dis){//优化判断
					dist[to] = u.dis;//将这条边变为免费边
					pq.push(node{to,dist[to],u.kk+1});
				}
			}
		}
	}
	return dist[t];
}
int main(){
	while(~scanf("%d %d %d %d %d",&n,&m,&s,&t,&k)){
		init();
		per(i,1,m){
			int a = 0,b = 0,l = 0;
			scanf("%d %d %d",&a,&b,&l);
			add_edge(a,b,l); add_edge(b,a,l);
		}
		int ans = dijikstra();
		printf("%d\n",ans);
	}

	return 0;
}