#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#define INF 0x7f
using namespace std;
const int maxn = 200 + 10;

int dp[maxn][maxn];
int sum[maxn];

int main(){
	int n = 0,x = 0;
	while(scanf("%d",&n) != EOF){
		//memset(dp,INF,sizeof(dp));//ʹ��memset��ʼ�������0x3f���ԣ���0x3ff���治ֹһ��fʱ������
		//���Խ����ֶ���ʼ�� 
		for(int i = 0;i < maxn;++i){//dp����Ҫ��ʼ��Ϊ����� 
			for(int j = 0;j < maxn;++j){
				dp[i][j] = 100000;
			}
		}
		memset(sum,0,sizeof(sum));
		for(int i = 1;i <= n;++i){
			scanf("%d",&x);
			sum[i] = sum[i-1] + x;
			dp[i][i] = 0;//
		}
		
		for(int len = 2;len <= n;++len){
			for(int i = 1;i <= n;++i){
				int j = len + i - 1;
				if(j > n){			//�յ�Խ�� 
					break;
				}
				for(int k = i;k < j;++k){//״̬ת�Ʒ��̣�����������Ž�֮�� 
					dp[i][j] = min( dp[i][j] , dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1]);
				}
			}
		}	
		printf("%d\n",dp[1][n]);
		
	}
	
	return 0;
} 
