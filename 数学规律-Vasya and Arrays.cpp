#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;//���ֱ���ƭ�ˣ�ģ�⺦���� 
int n = 0,m = 0;
int a[maxn],b[maxn];
int main(){
	LL sum1 = 0,sum2 = 0;
	scanf("%d",&n);
	for(int i = 1;i <= n;++i){
		scanf("%d",&a[i]);
		sum1 += a[i];
	}
	scanf("%d",&m);
	for(int i = 1;i <= m;++i){
		scanf("%d",&b[i]);
		sum2 += b[i];
	}
	if(sum1 != sum2){
		printf("-1\n");
		return 0;
	}
	int j = 1,cnt = 0;
	sum1 = 0,sum2 = 0;
	for(int i = 1;i <= n;++i){//�����һ�����еĺ�С�ڵڶ���ʱ��forѭ���ǵĵ�һ��һֱ�� 
		sum1 += a[i];
		while(sum2 < sum1){//��һ�����еĺʹ��ڵڶ���ʱ���ڶ���һֱ�� 
			sum2 += b[j++];
		}
		if(sum2 == sum1){//��Ⱦͼ�����һ��������Ϊ0 
			sum1 = sum2 = 0;
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}

