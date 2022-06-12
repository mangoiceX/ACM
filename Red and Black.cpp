#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
using namespace std;
const int maxn = 25;
char str[maxn][maxn];
bool visited[maxn][maxn];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int w = 0,h = 0;
int cnt = 0;
void dfs(int x,int y){
	visited[x][y] = 1;
	for(int i = 0;i < 4;++i){
		int tx = x + dx[i],ty = y + dy[i];
		if(tx >=0 && tx < h && ty >= 0 && ty < w && visited[tx][ty] == 0 && str[tx][ty] != '#'){
			++cnt;
			dfs(tx,ty);
		}
	}
	
}
int main(){
	int sx = 0,sy = 0;
	while(scanf("%d %d",&w,&h) != EOF && w && h){
		cnt = 1;
		memset(visited,0,sizeof(visited));
		for(int i = 0;i < h;++i){
			getchar();
			for(int j = 0;j < w;++j){
				//cin >> str[i][j];
				scanf("%c",&str[i][j]);
				if(str[i][j] == '@'){
					sx = i,sy = j;
				}
			}
		}
		dfs(sx,sy);
		printf("%d\n",cnt);
	}
	
	
	
	
	
	return 0;
} 
