#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e4 + 100;
LL dp[25][700][700];//dp[i][j][k]:i:数位,j表示左边的和，k表示目前右边的和
int d[25];
int pivot = 0; 
LL dfs(int pos,int l_sum,int r_sum,bool uplim,bool led){//注意前导0 
	if(pos <= 0){
		//cout << "mi " << l_sum << " " << r_sum << endl;
		return l_sum == r_sum;
	}
	
	if(!uplim && dp[pos][l_sum][r_sum] != -1){
		cout << " nimd" <<dp[pos][l_sum][r_sum] <<  endl;
		return dp[pos][l_sum][r_sum];
	}
	
	LL temp = 0;
	int up = uplim ? d[pos] : 9;
	for(int i = 0;i <= up;++i){
		LL l_sum_t = l_sum,r_sum_t = r_sum;
		///cout << "em " <<  pos << " " << pivot << endl;
		if(pos >= pivot){
			 l_sum_t = l_sum + i * (pos - pivot);
		}else{
			 r_sum_t = r_sum + i *(pivot - pos);
		}
		temp += dfs(pos-1,l_sum_t,r_sum_t,uplim && i == d[pos],led && i == 0);
	}
	if(!uplim){
		dp[pos][l_sum][r_sum] = temp;
	}
	return temp;
} 
LL solve(LL x){
	if(x <= 0){
		return 1;
	} 
	LL temp = x;
	int cnt = 0;
	while(temp > 0){
		d[++cnt] = temp % 10;
		temp /= 10;
	}
	d[cnt+1] = 0;
	pivot = cnt / 2 + 1;
	return dfs(cnt,0,0,true,true);
}
void init(){
	memset(dp,-1,sizeof(dp));
}
int main(){
	LL l = 0, r = 0 ;
	int T = 0;
	cin >> T;
	init();
	while(T--){
		cin >> l >> r;
		//cin >> r;
		//cout <<"mama " <<solve(r)  << endl;
		//cout <<  "ma" << solve(l) << endl;
		//cout << solve(r)  - solve(l) << endl;
	}
	
	
	return 0;
} 
