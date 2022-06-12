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
const int maxn=1e5 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n = 0; 
int bit[maxn][18];
int a[maxn];
void getbit(){
	per(i,1,n+1){
		int temp = a[i];
		int cnt = 0;
		while(temp > 0){
			bit[i][cnt++] = temp % 2;
			temp >>= 1;
		}
	}
	
	
}
void solve(){
	memset(bit,0,sizeof(bit));
	per(i,1,n){
		if(a[i] == a[i-1]){
			printf("0\n");
			return ;
		}
	}
	set<int> st0,st1;
	per(i,1,n){
		st0.insert(i);st1.insert(i);
	} 
	getbit();
	int num[18],cnt = 0;
	per(i,0,17){
		if(a[n+1][i] == 1){
			num[cnt++] = i;
		}
	}
	per(i,0,cnt-1){
		per(j,i+1,cnt-1){
			if()
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%d %d",&n,&x)){
		a[0] = 0;a[n+1] = x; 
		per(i,1,n){
			scanf("%d",&a[i]);
		} 
		sort(a+1,a+1+n);
		solve();
	}
	
	return 0; 
}
