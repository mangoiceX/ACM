/*STL-Standard Template Library,��׼ģ���-sort�����㷨sort*/
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

struct Rule1
{
	bool operator()( const int &a1,const int & a2)
	{
		return a1 > a2;
	}
};

int main()
{
	int a[7] = {15,4,3,9,7,2,6}; 
	//sort(a,a+7);
	//sort(a,a+7,greater<int>());
	sort(a,a + sizeof(a)/sizeof(int),Rule1());
	for(int i = 0;i < 7;i++)
		//printf("%d ",a[i]);
		cout<<a[i]<<" ";
	
	return 0;
 } 
