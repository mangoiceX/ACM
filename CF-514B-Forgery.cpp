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
const int maxn=2e3 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n = 0,m = 0; 
char s[maxn][maxn],t[maxn][maxn];
bool check(int x,int y){
	per(i,x-1,x+1){
		per(j,y-1,y+1){
			if(i == x && j == y){
				continue;
			}
			if(s[i][j] != '#'){
				return false;
			}
		}
	}
	return true;
}
void fill_ink(int x,int y){
	per(i,x-1,x+1){
		per(j,y-1,y+1){
			if(i == x && j == y){
				continue;
			}
			t[i][j] = '#';
		}
	}
}
void solve(){
	per(i,1,n){
		per(j,1,m){
			if(s[i][j] != t[i][j]){
				printf("NO\n");
				return ;
			}
		}
	}
	printf("YES\n");
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%d %d",&n,&m)){
		getchar();//不要忘记 
		per(i,1,n){
			per(j,1,m){
				scanf("%c",&s[i][j]);
				t[i][j] = '.';
			}
			getchar();//不要忘记 
		}
		per(i,2,n-1){
			per(j,2,m-1){
				if(check(i,j) == true){
					fill_ink(i,j);
				}
			}
		}
		solve();
	}
	
	return 0; 
}
