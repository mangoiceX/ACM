#include<bits/stdc++.h>
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 1e5 + 100;
typedef long long LL;
int n = 0,m = 0;
int a[maxn];
int main(){
	while(~scanf("%d %d",&n,&m)){
		for(int i = 0;i < n;++i){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		int tmp = m;
		for(int i = 0;i < n-1;++i){
			//sum += (a[n-1] - a[i]);
			tmp -= (a[n-1] - a[i]);
		}
		if(tmp < 0){
			printf("%d ",a[n-1]);
		}else{
			if(tmp % n > 0){
				printf("%d ",a[n-1]+tmp/n + 1);
			}else{
				printf("%d ",a[n-1]+tmp/n);
			}
		}
		printf("%d\n",a[n-1] + m);
	}
	
	return 0;
} 
