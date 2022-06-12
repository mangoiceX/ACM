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

//#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
typedef long long LL;
typedef pair<int,int> pii;
const double eps=1.0e-5;
const int maxn=3e5 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n = 0,x = 0; 
int a[maxn],b[maxn];
void solve(){
	per(i,1,n){//判断0的情况 
		if(a[i] == a[i-1]){
			printf("0\n");
			return ;
		}
	}
	per(i,1,n){//判断-1的情况 
		b[i] = a[i] & x;
	}
	b[0] = -1;
	sort(b+1,b+n+1);
	bool flag = false;
	per(i,1,n){
		if(b[i] == b[i-1]){
			flag = true;
			break;
		}
	}
	if(flag == false){
		printf("-1\n");
		return ;
	}
	
	per(i,1,n){//判断1的情况 
		if(a[i] == (a[i] & x)){
			continue;
		}
		if(
		//lower_bound(a+1,a+1+n,a[i] & x) != a+n+1 && //画蛇添足，导致WA 
		//lower_bound(a+1,a+1+n,a[i] & x) != (a + 1)  && 
		*lower_bound(a+1,a+1+n,a[i] & x) == (a[i] & x)){
			printf("1\n");
			return ;
		}
	}
	printf("2\n");//其它全是2的情况 
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%d %d",&n,&x)){
		per(i,1,n){
			scanf("%d",&a[i]);
		} 
		sort(a+1,a+n+1);
		solve(); 
	}
	
	return 0; 
}
