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
		
	if(apple[1] == 1){//确定初始条件 
		dp[1][0] = 1;
		dp[1][1] = 0;// 这个初始条件不要漏掉了
	}else{
		dp[1][0] = 0;
		dp[1][1] = 1;//这个初始条件不要漏掉了 
	}
	
	for(int i = 2;i <= t;++i){//以时间为外重循环，因为一个时间对应唯一位置，而同一位置可以对应不同时间
	//两个状态：时间，步数 
		for(int j = 0;j <= w;++j){
			if(j == 0){			//j==0特殊处理 
				dp[i][j] = dp[i-1][j] + apple[i] % 2;
			}else{
				dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]);//j!=0 
				if( (apple[i] == 1 && j % 2 == 0)  || ( apple[i] == 2 && j % 2 == 1)){
					//判断当前的数是否有苹果fall，利用i的奇偶性 
					++dp[i][j];
				}
			}
				
		}
	}
	
	int maxv = 0;
	for(int j = 0;j <= w;++j){//最终状态是：时间是t，但步数不确定 
		maxv = max( maxv,dp[t][j]);
	}
	cout << maxv << endl;
	
	return 0;
} 
