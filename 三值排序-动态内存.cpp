/*计蒜客-三值排序-贪心*/ 
#include<iostream>
#include<cstdio>
#include<cmath> 
#include<cstdlib>
#include<algorithm>
const int  maxn 1005
int a[maxn],c[maxn],size;
using namespace std;

void input()
{
	cin>>size;
	for(int i = 0;i < size;i++)
		scanf("%d",&a[i]);
}

void answer()
{
	memcpy(c,a,sizeof(c));
	sort(c+1,c+1+size);
	int count = 0;
	for(int i = 0;i < size;i++)
		if(a[i] != c[i])
		{
			int t = 0;
			for(int j = size - 1;j > i;j--)
			{
				if(a[j] == c[i] && a[j] != c[j])
				{
					t = j;
					if(c[j] == a[i])
						break;
				}
			}
			swap(a[i],a[t]);
			count++;
		}
		cout<<count<<endl;
}

int main()
{
	//void input(int v[],int size);//输入
	//void answer(int s[],int d[],int size);//得到答案
	 
	/*int *a,*c,size_m;
	cin>>size_m;
	
	for(int i = 0;i < size_m;i++)
	{
		a = (int*)malloc(size_m * sizeof(int));
		c = (int*)malloc(size_m * sizeof(int));
	}
	input(a,size_m);
	memcpy(c,a,sizeof(a));
	sort(c+1,c+1+size_m);
	answer(a,c,size_m);
	*/
	input();
	answer();
	return 0;
}
