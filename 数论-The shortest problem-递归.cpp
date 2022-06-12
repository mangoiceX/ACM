#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define INF 1e6
using namespace std;
int n = 0,t = 0;
int sum = 0,ans = 0,cnt = 0;
void solve(int x){
	if(x / 10 > 0){
		solve(x/10);
	}
	if(cnt % 2 == 0){
		ans += x % 10;
	}else{
		ans -= x % 10;
	}
	sum += x % 10;
	++cnt;
	return ;
}
int main(){
	int kase = 0;
	while(scanf("%d %d",&n,&t) != EOF && (n != -1 || t != -1)){
		ans = cnt = sum = 0;
		solve(n);
		ans %= 11;
		while(t--){
			solve(sum);
			ans %= 11;	
		}
		if(ans % 11 == 0){
			printf("Case #%d: Yes\n",++kase);
		}else{
			printf("Case #%d: No\n",++kase);
		}
	}
	
	
	return 0;
}
