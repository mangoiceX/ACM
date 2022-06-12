#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<set> 
#include<queue>
#include<algorithm>
using namespace std;
struct Node{
	int x,y;
	int time;
};
const int maxn = 310;
int map[maxn][maxn];
int dx[5] = {0,1,0,-1,0};
int dy[5] = {0,0,1,0,-1};
int dfs(){
	
	if(map[0][0] == -1){	//特殊情况处理 
		return 0;
	}
	if(map[0][0] == 0){//到达终点 
		return -1;
	}
	
	queue<Node> que;
	Node temp,now;
	temp.time = temp.x = temp.y = 0;
	que.push(temp);
	while(!que.empty()){
		now = que.front();
		que.pop();
		
		for(int i = 1;i < 5;++i){
			
			temp.x = now.x + dx[i],temp.y = now.y + dy[i];
			temp.time = now.time + 1;
			
			if(temp.x < 0 ||temp.y < 0 || temp.x >= maxn || temp.y >= maxn){//先把特殊情况全处理 
				continue;
			}
			if(map[temp.x][temp.y] == -1){//
				return temp.time;
			}
			if(temp.time >= map[temp.x][temp.y]){//第一次比较是与毁灭时间比较
												//后面更新后是与到达该点的最短时间比较 
				continue;
			}
			
			map[temp.x][temp.y] = temp.time;//更新到达该点的最短时间 
			que.push(temp);
		}
	}
	return -1;
}
int main(){
	int num = 0;
	//while(cin >> num){
	while(scanf("%d",&num) != EOF && num){
		memset(map,-1,sizeof(map));
		Node temp;
		for(int i = 0;i < num;++i){
			
			//cin >> temp.x >> temp.y >> temp.time;
			scanf("%d %d %d",&temp.x,&temp.y,&temp.time);
			for(int i = 0;i < 5;++i){				//记录每个地方被袭击的时间 
				int tx = temp.x + dx[i],ty = temp.y + dy[i];
				if(tx < 0 || tx >= maxn || ty < 0 || ty >= maxn){
					continue;
				}
				if(map[tx][ty] == -1){
					map[tx][ty] = temp.time;//记录最早被毁灭的时间，	
											//	所以要加上map[tx][ty] == -1的条件 x
				}else{
					map[tx][ty] = min(map[tx][ty],temp.time);
				}
			}
		} 
		
		int ans = dfs();
		//cout << ans << endl;
		printf("%d\n",ans);
	}
	
	return 0;
}
