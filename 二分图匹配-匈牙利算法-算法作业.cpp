/*
程序求解最大二分匹配问题 
程序采用的是匈牙利算法，但其本质与最大流算法一样的，采用的是和Ford-Fulkerson算法一样的dfs，
只是匈牙利算法相比FF算法的路径少了源点s到中间点，并且缺少了反向边，其中反向边的建立由于二分匹配所以
flow == 0 or == 1,匈牙利算法通过记录每个节点的汇入点，来实现和反向边一样的功能， 
还有中间点到汇点t的有向路径，
但是这两个路径在最大流算法中的方向是唯一确定的，所以可以省略。所以FF算法省略s,t即为匈牙利算法。 
*/
#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
const int maxn = 200;
int mp[maxn+10][maxn+10] = {0};//邻接矩阵， 
int s = 0,t = 200;
int n = 0;
int cx[maxn+10],cy[maxn+10];//cx表示x集合中匹配的y，cy表示y集合中匹配的x 
bool vis[maxn+10];
int path(int u){
	per(i,1,84){
		if(!vis[i] && mp[u][i] == 1){
			vis[i] = true;
			if(cy[i] == -1 || path(cy[i])){//如果y集合的元素i没有被匹配或者，可以从cy[i]找到增广路 
				cx[u] = i; cy[i] = u;
				return 1;
			}
		}
	}
}
int max_match(){
	int ans = 0;
	memset(cx,-1,sizeof(cx)); memset(cy,-1,sizeof(cy));
	per(i,1,n){
		//if(cx[i] == -1){//
			memset(vis,false,sizeof(vis));	
			ans += path(i);
		//}
	}
	per(i,1,n){
		printf("%d\n",cx[i]);//输出x集合匹配的y 
	}
	return ans;
}
int main(){
	while(~scanf("%d",&n)){
		memset(mp,0,sizeof(mp));
		per(i,1,n){
			int k = 0;
			scanf("%d",&k);
			per(j,1,k){	
				int x = 0,y = 0;
				scanf("%d %d",&x,&y);
				mp[i][12*(x-1)+y] =  1;//建图（有向边）
			}
		}
		int ans = max_match();//最大匹配 
		printf("%d\n",ans);
	}
	
	return 0;
} 
/*
5
1 1 1
2 1 1 2 2
1 2 2
2 3 2 3 3
1 3 3
*/
