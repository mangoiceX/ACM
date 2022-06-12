
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <string>
#include <queue>
#define INF 0xffffff
using namespace std;
const int maxn=101;
int m,n,x,y,v;
int G[maxn][maxn];	//存储距离 
int dist[maxn];		//存储距离某地最小值 
bool vis[maxn];			//存储轨迹 


int prim()
{
	int min = INF,ans = 0,path = 1;
	memset(vis,true,sizeof(vis));
	memset(dist,0X7f,sizeof(dist));
	vis[1] = false;		//标记已经走过		
	while( true )
	{
		for(int i = 1;i <= n;i++)
			if( vis[i] && G[path][i] && dist[i] > G[path][i] )
				dist[i] = G[path][i];	//比如现在path=4,但4与2的距离比3与2的距离远,dist[i]存储距离某地最小值 
		path = -1;     //标记，已经全部走完
		min = INF; 
		for(int i = 1; i <= n; i++)
		{
			if(vis[i] && min > dist[i])
			{
				min = dist[i];
				path = i;
			}
		}
		if(path == -1)
			break;
		ans += min;
		vis[path] = false;	
	}
	return ans;
	
	
}

int main()
{
	while(~scanf("%d",&n)&&n>0)
	{
		m = (n-1)*n/2;
		memset(G,0,sizeof(G));
		while(m--)
		{
			scanf("%d %d %d",&x,&y,&v);
			G[x][y] = G[y][x] = v;
		}
		printf("%d\n",prim());	
	}	
	
	
	
	
	return 0;
}
