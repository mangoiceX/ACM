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
LL n = 0,k = 0;

int main(){
	while(~scanf("%I64d %I64d",&n,&k)){
		LL x = (sqrt(9+8*(n+k)) - 3)/2;
		printf("%I64d\n",n-x);
	}

	return 0;
}