#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#define INF 1e6
using namespace std;
const int maxn = 100 + 10;

int dp[maxn][1200];
//dp[i][j]��ʾ����ѡ��i��devices����С�����jʱ����С����
//���������໥��Լ�������̶�i���䣬̰����j��Ҳ��������һ��ʱ�����ѵ���Сֵ 
int main(){
	
	int T = 0,q = 0,num = 0,b = 0,p = 0;
	//cin >> T;
	scanf("%d",&T);
	while(T--){
		fill(dp[0],dp[0] + maxn*1200,INF);
		scanf("%d",&q);
		for(int i = 1;i <= q;++i){	
			//cin >> num;
			scanf("%d",&num);
			for(int j = 1;j <= num;++j){
				//cin >> b >> p;
				scanf("%d %d",&b,&p);
				if(i == 1){
					dp[i][b] = min(dp[i][b],p);
				}else{
					for(int k = 0;k < 1200;++k){//Ѱ����������¼����� 
						
						if(dp[i-1][k] != INF){//����ÿ���������ѡ��ǰ��device
						//���ǣ�������Ŀ����ͬʱ��Ҫ�Ƚ� ��ѡ��Сֵ 
							if(b >= k){
								dp[i][k] = min( dp[i-1][k] + p,dp[i][k]);
							}else{
								dp[i][b] = min( dp[i-1][k] + p,dp[i][b]);
							}
						}
						
					}	
				}
				
			}
		}	
		double ans = 0;
		for(int j = 0;j < 1200;++j){
			if(dp[q][j] != INF){
				ans = max(double(j)/dp[q][j],ans);
			}
			
		}	
		printf("%.3lf\n",ans);
		//cout << ans << endl;
	}
	
	return 0;
}
