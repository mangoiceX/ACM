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
void solve(){
	double minv = 4.0;
	int i = 0;
	if(n == 1){
		if(m>= 85){
			minv = 4.0;
		}else if(m >= 80){
			minv = 3.5;
		}else if(m >= 75){
			minv = 3.0;
		}else if(m >= 70){
			minv = 2.5;
		}else{
			minv = 2.0;
		}
	}
	while(true){
		if(n-i < 0){
			break;
		}
		if(69 * (n-i) >= m*n-100*i && 60 * (n-i) <= m*n-100*i){
			minv = min(minv,(i*4.0+2.0*(n-i)) / n);
		}
		if(60 * (n-i) > m*n - 100*i){
			break;
		}
		++i;
		cout << "ji" <<endl;
	}
	i = 0;
	while(true){
		if(n-i < 0){
			break;
		}
		if(100 * (n-i) >= m*n-69*i && 85 * (n-i) <= m*n-69*i){
			minv = min(minv,(i*2.0+4.0*(n-i)) / n);
		}
		++i;
	}	
	printf("%.4lf\n",minv);

}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&m,&n);
		solve();
	}

	return 0;
}