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
const int maxn = 1e2;//G++会WA， 
int n = 0,m = 0;
double a[maxn+10];

int main(){

	while(~scanf("%d",&n)){//G++会WA 
		priority_queue<double> pq;//默认top是最大值 
		per(i,1,n){
			scanf("%lf",&a[i]);
			pq.push(a[i]);
		}
		while(pq.size() != 1){
			double x = pq.top();
			pq.pop();
			double y = pq.top();
			pq.pop();
			pq.push(2*sqrt(x*y));
		}
		printf("%.3lf\n",pq.top());
	}
	
	return 0;
}

