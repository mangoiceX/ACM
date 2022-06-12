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

bool Cmp(const Wood a, const Wood b) 
{ 
    return a.l < b.l; 
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

		sort(wood,wood + n,Cmp);
		for(int i = 0;i < n && wood[i].mark != 1;i++)
		{
			wood[i].mark = 1;
			for(int j = i + 1;j < n && wood[j].mark != 1;j++)
			{
				if(wood[j].w >= wood[i].w)
					wood[j].mark = 1;
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
 
