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
	
	if(map[0][0] == -1){	//����������� 
		return 0;
	}
	if(map[0][0] == 0){//�����յ� 
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
			
			if(temp.x < 0 ||temp.y < 0 || temp.x >= maxn || temp.y >= maxn){//�Ȱ��������ȫ���� 
				continue;
			}
			if(map[temp.x][temp.y] == -1){//
				return temp.time;
			}
			if(temp.time >= map[temp.x][temp.y]){//��һ�αȽ��������ʱ��Ƚ�
												//������º����뵽��õ�����ʱ��Ƚ� 
				continue;
			}
			
			map[temp.x][temp.y] = temp.time;//���µ���õ�����ʱ�� 
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
			for(int i = 0;i < 5;++i){				//��¼ÿ���ط���Ϯ����ʱ�� 
				int tx = temp.x + dx[i],ty = temp.y + dy[i];
				if(tx < 0 || tx >= maxn || ty < 0 || ty >= maxn){
					continue;
				}
				if(map[tx][ty] == -1){
					map[tx][ty] = temp.time;//��¼���类�����ʱ�䣬	
											//	����Ҫ����map[tx][ty] == -1������ x
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
