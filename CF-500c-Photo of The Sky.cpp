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
int n = 0; 
LL a[maxn];
void solve(){
	sort(a+1,a+n+1);
	/*
	int num = 0;
	per(i,1,n){
		if(num >= n/2){
			printf("00\n");
			return ;
		}
		if(a[i] == a[i-1]){
			num++;
		}else{
			num = 1;
		}
	}
	*/
	LL minv = INF;
	minv = min(minv,(a[n/2] - a[1]) * (a[n] - a[n/2+1]));
	
	per(i,2,n/2-1){
		minv = min(minv , (a[n]-a[1])*(a[i+n/2-1] - a[i]));
	} 
	printf("%I64d\n",minv);
	
} 
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%d",&n)){
		a[0] = 0;
		per(i,1,n){
			scanf("%I64d",&a[i]);
		} 
		solve(); 
	}
	
	return 0; 
}
