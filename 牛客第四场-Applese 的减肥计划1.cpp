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
int a = 0,b = 0,c = 0; 
void solve(){

}
int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%d %d %d",&a,&b,&c)){
		printf("%.10lf\n",sqrt(a*a + b*b + 2*a*b*cos(c*1.0/180*PI)));
	}
	
	return 0;
}

