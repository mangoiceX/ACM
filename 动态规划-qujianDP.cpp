#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string> 
#include<cstring>
#include<set>
#define INF 0x7fffffff
using namespace std;
const int maxn = 100+ 10;

string str;
//char str[maxn];
int dp[maxn][maxn];
//dp[i][j]��ʾ��i-j����������ƥ�䳤�� ,ÿ����i��ƥ�䣬��Ϊ��i�����ȫ���� 
int main(){
	
	//while(scanf("%s",&str) != EOF){
	while(cin >> str){
	//while(scanf("%s",str+1)!=EOF){
		//if(str[1] == 'e'){
		if(str[0] == 'e'){
			break;
		}
		int len = str.size();
		//int len = strlen(str+1);
		//cout << len ;
		memset(dp,0,sizeof(dp));
		for(int i = len - 2; i >= 0;--i){//�Ӻ���ǰ��������Ϊ�����״̬������ȷ���� 
			for(int j = i+1;j < len;++j){//��i-j������ƥ�� 
				dp[i][j] = dp[i+1][j];
				if(str[i] == '(' || str[i] == '['){//���ܴ���ƥ�� 
					
					for(int k = i + 1;k <= j;++k){
						
						if(str[i] == '(' && str[k] == ')'){//����i-j�У��ҵ�ƥ�� 
						//״̬ת�Ʒ������޳�i,k���㣬Ȼ����ʣ�µ������� 
							dp[i][j] = max( dp[i][j] , dp[i+1][k-1] + dp[k+1][j] + 2);
						}else if(str[i] == '[' && str[k] == ']'){
							dp[i][j] = max( dp[i][j] , dp[i+1][k-1] + dp[k+1][j] + 2);
						}
						//else{	//i-j���Ҳ���ƥ�� 
						//	dp[i][j] = dp[i+1][j];
						//}
						
					}
				}
			}
		}
		cout << dp[1][2] << " "<<dp[1][3] << " " << dp[0][2] << " " << dp[0][3] << endl;
		printf("%d\n",dp[0][len - 1]);
	}
	
	
	
	
	return 0;
} 
