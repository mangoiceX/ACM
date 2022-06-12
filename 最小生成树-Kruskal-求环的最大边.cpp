#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
using namespace std;
const int maxn = 2222222 + 100;
const int maxv = 5e5 + 10;	
struct node{
	int u,v,w;
};

node edge[maxn];
int n = 0,m = 0;
int fa[maxv],rak[maxv];
bool cmp(node x,node y){
	return x.w < y.w;
}
void init(){
	per(i,1,n){
		fa[i] = i;
		rak[i] = 0;
	}
}
int find(int x){
	if(x == fa[x]){
		return x;
	}else{
		return fa[x] = find(fa[x]);
	}
}
void unite(int x,int y){
	//x = find(x); y = find(y);
	if(x == y){
		return ;
	}
	if(rak[x] < rak[y]){
		fa[x] = y;
	}else{
		if(rak[x] == rak[y]){
			++rak[x];
		}
		fa[y] = x;
	}
}
bool same(int& x,int& y){
	return (x = find(x)) == (y = find(y)) ;
}
void solve(){
	init();
	int ans = 500000;
	per(i,1,m){
		if(!same(edge[i].u,edge[i].v)){
			unite(edge[i].u,edge[i].v);
		}else{
			ans = min(ans,edge[i].w);
			break;
		}
	}
	if(ans == 500000){
		//puts("No solution!");
		printf("No solution!\n");
		return ;
	}
	printf("%d\n",ans);
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		per(i,1,m){
			scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].w);
		}
		sort(edge+1,edge+1+m,cmp);
		solve();
	}


	return 0;
}