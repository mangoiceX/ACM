#include<stdio.h>
void selectsort(int v[],int n)
{
	int i,j,k,temp;
	for(i=0;i<n;i++)						//卡片选择排序,升序 
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(v[j]<v[k])
				k=j;
		if(k!=i)
			temp=v[i],v[i]=v[k],v[k]=temp;
	}
}

int main()
{
	int m,n,count=0,ct=0,i,j,k,temp,num,sum=0,cnt=0,flag=0;
	int nm=0;
	int a[1000],b[500],c[1000],d[10];
	//printf("input m and n:\n");
	while(scanf("%d %d",&m,&n)!=EOF&&(m>0)&&(n>0))
	{
	count=0,nm=0,ct=0,cnt=0;
	for(i=0;i<m*n;i++)
		a[i]=i+1;		
	for(i=0;i<n;i++)		//我的卡片 
		scanf("%d",&b[i]);
	selectsort(b,n);
	for(i=0;i<m*n;i++)
	{flag=0;
		num=a[i];
		for(j=0;j<n;j++)
		{
			if(num!=b[j])
			{
				flag=1;
			}
			else
			{	
				flag=0;
				break;
			}
		}
			if(flag==1)
			{
				c[nm]=a[i];	
				nm++;
			}
	}
	//for(i=0;i<m*n-n;i++)
	//	printf("%d ",c[i]);		
	for(i=n-1;i>=0;i--)
	{
		for(j=m*n-n-1-ct;j>=cnt;j--)
		{
			flag=0;
				if(c[j]>b[i])	//比它大的数有多少 
				{
					ct++;
					break;
				 }
				else
				{
					flag=1;
					count++;
					break;
				 } 
		}
			
		if(flag!=0)
			cnt++;
	}
	d[sum]=count;
	sum++;	
}
for(i=0;i<sum;i++)
	printf("Case %d:%d\n",i+1,d[i]);		
	return 0;	
} 
