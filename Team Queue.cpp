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
			
			for(int j = 0;j < n;++j){//�Ŷ���ԺŽ���ӳ�� 
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
				if(que[temp].empty()){//������һ��Ԫ�ر�pop������ɾ���ŶӺ� 
					q.pop();
					//cout << "nihao\n";//û��pop��ȥ 
				}
			}else if(cmd[0] == 'E'){
				int temp = 0;
				scanf("%d",&temp);
				int tea = team[temp];//�ҵ������ŶӺ�
				if(que[tea].empty()){//����Ŷ�Ϊ0��������ŶӺ� 
					q.push(tea);
				}
				que[tea].push(temp);
			
			}
			
			 
			
		}
		printf("\n");
		//q.clear();que.clear();
		
		while(!q.empty()){		//Ϊʲô����ն���Ҳ���Թ��� 
			q.pop();			//��ĿӦ�ûᱣ֤�����˶������£������Ŷӵ���ȫ�������� 
		}
		for(int i = 1;i <= t;++i){
			while(!que[i].empty()){
				que[i].pop();
			}
		}
		
	}
	
	
	
	return 0;
}
