/*HDU-1051*/

#include<cstdio>
#include<algorithm>
#include<string.h>

using namespace std;
#define N 5000

struct Wood
{
	int l,w;
	int mark;
}wood[N];

void selectsort(Wood v[],int n)
{
	int i,j,k;
	Wood temp;
	for(i=0;i<n;i++)						//¿¨Æ¬Ñ¡ÔñÅÅÐò,ÉýÐò 
	{
		k=i;
		for(j=i+1;j < n;j++)
		{
			if(v[j].l < v[k].l)
				k=j;
			if(v[j].l == v[k].l)
			{
				if(v[j].w < v[i].w)
					temp=v[i],v[i]=v[k],v[k]=temp;	
			}
		}
		if(k!=i)
			temp=v[i],v[i]=v[k],v[k]=temp;
	}
}

int main()
{
	int testnum = 0;
	int ans[5];
	scanf("%d",&testnum);
	while(testnum--)
	{
		int count = 0,n = 0;
		memset(wood,0,sizeof(wood));
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
			scanf("%d %d",&wood[i].l,&wood[i].w);

		//sort(wood,wood + n,Cmp);
		selectsort(wood,n);
		for(int i = 0;i < n && wood[i].mark != 1;i++)
		{
			int k = i;
			int w = wood[i].w;
			wood[i].mark = 1;
			for(int j = i + 1;j < n && wood[j].mark != 1;j++)
			{
				if(wood[j].w >= w)
				{
					wood[j].mark = 1;
					w = wood[j].w;
					//k = j;
				}
			}
			count++;	
		}
		//ans[testnum] = count;
		printf("%d\n",count);	
	}
	//for(int i = testnum - 1;i >= 0;i--)
	//	printf("%d\n",ans[i]);
	
	
	return 0;
}
 
