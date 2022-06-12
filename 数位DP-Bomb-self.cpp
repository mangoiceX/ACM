#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const int maxn = 10;
LL dp[23][3];//dp[i][0]:i位数中不含"49"的个数，dp[i][1]：以9开头的个数，dp[i][2]:i位数中含"49"的个数
//之前int dp，WA，后面 的改为LL对了 
void init(){
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1;i <= 22;++i){
		dp[i][0] = dp[i-1][0] * 10 - dp[i-1][1];
		dp[i][1] = dp[i-1][0];
		dp[i][2] = dp[i-1][2] * 10 + dp[i-1][1];
	}
}

LL solve(LL x){
	LL temp = x;
	int digit[23];
	memset(digit,0,sizeof(digit));
	int cnt = 0;
	while(temp > 0){
		digit[++cnt] = temp % 10;
		temp /= 10;
	}
	digit[cnt+1] = 0;
	bool flag = false;
	LL ans = 0;
	for(int i = cnt;i >= 1;--i){
		ans += digit[i] * dp[i-1][2];
		if(flag == true){
			ans += digit[i] * dp[i-1][0];
		}else{
			if(digit[i] > 4){
				ans += dp[i-1][1];
			}
			//if(digit[i+1] == 4 && digit[i] > 9){//必须是大于号 
			//	ans += dp[i][1] ;
			//}
		}
		if(digit[i+1] == 4 && digit[i] == 9){
			flag = true;
		}
	}
	//if(flag == true){
//		++ans;
//	}
	return ans;
}
int main(){
	
	int T = 0;
	cin >> T;
	LL n = 0;
	init();
	while(T--){
		cin >> n;
		cout << solve(n+1) << endl;
	}
	return 0;
} 
