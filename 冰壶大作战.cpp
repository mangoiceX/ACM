#include<stdio.h>
int w,h;
int ans=0,count=0;
int x_start,y_start,x_goal,y_goal;
int dir[4][2]={1,0,-1,0,0,1,0,-1},square[20][20];;
void dfs(int x_start,int y_start,int x_goal,int y_goal)
{
	int i,j,x1,y1,flag=0;
	x1=x_start,y1=y_start;
	for(i=0;i<4;i++)
	{
		if(x1==x_goal&&y1==y_goal)			//到达目标 
		{
			ans=(ans<count?ans:count);
			count=0;
			return ;
		}
		if(i<2)	//沿x运动 
		{
			for(x1=x_start,y1=y_start;x1>=0&&x1<h&&y1>=0&&y1<w&&(square[x1+dir[i][0]][y1])!=1;x1=x_start+dir[i][0],
				y1=y_start+dir[i][1])
				;
			if(square[x1+dir[i][0]][y1]==1)
			{
				square[x1+dir[i][0]][y1]==0;		//消除石块 
				count++;
				dfs(x1,y1,x_goal,y_goal);									//递归调用没写 
			}
			else 						//处理有问题，总是会跑出去 
			{
				if(x1==x_goal&&y1==y_goal)			//到达目标 
				{
					ans=(ans<count?ans:count);
				}
				else
				{
					count=0;
					continue;
				}
			}		
		
		}
		else	//沿y运动 
		{
			for(x1=x_start,y1=y_start;x1>=0&&x1<h&&y1>=0&&y1<w&&square[x1][y1+dir[i][0]]!=1;x1=x_start+dir[i][0],
				y1=y_start+dir[i][1])
				;
			if(square[x1][y1+dir[i][0]]==1)
			{
				square[x1][y1+dir[i][0]]==0;			//消除石块
				count++;
				dfs(x1,y1,x_goal,y_goal);	
			} 
			else 						//处理有问题，总是会跑出去 
			{
				if(x1==x_goal&&y1==y_goal)			//到达目标 
				{
					ans=(ans>count?ans:count);
				}
				else
				{
					count=0;
					continue;
				}
			}		
		}
	}
	if(ans==0)
		printf("failed\n");
	else
		printf("succeded\n");	
	
}
int main()
{
	int i,j,w,h;
	int x_start,y_start,x_goal,y_goal;
	
	while(scanf("%d %d",&w,&h)!=EOF&&w>0&&h>0)
	{
		for(i=0;i<h;i++)
		{
			getchar();
			for(j=0;j<w;j++)
			{
				scanf("%d",&square[i][j]);
				if(square[i][j]==2)					//记录起始和目标位置 
					y_start=j,x_start=i;
				if(square[i][j]==3)
					y_goal=j,x_goal=i;	
			}
		}
		dfs(x_start,y_start,x_goal,y_goal);
		printf("%d",ans);	
	}
	return 0;	
} 
