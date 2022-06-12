#include<bits/stdc++.h>
// #include<iostream>
// #include<cstdio>
// #include<vector>
// #include<cstring>
using namespace std;
#define per(i,a,b) for(int  i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
const int maxn = 2e5 + 10;
typedef long long LL;
int n = 0,m = 0;
double v1 = 0,v2 = 0,r = 0,d = 0;
int main(){
	int T = 0;
	scanf("%d",&T);	
	while(T--){
		scanf("%lf %lf %lf %lf",&v1,&v2,&r,&d);
		double s = r*v2/v1*asin(v1/v2);
		if(s <= d){
			puts("Wake up to code");
		}else{
			puts("Why give up treatment");
		}
	}

	return 0;
}