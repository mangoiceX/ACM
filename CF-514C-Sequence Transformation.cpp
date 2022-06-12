#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
typedef long long LL;
const double eps=1.0e-5;
const int maxn=3e5 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n = 0; 
void solve(){
	if(n == 1){
		printf("1\n");
		return ;
	}
	if(n == 2){
		printf("1 2\n");
		return ;
	}
	if(n == 3){
		printf("1 1 3\n");
		return ;
	}
	
	per(i,1,(n+1)/2){
		printf("1 ");
	}
	int i = 0;
	for(i = 2;i * 2 <= n;){
		if(n/i - n/(i*2) < ((i*2+i) / i - 1) ){
			per(j,1,n/i - n/(i*2)){
				printf("%d ",i);
			}
			i *= 2;
		}else{
			per(j,1,2){
				printf("%d ",i);
			}
			i = i * 2 + 2;
		}
	}
	printf("%d\n",i);
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%d",&n)){
		solve();
	}
	
	return 0; 
}
