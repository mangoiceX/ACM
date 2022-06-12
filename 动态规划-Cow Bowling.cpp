#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#define INF 0x7fffffff
using namespace std;
const int maxn = 350 + 10;
int data[maxn][maxn];
int dp[maxn];
int main(){
	
	int n = 0;
	scanf("%d",&n);
	memset(dp,0,sizeof(dp));
	memset(data,0,sizeof(data));
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= i;++j){
			scanf("%d",&data[i][j]);
		}
	}
	
	for(int i = n;i >= 1;--i){
		for(int j = 1;j <= i;++j){
			dp[j] = max(dp[j],dp[j+1]) + data[i][j];//×´Ì¬×ªÒÆ·½³Ì 
		}
	}
	
	printf("%d\n",dp[1]);
	
	
	return 0;
}
