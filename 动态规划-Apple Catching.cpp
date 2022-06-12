#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1000 + 10;
int dp[maxn][35];
int apple[maxn];

int main(){
	int t = 0,w = 0;
	cin >> t >> w;
	for(int i = 1;i <= t;++i){
		cin >> apple[i] ;
	}
		
	if(apple[1] == 1){//ȷ����ʼ���� 
		dp[1][0] = 1;
		dp[1][1] = 0;// �����ʼ������Ҫ©����
	}else{
		dp[1][0] = 0;
		dp[1][1] = 1;//�����ʼ������Ҫ©���� 
	}
	
	for(int i = 2;i <= t;++i){//��ʱ��Ϊ����ѭ������Ϊһ��ʱ���ӦΨһλ�ã���ͬһλ�ÿ��Զ�Ӧ��ͬʱ��
	//����״̬��ʱ�䣬���� 
		for(int j = 0;j <= w;++j){
			if(j == 0){			//j==0���⴦�� 
				dp[i][j] = dp[i-1][j] + apple[i] % 2;
			}else{
				dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]);//j!=0 
				if( (apple[i] == 1 && j % 2 == 0)  || ( apple[i] == 2 && j % 2 == 1)){
					//�жϵ�ǰ�����Ƿ���ƻ��fall������i����ż�� 
					++dp[i][j];
				}
			}
				
		}
	}
	
	int maxv = 0;
	for(int j = 0;j <= w;++j){//����״̬�ǣ�ʱ����t����������ȷ�� 
		maxv = max( maxv,dp[t][j]);
	}
	cout << maxv << endl;
	
	return 0;
} 
