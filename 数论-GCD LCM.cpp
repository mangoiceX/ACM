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
#define inf 0x3f3f3f3f
typedef long long LL;
const double eps=1.0e-5;
const int maxn=1e6 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int cnt1=0,cnt2=0,cnt3=0,tmp = 0,ma=-inf,flag;
int n = 0;
int a = 0,b = 0; 
int gcd(int a,int b){
	return (b == 0) ? a : gcd(b,a % b);
}
int lcm(int g){
	return a / g * b;
}
void solve(){
	int gc = gcd(a,b);
	int lc = lcm(gc);
	printf("%d %d\n",gc,lc);
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%d %d",&a,&b)){
		if(a  < b){
			swap(a,b);
		}
		solve();
	}
	
	return 0; 
}
