#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
typedef long long LL;
int fa[maxn];//�洢a������
LL a = 0,b = 0;
LL solve(LL part,LL sum){
	int cnt = 0;
	for(LL i = 1;i * i <= part;++i){//����part������(С��sqrt(n)������)��
										//����sqrt(n)������,���ظ����� 
		if(part % i == 0){
			fa[++cnt] = i;
		}
	}
	LL ans = 2*sum + 2;//���ó�ʼֵ 
	for(LL i = 1;i * i <= sum;++i){
		if(sum % i == 0){
			LL size = 1; 
			while(fa[size] <= i && size <= cnt){//part��sum�϶̵ı�����Ĺ�ϵ 
				if(part/fa[size] <= sum/i){//part��sum�ϳ��ı� ��Ĺ�ϵ 
					ans = min(ans,2*(i + sum/i));
					//++size; //����if���棬Ҫ��Ȼ������ѭ�� �����Ǵ��Ĵ��� 
				}
				++size;
			}
		}
	}
	return ans;
}
int main(){
	while(scanf("%I64d %I64d",&a,&b) != EOF){
		LL ans = min(solve(a,a+b),solve(b,a+b));//�ֱ�ö��a,b��С���ε���� 
		printf("%I64d\n",ans); 
	}
	
	return 0;
} 
