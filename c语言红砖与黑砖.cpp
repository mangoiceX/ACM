#include<stdio.h>
#include<string.h>
#include<math.h>
char map[25][25];
int flags[25][25],w,h,count;
void dfs(int x,int y)
{
	if(x<0||y<0||x>=h||y>=w)
		return ;
	if(flags[x][y]!=0)
		return ;
	flags[x][y]=1;
	count++;
	for(int i=-1;i<2;i++)
		for(int j=-1;j<2;j++)
			if(map[x+i][j+y]!='#'&&abs(i)!=abs(j))
				dfs(x+i,j+y);
}
int main()
{
	while(scanf("%d%d",&w,&h)&&(h+w))
	{
		count=0;
		memset(flags,0,sizeof(flags));
		for(int i=0;i<h;i++)
			scanf("%s",map[i]);
		int x,y;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(map[i][j]=='@')
				{
					x=i;
					y=j;
					break;
				}
			dfs(x,y);
			printf("%d\n",count);
		
	}
 } 

