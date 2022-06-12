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
//dp[i][j]表示从i-j的最大的括号匹配长度 ,每次找i的匹配，因为第i个最具全局性 
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
		for(int i = len - 2; i >= 0;--i){//从后往前遍历，因为后面的状态是容易确定的 
			for(int j = i+1;j < len;++j){//在i-j区间找匹配 
				dp[i][j] = dp[i+1][j];
				if(str[i] == '(' || str[i] == '['){//可能存在匹配 
					
					for(int k = i + 1;k <= j;++k){
						
						if(str[i] == '(' && str[k] == ')'){//区间i-j中，找到匹配 
						//状态转移方程中剔除i,k两点，然后在剩下的区间找 
							dp[i][j] = max( dp[i][j] , dp[i+1][k-1] + dp[k+1][j] + 2);
						}else if(str[i] == '[' && str[k] == ']'){
							dp[i][j] = max( dp[i][j] , dp[i+1][k-1] + dp[k+1][j] + 2);
						}
						//else{	//i-j中找不到匹配 
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
