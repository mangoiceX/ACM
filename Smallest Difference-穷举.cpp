#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
const int maxn = 12;
int n = 0,ans = 0;
char str[30];
int data[maxn];

void solve(){
	if(n == 2){
		ans = data[1] - data[0];
		printf("%d\n",ans);
		return ;
	}
	
	while(data[0] == 0){//��֤��ͷ��������0 
	//����next_permutation()�ǰ����ֵ���������еģ�
	//�����Ǵ������е�ǰ���ֵ���ʼ��������ֱ��������ֵ��� 
		next_permutation(data,data + n);//�Ȱѿ�ͷ��0�ģ������ 
	}
	ans = INF;
	
	do{
		int mid = (n + 1)/2;//�м����
		if(data[mid] != 0){
			int a = 0,b = 0; 
			for(int i = 0;i < mid;++i){	//n������ʱ��a��λ����һλ 
				a = a * 10 + data[i];
			}
			for(int i = mid;i < n;++i){
				b = b * 10 + data[i];
			}
			ans = min(ans,abs(a-b));
		} 
		
	}while(next_permutation(data,data + n));
	
	printf("%d\n",ans);
}

int main(){
	int t= 0;
	//cin >> t;//cin��getchar(),gets(),����һ��ʹ�� 
	scanf("%d",&t);
	getchar();
	while(t--){
		gets(str); //�˴�Ҫ��gets��ȡһ�У���������cin ȥ�� 
		int len = strlen(str);
		for(int i = 0;i < len;++i){
			if(str[i] >= '0' && str[i] <= '9'){
				data[n++] = str[i] - '0';//n���������ĸ��� 
			}
		}
		solve();
	}	
	return 0;	
} 
