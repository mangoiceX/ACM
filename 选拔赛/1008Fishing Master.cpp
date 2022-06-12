#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;
int n = 0,m = 0,q = 0,k = 0;
int a[maxn];
// bool cmp(int x,int y){
// 	return x > y;
// }
void solve(){
	priority_queue<LL> pq;
	int yu[maxn];//记录余数
	LL ans = k;
	int res = 1;
	rep(i,n,1){
		--res;
		if(i == 1){
			ans += a[i];
			break;
		}
		yu[i] = a[i] % k;//剩余的时间
		res += a[i] / k;//煮鱼的时候，抓的鱼
		ans += a[i];//先贪心全都等
		if(res == 0){//如果下一条还没有没有抓住
			if(pq.empty()){//重新抓
				ans -= a[i];
				ans += k;
				res += 1;
			}else{
				if(k - pq.top() < k - yu[i]){//之前就抓浪费的时间<= 现在才抓浪费的时间
					ans -=  pq.top();
					pq.pop();
					ans += k;
					// ans += a[i];
					pq.push(yu[i]);
					res += 1;
				}else{
					ans -= a[i];
					ans += k;
					res += 1;
				}
			}
		}else{
			pq.push(yu[i]);
		}
	}
	printf("%lld\n",ans);
}
int main(){
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		solve();	
	}

	return 0;
}
