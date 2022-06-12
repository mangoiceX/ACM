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
LL p = 0,a = 0;
bool judge(){
	LL res = 1;
	LL pi = p,ai = a;
	while(p > 0){
		if(p & 1){
			res  = (res * (a % pi) ) % pi;
		}
		p >>= 1;
		a = (a * a) % pi;
	}
	return (res % pi == ai) ? true : false;
}
void solve(){
	bool flag = true;
	for(int i = 2;i * i <= p;++i){
		if(p % i == 0){
			flag = false;
			break;
		}
	}
	if(flag == true){
		printf("no\n");
		return ;
	}else{
		if(judge()){
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%I64d %I64d",&p,&a) && p && a){
		solve();
	}
	
	return 0; 
}
