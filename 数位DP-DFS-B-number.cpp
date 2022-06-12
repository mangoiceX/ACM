#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[23][13][3];//需要3个状态量才能确定唯一一个状态 ,去掉中间的状态量res，会出现重复，打表观察 
int d[15];

int dfs(int pos,int res,int have,bool lim){
	if(pos == 0){
	//	if(res == 0 && have == 2){
	//		cout << "nihao" << endl;
	//	}
		return res == 0 && have == 2;
	}
	
	if(!lim && dp[pos][res][have] != -1){
		return dp[pos][res][have];
	}
	
	int temp = 0;
	int up = lim ? d[pos] : 9;
	for(int i = 0;i <= up;++i){
		int res_t = (res*10 + i) % 13,have_t = have;
		if(have == 0 && i== 1){
			have_t = 1;
		}
		if(have == 1 && i == 3){
			have_t = 2;
		//	cout << "en " << pos-1 << " " << res_t  << " " << have_t<< endl;
		}
		if(have == 1 && i != 1 && i != 3){//
			have_t = 0;
		}
		temp += dfs(pos - 1,res_t,have_t,lim && i == d[pos]);
	}
	if(!lim){
		dp[pos][res][have] = temp;
	}
	return temp;
}
int solve(int x){
	int temp = x;
	int cnt = 0;
	while(temp > 0){
		d[++cnt] = temp % 10;
		temp /= 10;
	}
	d[cnt+1] = 0;
	return dfs(cnt,0,0,true);
}
void init(){
	memset(dp,-1,sizeof(dp));
}
int main(){
	int n = 0;
	while(cin >> n){
		init();
		cout << solve(n) << endl;	
	}
	
	return 0;
}
