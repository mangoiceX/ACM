#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define MAX 100
using namespace std;
typedef int status;
typedef struct{
	int i,j;
	int e;
}Triple;
typedef struct{
	Triple data[MAX+1];  //非零元三元组表，data【0】未用 
	int mu,nu,tu;
}TSMatrix;
status TransposeSMatrix(TSMatrix &M,TSMatrix *T)
{
	T->mu=M.nu,T->nu=M.mu,T->tu=M.tu;
	int col;
	if(T->tu > 0){									//这个怎么进行退出呢？ 
		int q=1;
		for(col=1;col<=M.nu;++col)
			for(int p=1;p<=M.mu;++p)
			if(M.data[p].j == col){
			//	int temp = T->data[q].i;
				T->data[q].i=M.data[p].j;	T->data[q].j=M.data[p].i;
				T->data[q].e=M.data[p].e;   ++q;
			}
	}
	printf("OK!\n");
}
status input(TSMatrix *M)
{
	printf("请输入三元数组的行数，列数，以及非零元素个数：\n");
	scanf("%d%d%d",&M->mu,&M->nu,&M->tu);
	printf("请按行排序的顺序输入非零元素的行号、列号、非零元素的值：\n");
	int p=1;
	int i;
	for(i=1;i<=M->tu;i++)
	{
		scanf("%d %d %d",&M->data[p].i,&M->data[p].j,&M->data[p].e);
		p++;
		printf("\n");
	}
	//cout  << "jijij" << endl;
	if(i==M->tu+1)  return 1;
	else {
		//cout << "ppp" << endl;
		exit(1);
	}
}
status output(TSMatrix *M)
{
	printf("字符串的转置输出：\n");
	int p=1;
	int i;
	for(i=1;i<=M->tu;i++)
	{
		printf("%d %d %d",M->data[p].i,M->data[p].j,M->data[p].e);
		p++;
		printf("\n");
	}
	//cout << "nianm" << endl;
	if(i==M->tu+1)  return 1;
	else exit(1);
}
int main()
{
	freopen("a.txt","r",stdin); 
	TSMatrix M;
	TSMatrix T;
	input(&M);
	TransposeSMatrix(M,&T);
	cout << "haha" << endl;
	output(&T);
	getchar();
	return 0;
 } 

