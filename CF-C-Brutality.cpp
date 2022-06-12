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
const int maxn = 2e5;
int n = 0,k = 0; 
int a[maxn+10];
char str[maxn+10];
bool cmp(int x,int y){
	return x > y;
}
void solve(){
	vector<int> rec;
	rec.push_back(0);
	int loc = 0;
	per(i,1,n-1){
		while(i <= n-1 && str[i] == str[loc]){
			++i;
		}
		loc = i;
		rec.push_back(loc);
	}

	int size = rec.size();

	per(i,0,size-2){
		sort(a+rec[i],a+rec[i+1],cmp);
	}
	LL ans = 0;
	per(i,0,size-2){
		per(j,rec[i],min(rec[i]+k-1,rec[i+1]-1)){
			ans += a[j];
		}
	}
	ans += (str[n-1] == str[n-2] ? 0 : a[n-1]);//注意边界问题 
	printf("%I64d\n",ans);
}
int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%d %d",&n,&k)){
		per(i,0,n-1){
			scanf("%d",&a[i]);
		}
		scanf("%s",str);
		solve();
	}
	

	return 0;
}

