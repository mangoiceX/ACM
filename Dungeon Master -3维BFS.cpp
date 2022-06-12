#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
using namespace std;
const int maxn = 35;
char maze[maxn][maxn][maxn];//三维迷宫 
bool vis[maxn][maxn][maxn];
//int dist[maxn][maxn][maxn];
struct Node{
	int x,y,z;
	int step;
};
//queue<Node> que;//之前将que定义为全局变量，导致不同测试样例的que会互相影响 
int L = 0,R = 0,C = 0;
int sx = 0,sy = 0,sz = 0;//起点 
int ex = 0,ey = 0,ez = 0;//终点
int dx[6] = { 1,-1,0,0,0,0 };//三维移动 
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int bfs(int x,int y,int z){
	queue<Node> que;//之前将que定义为全局变量，导致不同测试样例的que会互相影响 
	
	Node node1;
	node1.x = x,node1.y = y,node1.z = z,node1.step = 0;
	vis[z][y][x] = 1;
	que.push(node1);
	while(!que.empty()){
		Node u = que.front();
		que.pop();
		if(u.x == ex && u.y == ey && u.z == ez){//如果到达终点 
			return u.step;
		}
		for(int i = 0;i < 6;++i){
			Node v;
			v.x= u.x + dx[i],v.y = u.y + dy[i],v.z = u.z + dz[i];
			if(v.x >= 1 && v.x <= C && v.y  >= 1 && v.y  <= R && v.z >= 1 && v.z <= L
			&& vis[v.z][v.y][v.x] == 0 && maze[v.z][v.y][v.x] != '#'){
				vis[v.z][v.y ][v.x] = 1;
				//dist[v.z][v.y ][v.x] = dist[u.z][u.y][u.x] + 1;
				v.step = u.step + 1;
				que.push(v);
			}
		}
	}
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);

	while(cin >> L >> R >> C && L && R && C){
		//ans = 0;
		//memset(maze,'0',sizeof(maze));
		memset(vis,0,sizeof(vis));
		//memset(dist,-1,sizeof(dist));
	
		for(int i = 1;i <= L;++i){
			//cout << endl;
			for(int j = 1;j <= R;++j){
				for(int k = 1;k <= C;++k){
					cin >> maze[i][j][k];
					
					if(maze[i][j][k] == 'S'){//记录起点和终点 
						sz = i,sy = j,sx = k;
					}
					if(maze[i][j][k] == 'E'){
						ez = i,ey = j,ex = k;
					}
					
				}
			}
		}
		/* //错误的剪枝 
		if(sz != sy){//起点和终点不在同一层 
			if(maze[ez - 1][ey][ex] == '#'){//终点的下一层没有通向终点的路 
				cout << "Trapped!" << endl;
				break;
			}
		}*/
		int ans = bfs(sx,sy,sz);
		if(ans != 0){
			cout << "Escaped in "<< ans << " minute(s)." << endl;
		}else{
			cout << "Trapped!" << endl;
		}
		
	}
	
	
	
	return 0;
}
