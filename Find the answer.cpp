#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
int n = 0,m = 0,k = 0;
int a[maxn];
int gi(){
    char a=getchar();int b=0;
    while(a<'0'||a>'9')a=getchar();
    while(a>='0'&&a<='9')b=b*10+a-'0',a=getchar();
    return b;
}

int main(){
	int T = 0;
	// scanf("%d",&T);
	T = gi();
	while(T--){
		// scanf("%d %d",&n,&m);
		n = gi();m = gi();
		priority_queue<int> pq;
		priority_queue<int,vector<int>,greater<int> > pq2;
		LL sum = 0;
		int cnt = 0;
		int ans[maxn];
		per(i,1,n){
			// scanf("%d",&a[i]);
			a[i] = gi();
			sum += a[i];
			if(i > 1){
				pq.push(a[i-1]);
			} 
			while(sum <= m && !pq2.empty()){
				int u = pq2.top();
				pq2.pop();
				sum += u;
				pq.push(u);
				--cnt;
			}
			while(sum > m && !pq.empty()) {
				int u = pq.top();
				pq.pop();
				sum -= u;
				pq2.push(u);
				++cnt;
			}
			ans[i] = cnt;
		}
		// solve();
		per(i,1,n){
			printf("%d ",ans[i]);
		}
		puts("");
	}

	return 0;
}