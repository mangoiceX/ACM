#include<bits/stdc++.h>
using namespace std;
typedef long long LL;//���ֿ����Ҽ����򵥵����ӣ��������� 
const int maxn = 5e5 + 100;//Ѱ�Ҳ���Ĺ��ɣ������Ͽ������ܸ��ӣ�ץס����ı��ʾͺܼ��� 
int a[maxn];
/*
��min���ϼ�ȥ���ڵ�+����max���ϼ�ȥ���ڵ�-��������ֵ����max_sum 
��������������ֵ����Сֵ��ȷ���ģ�max�Ǽӣ�min�Ǽ���Ȼ�������м��������ȫ��-������max��ȥ���ǣ�
//��ȫ��+������min��ȥ���ǣ�����-��+�����������-��ȥ���ڵ�+ 
*/ 
int n = 0;//
int main(){
	while(scanf("%d",&n) != EOF){
		for(int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
		}
		if(n == 1){
			printf("%d\n",a[1]);
			continue; 
		}
		sort(a + 1,a + 1 + n);//���� 
		LL sum = 0;
		sum += a[n];//���ֵ�϶������ 
		sum -= a[1];//��Сֵ����� 
		for(int i = 2;i <= n - 1;++i){//�����ľ���ȡ����ֵ 
			sum += abs(a[i]);
		}
		printf("%I64d\n",sum);
	}

	return 0;
} 
