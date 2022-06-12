//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long LL;
int main(){
	int kase = 0;
	LL n = 0,k = 0;
	while(~scanf("%lld %lld",&n,&k)){
		cout << (k - (3*n-3)) << endl;
		if(n == 2){
			printf("Case #%d: %lld\n",++kase,k%2 == 0 ? 2 : 1);
			continue;
		}
		if(k <= n){
			printf("Case #%d: %lld\n",++kase,k);
		}else if(k <= 2*n-1){
			printf("Case #%d: %lld\n",++kase,k-n);
		}else if(k <= 3*n-3){
			printf("Case #%d: %lld\n",++kase,k-2*n+1);
		}else{
			k -= (3*n-3);
			int times = ceil(k*1.0 / (n-1));
			k %= (n-1);
//			cout << k << endl;
			if(k == 1){
				printf("Case #%d: %lld\n",++kase,times%2 == 1 ? n : (n-1));
			}else{
				printf("Case #%d: %lld\n",++kase,(int(k-1) > 0) ? k-1 : n-2);
			}
		}
	}

	return 0;
}