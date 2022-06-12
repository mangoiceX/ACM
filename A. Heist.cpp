#include<bits/stdc++.h>
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 1e3 + 100;
typedef long long LL;
int a[maxn];
int n = 0;
int main(){
	while(~scanf("%d",&n)){
		for(int i = 0;i < n;++i){
			scanf("%d",&a[i]);
		}
		sort(a,a + n);
		LL ans = 0;
		for(int i = 1;i < n;++i){
			ans += (a[i] - a[i-1] - 1);
		}
		printf("%I64d\n",ans);
	}
	
	return 0;
} 
