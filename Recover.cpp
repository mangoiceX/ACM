#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
//#define fill(a,b) fill(a,a+sizeof(a),b)
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
typedef long long LL;
const double eps=1.0e-5;
const int maxn=2e6 + 10;
int n = 0; 
bool is_prime[maxn];
int prime[maxn];
int a[200000+10];
bool vis[maxn+10];
int ouler(){
	fill(is_prime,is_prime+maxn,true);
	fill(prime,prime+maxn,0);
	int cnt = 0;
	//int m = sqrt(n+0.5);
	per(i,2,maxn){
		if(is_prime[i]){
			prime[cnt++] = i;
		}
		for(int j = 0;j < cnt && i * prime[j] <= maxn;++j){
			is_prime[i * prime[j]] = false;
			if(i % prime[j] == 0){
				break;
			}
		}
	}
	return cnt;
} 
void solve(){
	vector<int> ans;
	memset(vis,false,sizeof(vis));
	per(i,1,2*n){
		if(is_prime[a[i]] && (*lower_bound(a+1,a+1+n,prime[a[i]]) == prime[a[i]])){
			ans.push_back(a[i]);
		}
		if(!prime[a[i]]){
			ans.push_back(a[i]*2);
		}
	}
	per(i,0,n-1){
		printf("%d%c",ans[i],i == (n-1) ? '\n' : ' ');
	}
}
int main(){
	ouler();
	while(~scanf("%d",&n)){
		per(i,1,2*n){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		solve();
	}
	
	return 0; 
}
