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
const int maxn=1e3 + 10;
const LL mod=1e9+7;

int n = 0,m = 0;
struct node{
	int s,t,id;
};
node a[maxn],b[maxn];
vector<node> p,q;
int cnt0 = 0,cnt1 = 0;
bool cmp1(node x,node y){
	return x.s == y.s ? (x.t > y.t) : (x.s < y.s);
}
void solve(){
	q.push_back(b[1]);
	per(i,2,cnt1){
		bool fg = false;
		per(j,1,i-1){
			if(b[j].s <= b[i].s && b[j].t >= b[i].t){
				//cout << i << endl;
				fg = true;
				break;
			}
		}
		if(!fg){
			q.push_back(b[i]);
		}
	}

	int si1 = q.size();
	bool fg = true;
	per(i,1,cnt0){
		per(j,0,si1-1){
			if(q[j].s <= a[i].s && q[j].t >= a[i].t){
				//cout << j << si1 << endl;
				fg = false;
				puts("NO");
				return ;
			}
		}
	}
	per(i,0,si1-1){
		p.push_back(q[i]);
	}
	per(i,1,cnt0){
		p.push_back(a[i]);
	}
	//sort(p,p+si1+cnt0,cmp1);
	sort(p.begin(),p.end(),cmp1);

	puts("YES");
	int ans[maxn];
	//memset(ans,0,sizeof(ans));


	per(i,1,n){
		ans[i] = 1000;
	}
	per(i,0,si1+cnt0-1){
		if(p[i].id == 1){
			per(j,p[i].s,p[i].t){
				ans[j] = max(ans[j-1] + 1000,ans[j] + 1000);
			}
		}
	}
	per(i,0,si1+cnt0-1){
		if(p[i].id == 0){
			per(j,p[i].s,p[i].t){
				ans[j] = ans[j-1] - 1;
			}
		}
	}
	per(i,1,n){
		printf("%d%c",ans[i],i == n ? '\n' : ' ');
	}
}
int main(){
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	while(~scanf("%d %d",&n,&m)){
		cnt0 = cnt1 = 0;
		p.clear(); q.clear();
		per(i,1,m){
			int id = 0;
			scanf("%d",&id);
			if(id == 0){
				++cnt0;
				scanf("%d %d",&a[cnt0].s,&a[cnt0].t);
				a[cnt0].id = 0;
			}else{
				++cnt1;
				scanf("%d %d",&b[cnt1].s,&b[cnt1].t);
				b[cnt1].id = 1;
			}
		}
		sort(a+1,a+1+cnt0,cmp1);
		sort(b+1,b+1+cnt1,cmp1);


		solve();
	}
	
	return 0;
}
