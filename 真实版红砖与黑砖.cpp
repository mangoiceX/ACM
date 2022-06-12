#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char map[21][21];
int vis[21][21], m, n,x,y,cnt;
int dir[4][2] = { 1,0,-1,0
				,0,1,0,-1 };

void dfs(int x,int y)
{
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int x1 = x + dir[i][0];
		int y1 = y + dir[i][1];
		if (x1 >= 0 && x1 < m&&y1 >= 0 && y1 < n&&vis[x1][y1] == 0 && map[x1][y1] != '#')
		{
			cnt++;
			dfs(x1, y1);
		}
	}
}
int main()
{
	while (scanf("%d %d", &n, &m) != EOF && m + n > 0)
	{ 
		memset(vis, 0, sizeof(vis));
		cnt = 1;
		for (int i = 0; i < m; i++)
		{
			getchar();						//¶ÁÈ¡¿Õ¸ñ 
			for (int j = 0; j < n; j++)
			{
				scanf("%c", &map[i][j]); 
				if (map[i][j] == '@')
				{
					x = i;
					y = j;
				}
			}
		}
		dfs(x, y);
		printf("%d\n", cnt);
	}
	return 0;
}
