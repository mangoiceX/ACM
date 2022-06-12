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
	Triple data[MAX+1];  //����Ԫ��Ԫ���data��0��δ�� 
	int mu,nu,tu;
}TSMatrix;
status TransposeSMatrix(TSMatrix &M,TSMatrix *T)
{
	T->mu=M.nu,T->nu=M.mu,T->tu=M.tu;
	int col;
	if(T->tu > 0){									//�����ô�����˳��أ� 
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
	printf("��������Ԫ������������������Լ�����Ԫ�ظ�����\n");
	scanf("%d%d%d",&M->mu,&M->nu,&M->tu);
	printf("�밴�������˳���������Ԫ�ص��кš��кš�����Ԫ�ص�ֵ��\n");
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
	printf("�ַ�����ת�������\n");
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

