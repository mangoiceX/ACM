#include<iostream> 
#include<cstdio>
#include<cmath>
bool vis[10000005];
int sums(int x,int y){
	int sum=0;
	int m=(int)sqrt(y+0.5);//������ʱ����磬��������һ��
	for(int i=2;i<=m;i++)
		for(int j=x/i/i;j*i*i<=y;j++)//ע�⣬j��x���׶ˣ�/i/i��ʼ,����x/(i^2)�������Ǽ����һ�������׶˵ĺ�i^2���ӵ�������i^2�ļ���
			if(j*i*i>=x)//����Ϊ������ȡ����Ե����Ϊ�˱��գ����ж�һ�Σ���Ϊһ�������ڸ�����������Ķ��ˣ��ͻ����ظ�������
				vis[j*i*i%(y-x+1)+1]=1;//mod���ȣ�ע�ⲻ�ܼ�ȥ����Ϊ����ɸ����������д�����
	for(int i=1;i<=y-x+1;i++)
		if(!vis[i])
			sum++;//��û�б����£�ɸ��������
	return sum;
}
int main(){
	int n = 0,m = 0;
	scanf("%d%d",&n,&m);
	printf("%d",sums(n,m));//�������
}

