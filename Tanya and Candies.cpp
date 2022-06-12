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

typedef long long LL;

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 3e5;
int n = 0,m = 0;
int a[maxn+10];
int odd1[maxn+10],even1[maxn+10];
int odd2[maxn+10],even2[maxn+10];
int main(){
	while(~scanf("%d",&n)){
		memset(odd1,0,sizeof(odd1));memset(even1,0,sizeof(even1));
		memset(odd2,0,sizeof(odd2));memset(even2,0,sizeof(even2));
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		rep(i,n,1){
			if(i&1){
				odd1[i] = odd1[i+2] + a[i];
			}else{
				even1[i] = even1[i+2] + a[i];
			}
		}
		per(i,1,n){
			if(i&1){
				if(i == 1){
					odd2[i] = a[i];
					continue;
				}
				odd2[i] = odd2[i-2] + a[i];
			}else{
				even2[i] = even2[i-2] + a[i];
			}	
		}
		int ans = 0;
		per(i,1,n){
			if(i & 1){
				if((odd1[i+2] + even2[i-1] ) == (even1[i+1] + odd2[i-2])){
					ans++;
				}
			}else{
				if((odd1[i+1] + even2[i-2] ) == (even1[i+2] + odd2[i-1])){
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	
	
	return 0;
}

