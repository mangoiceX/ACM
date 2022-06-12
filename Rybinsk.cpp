#include<bits/stdc++.h>
// #include<iostream>
// #include<cstdio>
// #include<vector>
// #include<cstring>
using namespace std;
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
const int maxn = 2e5 + 10;
#define INF 0x3f3f3f
typedef long long LL;
const LL mod = 998244353;
int n = 0,m = 0;
char s[20];
LL q_pow(int x,int y){
	LL res = 1;
	while(y > 0){
		if(y & 1){
			res = (res*x) % mod;
		}
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}
LL f(char* s){
	int len = strlen(s);
	LL res = 0;
	per(i,0,len-1){
		int id = len - 1 - i;
		res = (res + (s[i] - '0')*q_pow(10,id*2+1)) % mod;
		res = (res + (s[i] - '0')*q_pow(10,id*2)) % mod;
	}
	res = (res * n) % mod;
	return res;
}
int main(){
	while(~scanf("%d",&n)){
		LL ans = 0;
		per(i,1,n){
			scanf("%s",s);
			ans = (ans + f(s) ) % mod;
		}
		printf("%I64d\n",ans);
	}

	return 0;
}