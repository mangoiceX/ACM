#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define INF 1e6
using namespace std;//�ύʱҪѡG++,ѡc++�ᳬʱ��֮ǰWA����ô��Σ��������ԭ����� 
int n = 0,t = 0;

int main(){
	int kase = 0;
	while(scanf("%d %d",&n,&t) != EOF && (n != -1 || t != -1)){
		int sum = 0,mod = n % 11;//mod�ĳ�ʼֵ 
		while(t--){
			while(n > 0){//����sum 
				sum += (n % 10);
				n /= 10;
			}
			int temp1 = sum,cnt = 1;
			n = sum;//����ӵ���sum 
			while(temp1 > 0){//����sum��λ�� 
				cnt *= 10;
				temp1 /= 10;
			}
			mod = (mod * cnt + sum) % 11;//�˴�mod11,���ƴ�С 
		}
		if(mod == 0){ 
			printf("Case #%d: Yes\n",++kase);
		}else{
			printf("Case #%d: No\n",++kase);
		}
	}
	return 0;
}
