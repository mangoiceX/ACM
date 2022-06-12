#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#define INF 0x7fffffff
using namespace std;
const int maxn = 2002 + 10;

int dp[maxn][maxn];
int sum[maxn][maxn],mark[maxn][maxn];
int data[maxn];
//dp[i][j]��ʾ��i�����ӵ���j��������ʶ���ܴ���
//mark[i][j]��ʾ��С�ָ�㴦��kֵ  �����ı��μ���
//sum[i][j]i��j�����ܺ�

int main(){
	int n = 0;
	while(scanf("%d",&n) != EOF && n){
		
		for(int i = 1;i <= n;++i){
			 scanf("%d",&data[i]);
			 data[i+n] = data[i];//2*n������ת��Ϊ���� 
		}
		
		for(int i = 1;i < 2 * n;++i){		//��ʼ�� 
			dp[i][i] = 0;
			mark[i][i] = i;
			for(int j = i;j <= i + n;++j){
				sum[i][j] = sum[i][j-1] + data[j];
			}
		}
		
		for(int len = 2;len <= n;++len){//���䳤�� 
			for(int i = 1;i + len <= 2*n+1;++i){
			//���ҲҪ�Ӻ���һ�ο�ʼ�����������ظ����� �����Ǻ����mark[i][j]Ҫ�õ�i>n��ʱ��
			//���� �ظ�������Ϊ����������mark 
				int j = len + i - 1;
				dp[i][j] = INF;
				for(int k = mark[i][j-1];k <= mark[i+1][j];++k){
					int temp = dp[i][k] + dp[k+1][j] + sum[i][j]; //״̬ת�Ʒ��� 
					if(temp < dp[i][j]){
						dp[i][j] = temp;
						mark[i][j] = k;
					}
				} 
			}
		}
		
		int ans = INF;
		for(int i = 1;i <= n;++i){
			ans = min( ans , dp[i][i+n-1]);//������ͬ����� 
		}
		printf("%d\n",ans);
	}
	
	
	
	
	return 0;
}
