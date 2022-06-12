#include<stdio.h>
int main()
{
	int card[1050]={0},i,j,m,n,a[20];
	int lager=0,ans=0,count=0;
	while((scanf("%d %d",&m,&n)!=EOF)&&(m>0)&&(n>0))
	{
		ans=0;lager=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			card[j]=1;
		}
		for(i=m*n;i>0;i--)
		{
			if(!card[i])
				lager++;
			else
			{
				if(lager==0)
					ans++;
				else
					lager--;
			}
		}
		a[count]=ans;
		count++;
	}
	for(i=0;i<count;i++)
		printf("Case %d:%d\n",i+1,a[i]);
	return 0;
}
