#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
using namespace std;
const int maxn = 100 + 5;
char str[maxn][maxn];
bool vis[maxn][maxn];
int dx[8] = {1,-1,0,0,1,-1,1,-1};
int dy[8] = {0,0,1,-1,1,-1,-1,1};
int m = 0,n = 0;
int cnt = 0;

void dfs(int x,int y){
	vis[x][y] = 1;
	
	for(int i = 0;i < 8;++i){
		
		int tx = x + dx[i],ty = y + dy[i];
		//cout << i << " " <<  tx << " " << ty << endl;
		if(tx >=0 && tx < m && ty >= 0 && ty < n && vis[tx][ty] == 0 && str[tx][ty] == '@'){
			dfs(tx,ty);
		}
		
	}
	
	
}


int main(){
	
	while(scanf("%d %d",&m,&n) != EOF && m && n){
		cnt = 0;
		memset(vis,0,sizeof(vis));
		for(int i = 0;i < m;++i){
			getchar(); 
		//	for(int j = 0;j < n;++j){		//使用%c一个一个读取不知道为什么会出现问题？ 
				//scanf("%c",&str[i][j]);
			//}
			scanf("%s",str[i]);
		}
		
		for(int i = 0;i < m;++i){
			for(int j = 0;j < n;++j){
				if(str[i][j] == '@' && vis[i][j] == 0){
				//	cout << i << " " << j << endl;
					dfs(i,j);
					++cnt;
				}
			}
		}
		printf("%d\n",cnt);
	}
	
	
	return 0;
}
