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
const int maxn = 1e5;
int n = 0,m = 0; 
struct node{
	int l,r;
};
node a[maxn+10],b[maxn+10];
bool cmp(node x,node y){
	return x.l == y.l ? (x.r > y.r) : (x.l < y.l);
}
int size = 0;

int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%d %d",&n,&m)){
		per(i,1,m){
			scanf("%d %d",&a[i].l,&a[i].r);
		}
		sort(a+1,a+1+m,cmp);
		if(a[1].l != 1){
			printf("-1\n");
			continue;
		}
		size = 0;
		int rm = a[1].r;
		b[++size].l = a[1].l;b[size].r = a[1].r;
		per(i,2,m){
			if(a[i].l > rm+1){//[1,2],[3,4]可以组成完整的[1,4] 
				printf("-1\n");
				return 0;
			}else{
				if(a[i].r > rm){
					b[++size].l = a[i].l;b[size].r = a[i].r;
					rm = a[i].r;
				}
			}
		}
		int ans = 1;
		rm = b[1].r+1;
		per(i,2,size){
			int maxv = 0;
			if(rm == n+1){
				break;
			}
			while(i <= size && b[i].l <= rm){//注意边界条件 
				maxv = max(maxv,b[i].r+1);
				++i;
			}
			rm = maxv;
			if(i == size + 1){
				if(rm != (n+1)){
					printf("-1\n");
					return 0;
				}
			}
			ans += 1;
			--i;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
