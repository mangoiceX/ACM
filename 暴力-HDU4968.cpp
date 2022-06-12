#include<bits/stdc++.h>
// #include<iostream>
// #include<cstdio>
// #include<vector>
// #include<cstring>
using namespace std;
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
const int maxn = 2e5 + 10;
typedef long long LL;
int n = 0,m = 0;
double ave = 0.0;
void solve(){
	double minv = 4.0,maxv = 0.0;
	per(a,0,n){
		per(b,0,n-a){
			per(c,0,n-a-b){
				per(d,0,n-a-b-c){
					per(e,0,n-a-b-c-d){
						if(1.0*(85*a+80*b+75*c+70*d+60*e) <= ave * n && ave*n <= 1.0*(100*a+84*b+79*c+74*d+69*e)
							&& (a + b + c + d + e == n)){
							double score = a*4.0+3.5*b+c*3.0+d*2.5+e*2.0;
							minv = min(minv,score/n);
							maxv = max(maxv,score/n);
						}
					}
				}
			}
		}
	}
	printf("%.4lf %.4lf\n",minv,maxv);
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%lf %d",&ave,&n);
		solve();
	}

	return 0;
}