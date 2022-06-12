#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 1e3;
int n = 0;
int d = 0;
struct node{
	double a,b;
};
node p[maxn+10];
bool cmp(node x,node y){
	if(x.a == 0 || y.a == 0){
		return x.a > y.a;
	}
	return (x.b / x.a == y.b / y.a) ? x.a > y.a : (x.b / x.a > y.b / y.a);
}
int main(){
	while(~scanf("%d %d",&n,&d)){
		per(i,1,n){
			scanf("%lf",&p[i].a);
		}
		per(i,1,n){
			scanf("%lf",&p[i].b);
		}
		sort(p+1,p+1+n,cmp);
		double ans = 0;
		int i = 1;
		while(d > 0 && i <= n){//i <= n因为d可能大于供给和，没有注意 
			if(p[i].a == 0){
				++i;
				continue;
			}
			ans += (p[i].a >= d ? d*(p[i].b / p[i].a) : p[i].b);
			d = max(d-p[i].a,0.0);
			++i;
		}
		printf("%.2lf\n",ans);
	}
	
	return 0;
}
