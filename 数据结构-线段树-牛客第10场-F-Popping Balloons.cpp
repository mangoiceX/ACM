#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e9
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
int n = 0,m = 0,q = 0,r = 0;
int row[maxn],col[maxn]; 
int mx = 0;
vector<int> rc[maxn];
struct Tree{
	int l,r,val;
}st[maxn<<2];
void push_up(int rt){
	st[rt].val = max(st[rt<<1].val,st[rt<<1|1].val);
}
void build(int rt,int l,int r){
	st[rt].l = l,st[rt].r = r;
	if(l == r){
		st[rt].val = 0;
		return ;
	}
	int mid = (l+r) >> 1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	push_up(rt);
}

void update(int rt,int pos,int add_val){
	if(st[rt].l == st[rt].r){
		st[rt].val += add_val;
		return ;
	}
	int mid = (st[rt].l + st[rt].r) >> 1;
	if(pos <= mid){
		update(rt<<1,pos,add_val);
	}else{
		update(rt<<1|1,pos,add_val);
	}
	push_up(rt);
}
void init(){
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));
	per(i,0,1e5){
		rc[i].clear();
	}
}

int getcol(int y){
	int x1 = y - r >= 0 ? col[y-r] : 0;
	int x2 = y >= 0 ? col[y] : 0;
	int x3 = y + r <= 1e5 ? col[y+r] : 0;
	return x1+x2+x3;
}
int getrow(int x){
	int x1 = x- r >= 0 ? row[x-r] : 0;
	int x2 = x >= 0 ? row[x] : 0;
	int x3 = x + r <= 1e5 ? row[x+r] : 0;
	return x1+x2+x3;
}
void cal(int y,int add_val){
	if(y-r >= 0){
		update(1,y-r,add_val);
	}
	update(1,y,add_val);
	if(y+r <= 1e5){
		update(1,y+r,add_val);
	}
}
void solve(){
	int ans = 0;
	per(i,0,1e5){
		int sum = getrow(i);
		if(i - r >= 0){
			int si = rc[i-r].size();
			per(j,0,si-1){
				int cc = rc[i-r][j];
				cal(cc,-1);
			}
		}
		int si1 = rc[i].size();
		per(j,0,si1-1){
			int cc = rc[i][j];
			cal(cc,-1);
		}
		if(i + r <= 1e5){
			int si = rc[i+r].size();
			per(j,0,si-1){
				int cc = rc[i+r][j];
				cal(cc,-1);
			}
		}
		ans = max(ans,sum + st[1].val);

		if(i - r >= 0){//回退原来的操作
			int si = rc[i-r].size();
			per(j,0,si-1){
				int cc = rc[i-r][j];
				cal(cc,1);
			}
		}
		si1 = rc[i].size();
		per(j,0,si1-1){
			int cc = rc[i][j];
			cal(cc,1);
		}
		if(i + r <= 1e5){
			int si = rc[i+r].size();
			per(j,0,si-1){
				int cc = rc[i+r][j];
				cal(cc,1);
			}
		}
		
	}
	printf("%d\n",ans);
}
/*
线段树维护每列和的最大值。
枚举行，然后将行对应的列(每列可以对周围3个点产生贡献减去所有列的对总体的贡献，
剩下的就是去重的列)，然后直接查询最大值，也就是线段树的根节点。

*/
int main(){
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	while(~scanf("%d %d",&n,&r)){
		init();
		per(i,1,n){
			int x = 0,y = 0;
			scanf("%d %d",&x,&y);
			++row[x]; ++col[y];
			rc[x].push_back(y);
		}
		build(1,0,1e5);//建树的时候从0开始建立，因为0也是一个有效点

		per(i,0,1e5){
			int tmp = getcol(i);
			if(tmp){
				update(1,i,tmp);
			}
		}
		solve();
	}

	return 0;
}
