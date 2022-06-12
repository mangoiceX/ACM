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
const int maxn=4e5 + 1000;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n = 0; 
struct node{
	int l,r;
};

map<int,int> mp;
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	int q = 0;
	scanf("%d",&q);
	int mid = q / 2 + 1,cntr = 0,cntl = 0; 
	while(q--){
		char ch;
		int x = 0;
		getchar();
		scanf("%c %d",&ch,&x);
		if(ch == 'L'){
			//a[mid-cntl] = x;
			mp[x] = mid-(cntl++);
		}else if(ch == 'R'){
			//a[mid+cntr+1] = x;
			mp[x] = mid + (cntr++) + 1;
		}else{
			printf("%d\n",min(mp[x] - (mid - cntl+1),(mid+cntr) - mp[x]));
		}
	} 
	
	return 0; 
}
