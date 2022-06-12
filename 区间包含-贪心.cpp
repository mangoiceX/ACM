#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
int m,n;//m为被动，n为主动 
struct node
{
	int s,e;
}a[100010],b[100010];//a为被动，b为主动 

using namespace std;

int cmp(node a,node b)		//排序规则
{
	if(a.e == b.e)
		return a.s < b.s;
	return a.e < b.e;	
}

int Find_LB(node K)//二分查找 
{
	int left = 1,right = m;
	int mid = 0;
	while(left < right)
	{
		mid = left + (right - left) / 2;
		if(a[mid].e == K.e)
			return mid;
		else if(a[mid].e > K.e)
			right = mid - 1;
		else
			left = mid + 1;	
	}
	return mid;
}
int main()
{
	while(cin >> m >> n)
	{
		for(int i = 1;i <= m;i++)
			cin >> a[i].s >> a[i].e;
		sort(a + 1,a + m + 1,cmp);//按结束时间从小到大排序
		for(int j = 1;j <= n;j++)
		{
			int num = 0;//答案 
			cin >> b[j].s >> b[j].e; 
			int t = Find_LB(b[j]);//二分查找,找下界 
			for(int i = 1;i <= t+1;i++)
			{
				if(a[i].s >= b[i].s && a[i].e <= b[i].e)
				{
					num++;
					b[i].s = a[i].e;
				}
			}
			cout << num << endl;
		} 
			
	}
	return 0;
}
