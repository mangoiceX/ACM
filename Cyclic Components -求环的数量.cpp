#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<stack>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 2e5 + 10;
vector<int> graph[maxn];	//邻接表 
int v = 0,e = 0;
bool vis[maxn];
void dfs_rm(int x){
	stack<int > st;
	st.push(x);
	
	while(!st.empty()){
		int u = st.top();
		int flag = 0;
		for(size_t i = 0;i < graph[u].size();++i){
			if(vis[graph[u][i]] == 0){
				vis[graph[u][i]] = 1;
				st.push(graph[u][i]);//将相邻节点压入栈中 
				flag = 1;
			}	
		}
		if(flag == 0){
			st.pop();
		}
	}
	
	
} 
int main(){
	std::ios::sync_with_stdio(false);
	int v1 = 0,v2 = 0;
	cin >> v >> e;
	memset(vis,0,sizeof(vis));
	for(int i = 0;i < e;++i){
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	
	for(int i = 1;i <= v;++i ){//vis[i] == 1的节点说明是被排除的点，但被排除的点也可能度数为2 
								//不过好像只要深搜一遍即可，所以此条件没必要 
		if(graph[i].size() != 2){//  || vis[i] == 1){//节点的度数不可能构成环 
			vis[i] = 1;
			dfs_rm(i);
			/*
			for(size_t j = 0;j < graph[i].size();++j){//与它相连的节点也不可能属于环
				vis[graph[i][j]] = 1;
				dfs_rm(i);	//他所能遍历到的节点也不可能属于环 ,剪枝 
			}
			*/
		}
	}
	int cnt = 0;
	for(int i = 1;i <= v;++i){
		if(vis[i] == 0 && graph[i].size() == 2){
			vis[i] = 1;
			++cnt;
			dfs_rm(i);
		}
	}
	cout << cnt << endl;
	
	
	return 0;
} 
