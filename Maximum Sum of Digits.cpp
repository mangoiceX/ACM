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
LL n = 0; 
int a[maxn];
void solve(){
	if(n <= 18){
		printf("%I64d\n",n);
		return ; 
	}
	int cnt = 0;
	LL temp = n;
	while(temp > 0){
		cnt++;
		temp /= 10;
	}
	//LL res1 = ((n/10 )- 1) * 10 + 9;
	LL res1 = 0,t1 = 0;
	per(i,1,cnt-1){
		res1 += 9;
		t1 += pow(10,cnt-i-1) * 9;
	}
	//cout << t1 << endl;
	LL t2 = n - t1;
	LL res2 = 0;
	while(t2 > 0){
		res2 += t2 % 10;
		t2 /= 10;
	}
	
	printf("%I64d\n",res1 + res2);
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%I64d",&n)){
		solve();
	}
	
	return 0; 
}
