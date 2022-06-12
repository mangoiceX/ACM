#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int n = 0,sum = 0;
	int a[10000]; 
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	if(n & 1)
	{
		for(int i = 0;i < n;i += 2)
			sum += a[i];
	}
	else
	{
		for(int i = 0;i < n - 2;i += 2)
			sum += a[i];
		if(a[n-1] > a[n-2])
			sum += a[n-1];
		else
			sum += a[n-2];
	}
	printf("%d",sum);
	
	return 0;
}
