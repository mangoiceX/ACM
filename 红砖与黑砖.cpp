#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
int count;
char **p,ch;
void dfs(int x,int y,int m,int n,char *v)
{
	
}

int main()
{
	int m,n,i,j,x,y;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		for(i=0;i<n;i++)
			p=(char **)malloc(n*sizeof(char*));
		for(i=0;i<m;i++)
			p[i]=(char *)malloc(m*sizeof(char));
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				scanf("%c",&p[i][j]);
				if(p[i][j]=='@')
					y=i,x=j;	
			}			
		dfs(x,y); 
		printf("%d\n",count);
	}
	return 0;
}
