#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 2000 + 10;
int dp[maxn][maxn];
int cost[maxn];
int n = 0,m = 0;
string str1;
char str2;

int main(){
	int a = 0,d = 0;
	cin >> n >> m;
	cin >> str1;
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= n;++i){
		cin >> str2 >> a >> d;
		cost[str2 - 'a'] = min(a,d);
	}
	/*
	//首先是状态建立，dp[i][j]表示的是从j到i区间的最小转化代价 
	for(int i  = 1;i < m;++i){
		for(int j = i - 1;j >= 0;--j){
			
			dp[i][j] = min( dp[i-1][j] + cost[str1[i] - 'a'] , dp[i][j+1] + cost[str1[j]-'a']);
			
			if(str1[i] == str1[j]){
				dp[i][j] = min( dp[i][j] , dp[i-1][j+1]);
			}
		}
	}
	*/
	//dp[i][j]表示的是从i到j区间的最小转化代价 
	for(int len = 2;len <= m;++len){
		for(int i = 0;i < m-len + 1;++i){
			int j = i + len - 1;
			dp[i][j] = min( dp[i+1][j] + cost[str1[i] - 'a'] , dp[i][j-1] + cost[str1[j]-'a']);
			if(str1[i] == str1[j]){
				dp[i][j] = min( dp[i][j] , dp[i+1][j-1]);
			}
		}
	} 
	cout << dp[0][m-1] << endl;
	
	//cout << dp[m-1][0] << endl;
	return 0;
}

