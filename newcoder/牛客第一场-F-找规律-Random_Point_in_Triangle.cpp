#include<bits/stdc++.h>
// #include<iostream>
// #include<cstdio>
// #include<vector>
// #include<cstring>x
using namespace std;
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
typedef long long LL;
const int maxn = 2e5 + 10;
const LL mod = (1e9 + 7);
#define INF 0x3f3f3f
typedef long long LL;

LL x1,x2,x3,y,y2,y3;

int main(){
	while(~scanf("%lld %lld %lld %lld %lld %lld",&x1,&y,&x2,&y2,&x3,&y3)){
		LL s = 11*labs(x1*y2 + x2*y3 + x3*y - x3*y2 - x2*y - x1*y3);
		printf("%lld\n",s);
	}
	return 0;
}