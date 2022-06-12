#include<bits/stdc++.h>
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 1e5 + 100;
typedef long long LL;
int n = 0,m = 0;
int a[maxn];
int main(){
	while(~scanf("%d %d",&n,&m)){
		int minv = INF;
		int maxv = 0;
		for(int i = 0;i < n;++i){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		maxv = a[n-1];minv = a[0];
		int ans1 = 0;
		int res = m % n;
		
		int temp = m;
		int sum = 0;
		for(int i = 0;i < n-1;++i){
			sum += (a[n-1] - a[i]);
		}
		
		if(m % n > 0){
			printf("%d ",m/n+1+maxv);
		}else{
			printf("%d ",m/n + maxv);
		}
		printf("%d\n",maxv + temp);
	}
	
	return 0;
} 
