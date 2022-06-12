/*poj2231*/
#include<stdio.h>

void selectsort(int v[],int n)
{
	int i,j,k,temp;
	for(i=0;i<n;i++)						//¿¨Æ¬Ñ¡ÔñÅÅÐò,ÉýÐò 
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
	int loc[10000],count = 0,n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%d",&loc[i]);	
	selectsort(loc,n);
	for(int i = 0;i < n;i++)
	{
		for(int j = i+1;j < n;j++)
		{
			count += loc[j]-loc[i];
		}
	}
	printf("%d",count * 2);
	
		
	return 0;
}
