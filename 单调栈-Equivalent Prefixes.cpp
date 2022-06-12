#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

#define pii pair<int, int>
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,a,b) for(int i=(a);i>=(b);i--)
#define pi acos(-1.0)
#define INF 0x3f3f3f3f
typedef long long LL;

const double eps=1.0e-5;
const int maxn=5e5 + 10;
const LL mod=1e9+7;

int n = 0,m = 0;
int a[maxn],b[maxn];
int st1[maxn],st2[maxn];
void solve(){
	int head1 = 1,tail1 = 0;
	int head2 = 1,tail2 = 0;
	int ans = 0;
	per(i,1,n){
		while(head1 <= tail1 && st1[tail1] > a[i]){
			--tail1;
		}
		st1[++tail1] = a[i];
		while(head2 <= tail2 && st2[tail2] > b[i]){
			--tail2;
		}
		st2[++tail2] = b[i];
		if(tail1 == tail2){
			ans = i;
		}else{
			break;
		}
	}
	printf("%d\n",ans);
}
int main(){
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		per(i,1,n){
			scanf("%d",&b[i]);
		}
		solve();
	}
	
	return 0;
}
