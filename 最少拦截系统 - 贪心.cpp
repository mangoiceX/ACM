#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string> 
#include<cstring>
#include<set>
#define INF 0x7fffffff
using namespace std;
const int maxn = 100000 + 10;
int a[maxn];
int main(){
	int n = 0;
	while(cin >> n && n){
		for(int i = 1;i <= n;++i){
			cin >> a[i];
		}
		
		int ans = 1,i = 0,j = 0;
		for(i = 2;i <= n;++i){
			int flag = 1;
			for(j = 1;j <= ans;++j){//��i�׵ĵ�ǰ��Сֵ���ڵ�i��λ�� 
				if(a[i] < a[j]){		//�ҵ����ڵĵ���ϵͳ 
					a[j] = a[i];
					flag = 0;
					break;
				}
			}
			if(flag == 1){		//�Ҳ�������ϵͳ���½�һ�����ں����¼�һ������ϵͳ 
				a[j] = a[i];//j�Ѿ�++�����Բ�����j+1 
				ans++;
			}
		}
		cout << ans << endl; 
	}
	
	
	
	
	
	
	return 0;
} 
