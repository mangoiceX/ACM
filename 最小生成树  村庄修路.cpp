
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
int G[maxn][maxn];	//�洢���� 
int dist[maxn];		//�洢����ĳ����Сֵ 
bool vis[maxn];			//�洢�켣 


int prim()
{
	int min = INF,ans = 0,path = 1;
	memset(vis,true,sizeof(vis));
	memset(dist,0X7f,sizeof(dist));
	vis[1] = false;		//����Ѿ��߹�		
	while( true )
	{
		for(int i = 1;i <= n;i++)
			if( vis[i] && G[path][i] && dist[i] > G[path][i] )
				dist[i] = G[path][i];	//��������path=4,��4��2�ľ����3��2�ľ���Զ,dist[i]�洢����ĳ����Сֵ 
		path = -1;     //��ǣ��Ѿ�ȫ������
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
