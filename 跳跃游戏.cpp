/*��Ծ��Ϸ-̰��*/ 
#include<iostream>
#include<cstdio>

using namespace std; 
#define maxn 500 + 10

int main()
{
	int n,a[maxn];
	cin>>n;
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	int maxnium = 0; 
	for(int i = 0;i < n;i++)
	{
		if(i <= maxnium)//��ʾ�ܵ����λ��
			maxnium = max( maxnium , a[i] + i);//�������ܵ�������λ�� 
		else							//�������� 
			break;
	}
	if(maxnium >= n - 1)
		printf("true");
	else
		printf("false");
	
	return 0;
}
