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
int l1 = 0,l2 = 0;
double x = 0,y = 0;
void solve(){
	double r = sqrt(x*x + y*y);
	if(r >= abs(l1-l2) && r <= abs(l1+l2)){
		puts("0.00000000");
		return ;
	}
	if(r < abs(l1-l2)){
		printf("%.8lf\n",abs(l1-l2) - r);
	}else{
		printf("%.8lf\n",r - abs(l1+l2));
	}
}
int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%d %d",&l1,&l2)){
		int T = 0;
		scanf("%d",&T);
		while(T--){
			scanf("%lf %lf",&x,&y);
			solve(); 
		}
	}
	
	
	return 0;
}

