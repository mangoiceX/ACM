#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
int d[maxn],a[maxn];
int n = 0,k = 0;
void solve(){
	int cnt = 0;
	for(int i = a[n];i > a[1];--i){
		d[++cnt] = (a+n+1 - lower_bound(a+1,a+1+n,i)) ;//不要加1，否则多加了 
	}
	LL sum = 0,ans = 0;
	for(int i = 1;i <= cnt;++i){	
		if(sum + d[i] > k){
			ans++;
			sum = d[i];
		}else{
			sum += d[i];
		}
	}
	if(sum > 0){//结尾剩余的也要算一个 
		ans++;
	}
	printf("%I64d\n",ans);
}
int main(){
	while(~scanf("%d %d",&n,&k)){
		for(int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		solve();
	}
	
	return 0;
}

