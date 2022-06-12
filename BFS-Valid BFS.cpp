#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 100;
int n = 0;
vector<vector<int> > mp(maxn);
int vis[maxn],id[maxn],num[maxn],ans[maxn];
bool cmp(int x,int y){//按照编号从小到大排序 
	return id[x] < id[y];
}
void bfs(){
	queue<int> que;
	que.push(1);
	vis[1] = 1;
	int cnt = 0;
	ans[++cnt] = 1;
	while(!que.empty()){
		int u = que.front();
		que.pop();
		for(int i = 0;i < mp[u].size();++i){
			int v = mp[u][i];
			if(vis[v] == 0){
				que.push(v);
				ans[++cnt] = v;//记录路径 
				vis[v] = 1;//进入队列的全部标记 
			}
		}
	}
}
int main(){
	while(scanf("%d",&n) != EOF){
		memset(vis,0,sizeof(vis));
		for(int i = 0;i < n - 1;++i){
			int x = 0,y = 0;
			scanf("%d %d",&x,&y);
			mp[x].push_back(y);mp[y].push_back(x);//邻接表存储 
		}
		for(int i = 1;i <= n;++i){//记录每个数在要判断的序列的编号 
			scanf("%d",&num[i]);
			id[num[i]] = i;
		}
		for(int i = 1;i <= n;++i){//按照路径出现的先后顺序排序 
			sort(mp[i].begin(),mp[i].end(),cmp);
		}
		bfs();
		int flag = 0;
		for(int i = 1;i <= n;++i){
			if(ans[i] != num[i]){//比较答案数组与序列是否一致 
				flag = 1;
				printf("No\n");
				break;
			}
		}
		if(flag == 0){
			printf("Yes\n");
		}
	}
		
	return 0;
} 
