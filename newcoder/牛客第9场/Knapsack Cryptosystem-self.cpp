#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
int num1 = 0,num2 = 0;
const int maxn = 30 + 10;
int n = 0,m = 0;
LL a[maxn];
set<LL> st1,st2;
LL sum[3];
LL s = 0;
bool vis[40];
bool dfs(int depth,LL su,int ma,int pre,int id){
	if(depth == ma+1){
		if(su == sum[id]){
			return true;
		}
		return false;
	}
	if(su > sum[id]){
		return false;
	}
	vis[depth+pre] = true;
	if(dfs(depth+1,su + a[depth+pre],ma,pre,id)){
		return true;
	}
	vis[depth+pre] = false;
	if(dfs(depth+1,su,ma,pre,id)){
		return true;
	}
	vis[depth+pre] = false;
	return false;
}
void solve(){//折半搜索
	sum[1] = 0,sum[2] = 0; 
	set<LL>::iterator it1,it2;//确定前半部分的和与后半部分的和，因为解是唯一的
	for(it1 = st1.begin();it1 != st1.end();++it1){
		it2 = st2.lower_bound(s-*it1);
		if(it2 != st2.end() && (*it2 + *it1 == s)){
			sum[2] = *it2; sum[1] = *it1;
			break;
		}
	}
	dfs(1,0,num1,0,1);//前半部分和后半部分的dfs
	dfs(1,0,num2,num1,2);
	per(i,1,n){
		if(vis[i]){
			printf("1");
		}else{
			printf("0");
		}
	}
	puts("");
}
int main(){

	while(~scanf("%d %lld",&n,&s)){
		per(i,1,n){
			scanf("%lld",&a[i]);
		}
		num1 = n/2,num2 = n - num1;
		//算出牵绊部分和后半部分的数组成和的所有可能，然后再折半搜索
		per(i,0,pow(2,num1)-1){
			LL ma = 0;
			int tmp = i;
			per(j,1,num1){
				if(tmp&1){
					ma += a[j];
				}
				tmp >>= 1;
			}
			st1.insert(ma);
		}
		per(i,0,pow(2,num2)-1){
			LL ma = 0;
			int tmp = i;
			per(j,1,num2){
				if(tmp&1){
					ma += a[j+num1];
				}
				tmp >>= 1;
			}
			st2.insert(ma);
		}
		solve();
	}

	return 0;
}
