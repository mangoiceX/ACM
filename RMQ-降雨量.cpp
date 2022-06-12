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
int n = 0,q = 0; 
 
struct node{
	int y,r;
}; 
struct nd{
	int ma,id;
};
node a[maxn+10];
nd dp[maxn+10][20];
void RMQ(){
	per(i,1,n){
		dp[i][0].ma = a[i].r;
		dp[i][0].id = i;
	}
	for(int j = 1;(1 << j) <= n;++j){
		for(int i = 1;i + (1<<j-1) <= n;++i){
			if(dp[i][j-1].ma >= dp[i+(1<<(j-1))][j-1].ma){
				dp[i][j].ma = dp[i][j-1].ma;
				dp[i][j].id = dp[i][j-1].id;
			}else{
				dp[i][j].ma = dp[i+(1<<(j-1))][j-1].ma;
				dp[i][j].id = dp[i+(1<<(j-1))][j-1].id;
			}
		}
	}
}
int query(int l,int r){
	if(l > r){
		return 0;
	}
	int k = 0;
	while((1<<(k+1)) <= (r - l + 1)){
		++k;
	}
	int id = INF;
	if(dp[l][k].ma >= dp[r-(1<<k)+1][k].ma){
		id = dp[l][k].id;
	}else{
		id = dp[r-(1<<k)+1][k].id;
	}
	
	return id;
}
int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%d",&n) && n){
		map<int,int> mp;	map<int,int> mp2;
		per(i,1,n){
			scanf("%d %d",&a[i].y,&a[i].r);
			mp[a[i].y] = i;
			mp2[i] = a[i].y;
		}
			
		RMQ();
		scanf("%d",&q);
		per(i,1,q){
			int l = 0,r = 0;
			scanf("%d %d",&l,&r);
			
			int id = query(mp2[mp[l]+1],mp[r]);
			if(id == mp[l]){
				printf("true\n");
			}else{
				printf("false\n");
			}
		}
	}
	

	return 0;
}

