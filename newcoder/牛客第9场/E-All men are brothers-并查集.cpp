#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;
int n = 0,m = 0;
int fa[maxn],rak[maxn];
int sons[maxn];
LL C[maxn][5];
LL sum = 0,now = 0;
//sum记录的是所有集合(size>1),的C(size,2)的总和，每次合并两个集合时，sum-C(a,2)-C(b,2)
//然后再sum += C(a+b,2)
/*
采取迭代算法，也就是每次计算要从上一次的结果中减去的不合法发案数。
now记录的是上一次的合法方案数
当前合法方案数 = now - a*b*(C(n-a-b) - (sum - C(a,2) - C(b,2)));
不合法方案数 = 从a,b中各取一个，然后从其它集合中取2个的合法方案（这个可以用
剩下所有集合取2个，再减去从每个集合取两个的方案数） 
*/
void  init(){
	sum = 0;
	per(i,1,n){
		fa[i] = i;
		rak[i] = 0;
		sons[i] = 1;
	}
}

int find(int x){
	if(fa[x] == x){
		return x;
	}
	return fa[x] = find(fa[x]);
}	
void unite(int x,int y){
	LL ans = 0;
	x = find(x);y = find(y);
	if(x == y){
		return ;
	}
	if(rak[x] < rak[y]){
		fa[x] = y;
		sum -= C[sons[x]][2] + C[sons[y]][2];
		LL other = C[n-sons[x]-sons[y]][2];
		ans = now - sons[x]*sons[y]*(other - sum);
		sum += C[sons[x]+sons[y]][2];
		sons[y] += sons[x];
	}else{
		if(rak[x] == rak[y]){
			++rak[x];
		}
		fa[y] = x;
		sum -= C[sons[x]][2] + C[sons[y]][2];
		LL other = C[n-sons[x]-sons[y]][2];
		ans = now - sons[x]*sons[y]*(other - sum);
		sum += C[sons[x]+sons[y]][2];
		sons[x] += sons[y];
	}
	now = ans;
	return ;
}


int main(){
	for(int i=0;i<=100000;i++)
        C[i][0]=1,C[i][1]=i;
    for(int i=1;i<=100000;i++)
        for(int j=2;j<=4;j++)
            C[i][j]=C[i-1][j]+C[i-1][j-1];
	while(~scanf("%d  %d",&n,&m)){
		init();
		now = C[n][4];
		printf("%lld\n",now);
		per(i,1,m){
			int x= 0,y = 0;
			scanf("%d %d",&x,&y);
			if(find(x) != find(y)){
				unite(x,y);
				printf("%lld\n",now);
			}else{
				printf("%lld\n",now);
			}
		}
	}

	return 0;
}
