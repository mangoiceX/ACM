#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
int m,n;//mΪ������nΪ���� 
struct node
{
	int s,e;
}a[100010],b[100010];//aΪ������bΪ���� 

using namespace std;

int cmp(node a,node b)		//�������
{
	if(a.e == b.e)
		return a.s < b.s;
	return a.e < b.e;	
}

int Find_LB(node K)//���ֲ��� 
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
		sort(a + 1,a + m + 1,cmp);//������ʱ���С��������
		for(int j = 1;j <= n;j++)
		{
			int num = 0;//�� 
			cin >> b[j].s >> b[j].e; 
			int t = Find_LB(b[j]);//���ֲ���,���½� 
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
