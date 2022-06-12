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
int q = 0,m = 0;
int l1 = 0,r1 = 0,l2 = 0,r2 = 0;
void solve(){

}
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
		if(l1 == l2 && r1 == r2){
			printf("%d %d\n",l1,r1);
			continue;
		}
		if(l1 != l2){
			printf("%d %d\n",l1,l2);
			continue;
		}
		if(r1 != r2){
			printf("%d %d\n",r1,r2);
			continue;
		}
		//solve();
	}
	
	
	return 0;
}

