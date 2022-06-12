#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
typedef long long LL;
#define INF 1e18
const int maxn = 2e5 + 10;
int n = 0,m = 0; 
char a[60],b[60];
void solve(){
	int len1 = strlen(a),len2 = strlen(b);
	int p = len1 - 1;
	while(p >= 0 && a[p] == '0'){
		--p;
	}
	LL num1 = 0,num2 = 0;
	rep(i,p,0){
		num1 = num1*10 + (a[i] - '0');
	}
	p = len2 - 1;
	while(p >= 0 && b[p] == '0'){
		--p;
	}
	rep(i,p,0){
		num2 = num2*10 + (b[i] - '0');
	}
	LL num3 = num1 + num2;
	while(num3 % 10 == 0){
		num3 /= 10;
	}
	while(num3 > 0){
		printf("%lld",num3%10);
		num3 /= 10;
	}
	puts("");
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%s %s",a,b);
		solve();
	}

	return 0;
}