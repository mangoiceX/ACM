//运行时间：480ms                                                                           
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<set> 
#include<queue>
#include<algorithm>
#define INF 1000005
using namespace std;
const int maxn = 1000 + 10;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int r = 0,c = 0;
int sx = 0,sy = 0;
struct Node{
	int x,y;
	int step;
};
bool vis[maxn][maxn]; 
int time_f[maxn][maxn];
char maze[maxn][maxn];
int es_tm = 0;
void bfs_f(int x,int y){	//求每个地点被烧的最短时间 
	queue<Node> que;
	Node no;
	no.x = x,no.y = y,no.step = 0;
	que.push(no);
	time_f[x][y] = 0;
	vis[x][y] = 1;
	while(!que.empty()){
		Node u = que.front();
		que.pop();
		
		for(int i = 0;i < 4;++i){
			Node v;
			v.x = u.x + dx[i],v.y = u.y + dy[i];
			if(v.x >= 1 && v.x <= r && v.y >= 1 && v.y <= c && maze[v.x][v.y] != '#'
			&& vis[v.x][v.y] == 0){
				vis[v.x][v.y] = 1;
				v.step = u.step + 1;
				if(time_f[v.x][v.y] > v.step){	//不同起火点最短时间的比较 
					time_f[v.x][v.y] = v.step;
					que.push(v);
				} 
				
			}
		}
	}
}

bool bfs_j(int x,int y){
	if((x == 1 || x == r || y == 1 || y == c) && time_f[x][y] > 0){//一开始就在边界 
		es_tm = 0;
		 return true;
	}
	if(time_f[x][y] == 0){//一开始所在地就是起火点 
		return false;
	}
	vis[x][y] = 1;
	queue<Node> q;
	Node no;
	no.x = x,no.y = y;
	no.step = 0;
	q.push(no);
	
	while(!q.empty()){
		Node u = q.front();
		q.pop();
		/*
		if(u.step < time_f[u.x][u.y] &&( u.x == 1  || u.x == r || u.y == 1 || .y == c)){
			//已经到达边界，并且没被烧的
			return true; 
		}
		*/
		for(int i = 0;i < 4;++i){
			Node v;
			v.x = u.x + dx[i],v.y = u.y + dy[i];
			if(v.x >= 1 && v.x <= r && v.y >= 1 && v.y <= c && maze[v.x][v.y] != '#' && 
			vis[v.x][v.y] == 0){
				
				v.step = u.step + 1;
				es_tm = v.step;	
				if(v.step < time_f[v.x][v.y] &&( v.x == 1  || v.x == r || v.y == 1 || v.y == c)){
					//已经到达边界，并且没被烧的
					return true; 
				}
				if(v.step <  time_f[v.x][v.y]){//关键步骤 
					vis[v.x][v.y] = 1;
					time_f[v.x][v.y] = v.step;//第一次比较是与毁灭时间比较
											//后面更新后是与到达该点的最短时间比较 
					q.push(v);
				}
				
			}
		}
		
	}
	return 0;
}
void init(){
	memset(time_f,INF,sizeof(time_f));
	es_tm = 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	int T = 0;
	cin >> T;
	while(T--){
		init();//初始化 
		cin >> r >> c;
		for(int i = 1;i <= r;++i){
			for(int j = 1;j <= c;++j){
				cin >> maze[i][j];	
			}	
		}
		
		for(int i = 1;i <= r;++i){
			for(int j = 1;j <= c;++j){
				
				if(maze[i][j] == 'J'){	//出发位置 
					sx = i,sy = j;
				}
				if(maze[i][j] == 'F'){	//看每个点最快被烧的时间 
					memset(vis,0,sizeof(vis));
					bfs_f(i,j);
				}	
			}
		}
		/*
		for(int i = 1;i <= r;++i){
			for(int j = 1;j <= c;++j){
				cout << time_f[i][j] << " ";
			}
			cout << endl;
		}
		*/
		memset(vis,0,sizeof(vis));
		if(bfs_j(sx,sy)){
			cout << es_tm + 1 << endl;
		}else{
			cout << "IMPOSSIBLE" << endl;
		}
		
	}
		
	return 0;
}
