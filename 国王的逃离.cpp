#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<string>

using namespace std;
const int maxn = 3e5;

typedef long long LL;

#define inf 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)

int n = 0;
int x11 = 0,y11 = 0,x2 = 0,y2 = 0,x3 = 0,y3 = 0; 
bool flag = false;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int d[3] = {-1,0,1}; 
bool vis[1000+10][1000+10];
void dfs(int x,int y){
	/*
	if(x == x3 && y == y3){
		flag = true;
		return ;
	}
	if(abs(x - x2) == abs(y - y2)){
		return ;
	}
	if(x == x2 || y == y2){
		return ;
	}
	*/
	//cout << "yes\n";
	vis[x][y] = true;
	for(int i = 0;i < 3;++i){
		for(int j = 0;j < 3;++j){
			if(i ==  1 && j == 1){
				continue;
			}
			int tx = x + d[i], ty = y + d[j];
			
			if(tx == x2 || ty == y2){
				continue;
			}
			if(abs(tx - x2) == abs(ty - y2)){
				continue; ;
			}
			if(tx == x3 && ty == y3){
				flag = true;
				return ;
			}
			if(tx >= 1 && tx <= n && ty >= 1 && ty <= n && vis[tx][ty] == false){
				dfs(tx,ty);
			}
		}
	}
}
int main(){	
	int T = 0;
	scanf("%d",&T);
	while(T--){
		fill(vis[0],vis[0]+(1000+10)*(1000+10),false);
		flag = false;
		scanf("%d",&n);
		scanf("%d %d",&x11,&y11);
		scanf("%d %d",&x2,&y2);
		scanf("%d %d",&x3,&y3);
		dfs(x11,y11);
		printf("%s\n",flag ? "Yes" : "No");
	}
	
	return 0;
}




