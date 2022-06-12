#include<iostream>
#include<cstdio>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
const int maxn = 1000 + 10;


int main(){
	int t = 0,kase = 0,n = 0,x = 0;
	while(scanf("%d",&t) == 1 && t){
		printf("Scenario #%d\n",++kase);
		map <int,int> team;
		for(int i = 1;i <= t;++i){
			//q.push(i);
			scanf("%d",&n);
			
			for(int j = 0;j < n;++j){//团队与对号建立映射 
				scanf("%d",&x);
				team[x] = i;
				//que[i].push(x);
			}
		}
		char cmd[10];
		queue<int> q,que[maxn]; 
		while(true){
			scanf("%s",cmd);
			if(cmd[0] == 'S'){
				break;
			}else if(cmd[0] == 'D'){
				int temp = q.front();
				printf("%d\n",que[temp].front());
				que[temp].pop();
				if(que[temp].empty()){//如果最后一个元素被pop出，则删除团队号 
					q.pop();
					//cout << "nihao\n";//没有pop出去 
				}
			}else if(cmd[0] == 'E'){
				int temp = 0;
				scanf("%d",&temp);
				int tea = team[temp];//找到他的团队号
				if(que[tea].empty()){//如果团队为0，则添加团队号 
					q.push(tea);
				}
				que[tea].push(temp);
			
			}
			
			 
			
		}
		printf("\n");
		//q.clear();que.clear();
		
		while(!q.empty()){		//为什么不清空队列也可以过？ 
			q.pop();			//题目应该会保证所有人都办完事，就是排队的人全部完事了 
		}
		for(int i = 1;i <= t;++i){
			while(!que[i].empty()){
				que[i].pop();
			}
		}
		
	}
	
	
	
	return 0;
}
