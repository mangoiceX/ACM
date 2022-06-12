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
bool vis[3];
int a[maxn+10];
void solve(){

}
int main(){
	while(~scanf("%d",&n)){
		memset(vis,false,sizeof(vis));
		per(i,1,n){
			scanf("%d",&a[i]);
			vis[a[i]&1] = true;
		}
		if(vis[0] && vis[1]){
			sort(a+1,a+1+n);
			per(i,1,n){
				printf("%d%c",a[i],i == n ? '\n' : ' ');
			}
			continue;
		}else{
			per(i,1,n){
				printf("%d%c",a[i],i == n ? '\n' : ' ');
			}
		}
	}
	return 0;
}

