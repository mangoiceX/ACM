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
const int maxn = 1e2;
int n = 0,k = 0;
struct node{
	LL x,y;
};
bool cmp(double x,double y){
	return x > y;
}
node a[maxn+10];
double ans[maxn+10]; 
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);
		per(i,1,n){
			scanf("%lld %lld",&a[i].x,&a[i].y);
		}
	//	double ans = 0;
		int cnt = 0;
		per(i,1,n){
			per(j,i+1,n){
				per(k,j+1,n){
					if(i == k || i == j || j == k){
						continue;
					}
					double sum = (a[i].x * a[j].y + a[i].y*a[k].x + a[j].x*a[k].y) -
					 (a[i].x*a[k].y + a[j].y*a[k].x + a[i].y*a[j].x);
					 if(sum == 0){
					 	continue;
					 }
					 //cout << sum << endl;
					 //sum *= 500;
					 sum /= 2.0;
					 //cout << "nia " << sum << endl;
					 /*
					 if(sum % 10 >= 5){
					 	sum = ((sum / 10) + 1) * 10;
					 }else{
					 	sum = (sum/10)*10;
					 }
					 */ 
					 ans[++cnt] = fabs(sum);
				}
			}
		}
		sort(ans+1,ans+1+cnt,cmp);
		//int res = ans[k] % 1000;
		printf("%.2lf\n",ans[k]);
		/*
		if(res / 100 > 0){	
			printf("%lld.%d\n",ans[k]/1000,res/10);
		}else if(res / 10 > 0){
			printf("%lld.0%d\n",ans[k]/1000,res/10);
		}else{
			printf("%lld.00\n",ans[k]/1000);
		}
		//printf("%lld.%d\n",ans[k]/1000,);
		*/
	}
	
	return 0;
}

