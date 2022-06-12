/*STL-���ֲ����㷨*/
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

void Print(int v[],int size)
{
	for(int i = 0;i < size;i++)
		cout<<v[i]<<" ";
		//printf("%d ",v[i]);
	printf("\n");
}

struct Rule1
{
	bool operator() (const int &a1,const int &a2)
	{
		return a1%10 < a2%10;
	}
};

int main()
{
	int a[7] = { 12,5,3,5,98,21,7};
	sort(a,a+7,Rule1());
	Print(a,7);
	int *p = lower_bound(a,a + 7,5,Rule1());
	//cout<<*p<<","<<p - a<<endl;
	printf("%d,%d\n",*p,p - a);
	cout<<"result:"<<binary_search(a,a+7,8,Rule1())<<endl;
	//lower_bound ���ڵ���"ֵ"���±���󣬷���ָ�� �����Ӷ�log(n)
	//upper_bound ���ڵ���"ֵ"���±���󣬷���ָ�룬���Ӷ�log(n) 
	
	
	
	
	
	return 0;
} 
