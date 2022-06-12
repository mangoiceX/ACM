#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath> 

#define ESP 1e-6 

using namespace std;

int BinarySearch(int a[],int size,int p)//二分查找，复杂度O(log(n)) 
{
	int left = 0;//查找区间左端点
	int right = size - 1;//查找区间右端点 
	while(left <= right)
	{
		int middle = left + (right - left)/2;
		if(p == a[middle])
			return middle;
		else if(p > a[middle])
			left = middle + 1;
		else 
			right =middle - 1;
	 } 
	return -1;	
}
//从小到大的数组中，找出比p小的，下标最大的元素 
int LowerBound(int a[],int size,int p)
{
	int L = 0;
	int R = size - 1;
	int lastPos = -1;
	while(L < R)
	{
		int mid = L + (R - L)/2;//不用(mid=(R + L)),防止(L+R)过大溢出 
		if(p <= a[mid])
			R = mid - 1;
		else
		{
			lastPos = mid;
			L = mid + 1;
		}	
	}
	return lastPos;
 }  

double f(double x)
{
	return x*x*x - 5*x*x + 10*x - 80;
}


int main()
{
	double root = 0, x1 = 0,x2 = 10,y = 0;
	root = x1 + (x2 - x1)/2;
	int Triedtimes = 1;
	y = f(root);
	while(fabs(y) > ESP)
	{
		if(y > 0)
			x2 = root;
		else
			x1 = root;
		y = f(root);
		Triedtimes++;
	}
	printf("%.8f\n%d",root,Triedtimes);
	
	
	return 0;
}
