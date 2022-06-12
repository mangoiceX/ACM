#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath> 

#define ESP 1e-6 

using namespace std;

int BinarySearch(int a[],int size,int p)//���ֲ��ң����Ӷ�O(log(n)) 
{
	int left = 0;//����������˵�
	int right = size - 1;//���������Ҷ˵� 
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
//��С����������У��ҳ���pС�ģ��±�����Ԫ�� 
int LowerBound(int a[],int size,int p)
{
	int L = 0;
	int R = size - 1;
	int lastPos = -1;
	while(L < R)
	{
		int mid = L + (R - L)/2;//����(mid=(R + L)),��ֹ(L+R)������� 
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
