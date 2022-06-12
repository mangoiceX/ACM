#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

int pfcompare(const void *e1,const void *e2)
{
	int *p1,*p2;
	p1 = (int*)e1;
	p2 = (int*)e2;
	return *p1 < *p2 ?1:-1;
}

int main()
{
	//int str[10] ;
/*	memset(str,0,sizeof(str));//内存操作库函数 
	//cout<<str<<endl;//输出二进制 
	for(int i = 0;i < 10;i++)
		printf("%d",str[i]);//输出十进制 */ 
	int a[10] = {1,4,7,3,9,2,5,8,6,0};
	int e1,e2;
	int pfcompare(const void *e1,const void *e2);
	qsort(a,10,sizeof(int),pfcompare);
	for(int i = 0;i < 10;i++)
		printf("%d ",a[i]);
	return 0;	
} 
