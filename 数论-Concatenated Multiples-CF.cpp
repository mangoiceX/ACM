#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
map<LL,LL> mp[11];//�����άmap 
int n = 0,k = 0;
LL a[maxn];
int main(){
	while(scanf("%d %d",&n,&k) != EOF){
		//mp.clear();
		for(int i = 0;i < 11;++i){//ע��Ҫ���ÿ��һά��map 
			mp[i].clear();
		}
		for(int i = 1;i <= n;++i){
			scanf("%I64d",&a[i]);
			LL x = a[i];
			for(int j = 1;j <= 10;++j){//Ԥ����ÿ�����ֱ������ƶ�jλmod k ��������
										//�������ֱ�Ӳ��� 
				x *= 10;
				x %= k;
				++mp[j][x];
			}
		}
		LL sum = 0;
		for(int i = 1;i <= n;++i){
			LL t = a[i] % k;
			int len = log10(a[i]) + 1;//�����������λ(Ҳ��������������������ʱ���������ƶ���λ��) 
			sum += mp[len][(k - t) % k];//�����ƶ�lenλ��������t���� 
			LL x = 1;
			for(int j = 1;j <= len;++j){//�ų��Ǳ������� 
				x = (x * 10) % k;
			}
			if(((a[i] * x)%k + a[i]%k)%k == 0){
				--sum;
			}
		}
		printf("%I64d\n",sum);
	}
	
	return 0;
}
