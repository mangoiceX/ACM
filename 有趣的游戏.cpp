#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f
const int maxn = 1e4;
int a[maxn+10];
int n = 0;
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		LL sum = 0;
		int minv = INF;
		for(int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
			sum += a[i];
			minv = min(minv,a[i]);
		}
		printf("%lld\n",sum - minv*n);//这里不能用%I64d,会PE 
	}
	
	return 0;
}
