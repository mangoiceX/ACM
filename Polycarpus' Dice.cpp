#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
int d[maxn];

int main(){
	LL n = 0,sum = 0;
	while(scanf("%I64d %I64d",&n,&sum) != EOF){
		LL sub_sum = 0;
		for(int i = 1;i <= n;++i){
			scanf("%d",&d[i]);
			sub_sum += d[i];
		}
		for(int i = 1;i <= n;++i){
			LL cnt = 0;
			LL minv = n - 1,maxv = sub_sum - d[i];
			LL l = sum - maxv;//×îÐ¡Öµ 
			LL r = sum - minv;//
			if(l > 0){
				cnt += l - 1;
			}
			if(r < d[i]){
				cnt += d[i] - r;
			}
			printf("%I64d ",cnt);
		}
		printf("\n");
	}
	
	return 0;
} 
