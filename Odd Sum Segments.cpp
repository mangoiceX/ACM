#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
const LL mod = (1e9 + 7);
int n = 0,m = 0,k = 0;
int a[maxn];
void solve(){

}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);
		vector<int> ans;
		per(i,1,n){
			scanf("%d",&a[i]);
			if(a[i] & 1){
				ans.push_back(i);
			}
		}
		int size = ans.size();
		if(ans.size() < k){

			puts("NO");
		}else{
			int st = (k == 1) ? 1 : ans[k-2]+1;
			LL sum = 0;
			per(i,st,n){
				sum += a[i];
			}
			if(sum % 2== 0){
				puts("NO");
				continue;
			}
			puts("YES");
			if(k == 1){
				printf("%d\n",n);
				continue;
			}
			// int si = ans.size();
			printf("%d",ans[0]);
			per(i,1,k-2){
				printf(" %d",ans[i]);
			}
			printf(" %d",n);
			puts("");
		}
	}

	return 0;
}