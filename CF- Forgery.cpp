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
const int maxn=1e3 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n = 0,m = 0;
string str[maxn]; 
void solve(){
	/*
	if(n >= 6 || m >= 6){
		printf("YES\n");
		return ;
	}
	*/
	per(i,1,n){
		per(j,0,m-1){
			if(i == 1 || i == n || j == 0 || j == m-1){
				continue;
			}
			if(str[i][j] == '#' && (( (j >= 1 && m-j-1 < 2) && (j < m - 1 && j < 2) )
			 && ((i >= 2 && n - i < 2)  && (i < n && i <= 2)) )){
			 	//cout << i <<"¡¡"<< j << endl; 
			 	printf("NO\n");
				 return ;
			 }
		}
	}
	printf("YES\n");
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	while(cin >> n >> m){
		per(i,1,n){
			cin >> str[i];
		}
		solve();
	}
	
	return 0; 
}
