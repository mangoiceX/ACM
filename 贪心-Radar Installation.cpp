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
const int maxn = 1e3;
int n = 0;
double d = 0;
struct node{
	double x,y;
};
int ans1 = 0,ans2 = 0;
node is[maxn+10];
bool cmp(node a,node b){
	return a.x != b.x ? a.x < b.x : a.y < b.y;
}
void solve(){
	ans1 = 1,ans2 = 1;
	double x1 = is[1].x + sqrt(d*d - is[1].y * is[1].y);
	per(i,2,n){
		if(x1 < is[i].x - sqrt(d*d - is[i].y * is[i].y)){
			x1 = is[i].x + sqrt(d*d - is[i].y * is[i].y);
			ans1++;
		}else if(x1 > is[i].x + sqrt(d*d - is[i].y * is[i].y)){//这个条件一定要加上去 
			x1 = is[i].x + sqrt(d*d - is[i].y * is[i].y);
		}//这个条件是对贪心的修正，因为第一个选择了
		//is[i].x + sqrt(d*d - is[i].y * is[i].y)，下面点时，他的y可能会比较大，
		//从而导致他的is[i].x + sqrt(d*d - is[i].y * is[i].y)比之前那个点要小 
		//所以这个时候x1要改成这个点的临界值 
	}
	x1 = is[n].x - sqrt(d*d - is[n].y * is[n].y);
	rep(i,n-1,1){
		if(x1 > is[i].x + sqrt(d*d - is[i].y * is[i].y)){
			x1 = is[i].x - sqrt(d*d - is[i].y * is[i].y);
			ans2++;
		}else if(x1 < is[i].x - sqrt(d*d - is[i].y * is[i].y)){
			x1 = is[i].x - sqrt(d*d - is[i].y * is[i].y);
		}
	}
}
int main(){
	int kase = 0;
	while(~scanf("%d %lf",&n,&d) && (n || d)){
		double maxy = 0;
		per(i,1,n){
			scanf("%lf %lf",&is[i].x,&is[i].y);
			maxy = max(maxy,is[i].y);
		}
		if(maxy > d){
			printf("Case %d: -1\n",++kase);
			continue;
		}
		sort(is+1,is+1+n,cmp);
		solve();
		printf("Case %d: %d\n",++kase,min(ans1,ans2));
	}
	
	return 0;
}

