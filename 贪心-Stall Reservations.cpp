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
const int maxn = 5e4;
int n = 0;
struct node{
	int s,e,id,num;
};
bool operator < (node a,node b){//重载运算符，因为set要比较 
	return a.e <= b.e;
}
node cow[maxn+10];
bool cmp(node a,node b){//按照开始时间递增的顺序排序 
	return a.s != b.s ? a.s< b.s : a.e < b.e;
}
bool cmp1(node a,node b){//按出场顺序排序，排回去 
	return a.num < b.num;
}
void solve(){
	int ans = 0;
	set<node> st;
	node mi;mi.e = INF;mi.id = -1;
	st.insert(mi);
	per(i,1,n){
		bool flag = false;
		node minv = *st.begin();//每次从之前的选取结束时间最小的，greedy 
		if(cow[i].s > minv.e){
			--ans;
			st.erase(st.begin());
			cow[i].id = minv.id;
			flag = true;
		}
		++ans;
		if(flag == false){
			cow[i].id = ans;
		}
		st.insert(cow[i]);
	}
	printf("%d\n",ans);
	sort(cow+1,cow+1+n,cmp1);
	per(i,1,n){
		printf("%d\n",cow[i].id);
	}
}
int main(){
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%d %d",&cow[i].s,&cow[i].e);
			cow[i].id = 0;cow[i].num = i;
		}
		sort(cow+1,cow+1+n,cmp); 
		solve();
	}
	
	return 0;
}




