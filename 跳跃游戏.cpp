/*跳跃游戏-贪心*/ 
#include<iostream>
#include<cstdio>

using namespace std; 
#define maxn 500 + 10

int main()
{
	int n,a[maxn];
	cin>>n;
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	int maxnium = 0; 
	for(int i = 0;i < n;i++)
	{
		if(i <= maxnium)//表示能到达该位置
			maxnium = max( maxnium , a[i] + i);//更新所能到达的最大位置 
		else							//类似搜索 
			break;
	}
	if(maxnium >= n - 1)
		printf("true");
	else
		printf("false");
	
	return 0;
}
