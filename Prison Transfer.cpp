#include<iostream> 
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<queue>
using namespace std;
typedef unsigned long long LL; 
const int maxn = 200000 + 10;
int n = 0,c = 0;
LL t = 0;
int ans = 0;
LL data[maxn];
int main(){
	
	while(scanf("%d %lld %d ",&n,&t, &c) != EOF){
	
	
	for(int i = 0;i < n;++i){
		scanf("%lld",&data[i]);
	}
	int loc = 0,flag = 1;
	int i = 0,j = 0,restart = 1;
	for( i = 0;i <= n - c;++i){
		flag = 1;
		if(restart == 1){		//���¿�ʼ���� 
			for( j = i;j < i + c;++j){
				
				if(data[j] > t){
					flag = 0;
					loc = j;	//��¼�����λ�� 
					break;
				}
			}
			if(flag == 1 ){	//û�г���ĵ�
				++ans;
				restart = 0;	//��һ��ֻ�ÿ���һ�� λ�ü��� 
			}else{						//�г���ģ��Ӹ�λ�õ���һ��λ�����¿�ʼ���� 
				i = loc;//ע��i++���1 
				restart = 1;
			}
			
		}else{
			--i;
			if(data[i + c] <= t){
				flag = 1;
				restart = 0;
			}else{
				flag = 0;
			}
			if(flag == 1){
				++ans;
				++i;
			}else{
				loc = i + c;
				i = loc;
			}
		}	
	}
	printf("%d\n",ans);
}
	return 0;
}

