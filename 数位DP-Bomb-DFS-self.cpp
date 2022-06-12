#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
LL dp[23][2];
int d[20];

void init(){
	memset(dp,-1,sizeof(dp));
}
LL dfs(int pos,int pre,int sta,bool lim){
	if(pos == 0){
		return 1;
	}
	if(!lim && dp[pos][sta] != -1){
		return dp[pos][sta];
	}
	LL temp = 0;
	int up = lim ? d[pos] : 9;
	for(int i = 0;i <= up;++i){
		if(pre == 4 && i == 9){
			continue;
		}
		temp += dfs(pos-1,i,i==4,lim && i == d[pos]);
	} 
	if(!lim){
		dp[pos][sta] = temp;
	}
	return temp;
}

LL solve(LL x){
	LL temp = x;
	int cnt = 0;
	while(temp > 0){
		d[++cnt] = temp % 10;
		temp /= 10;
	}
	d[cnt+1] = 0;
	return dfs(cnt,-1,0,true);
}
int main(){
	LL T = 0,n = 0;
	cin >> T;
	
	while(T--){
		init();
		cin >> n;
		cout << n - solve(n) + 1 << endl;//包含了0，所以要加1 
	}
	
	
	return 0;
} 
