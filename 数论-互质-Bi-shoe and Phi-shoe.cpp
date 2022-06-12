#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4,ma = 1e6;
typedef long long LL;
int a[maxn + 10];
int n = 0;
bool is_prime[ma+maxn+100];
int cnt = 0;
int prime[ma+10];
void ais(){
	fill(is_prime,is_prime+ma+maxn+100,true);
	is_prime[1] = false;
	//int m = maxn+1;
	int m = sqrt(ma + maxn + 0.5);//这里i*i不能爆int 
	for(int i = 2;i <= m;++i){
		if(is_prime[i]){
			for(int j = i * i;j <= maxn + ma;j += i){
				is_prime[j] = false;
			}
		}
	}
	cnt = 0;
	for(int i = 2;i <= ma+maxn;++i){
		if(is_prime[i]){
			prime[cnt++] = i;
		}
	}
}
int main(){
	int T = 0;
	ais();
	scanf("%d",&T);
	int kase = 0;
	while(T--){
		LL mi = 0;
		scanf("%d",&n);
		for(int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
			//cout << mi << endl; 
			mi += prime[lower_bound(prime,prime+cnt,a[i]+1) - prime];
			/*
			int tmp = a[i] + 1;
			while(true){
				if(is_prime[tmp]){
					mi += tmp;
					break;
				}
				++tmp;
			}
			*/
		} 
		printf("Case %d: %lld Xukha\n",++kase,mi);//I64d会WA 
	}
	return 0;
}
