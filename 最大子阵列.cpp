#include<iostream>
#include<cstdio>
using namespace std;
const int INF = 99999999;


int main()
{
	int max = -INF,sum = 0,n = 0;
	int a[1000];
	
	while(cin>>n)
	{
		for(int i = 0;i < n;i++)
			scanf("%d",&a[i]);
		for(int i = 0;i < n;i++)
		{
			if(sum >= 0)
				sum += a[i];
			else
				sum = a[i];
			if(sum > max)
				max = sum;
		}
	}
	cout<<max<<endl;
	
	
	
	return 0;
 } 
