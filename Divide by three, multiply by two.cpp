#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
typedef unsigned long long LL;
const int maxn = 100 + 5;
LL data[maxn];
LL ans[maxn];
bool vis[maxn];
int flag = 0;
//vector< vector<LL> > adj(maxn);
vector<int> adj[maxn];		//建立邻接表 
int n = 0;
void dfs(int loc,int cur){
	if(cur == n){
		flag = 1;
		for(int i = 0;i < n;++i){
			if(i != 0){
				cout << " ";
			}
			cout << ans[i];
		}
		cout << endl;
		return ;
	}
	vis[loc] = 1;
	for(size_t i = 0;i < adj[loc].size();++i){
		if(vis[adj[loc][i]] == 0){
			vis[adj[loc][i]] = 1;
			
			ans[cur] = data[adj[loc][i]];
			dfs(adj[loc][i],cur + 1);
			
			vis[adj[loc][i]] = 0;//记得还原操作 
		}
	}
}
int main(){
	
	std::ios::sync_with_stdio(false); //提高cin,cout的速度，使他的效果接近scanf,printf
	// 使用相同的stream缓冲区，缺省值是同步 ，使用该函数，取消同步 
  	flag = 0;
	cin >> n;
	for(int i = 0;i < n;++i){
		cin >> data[i];
	}
	
	for(int i = 0;i < n;++i){
		for(int j = 0;j < n;++j){//状态：当两者满足题意时，建立一条有向边 
			if(data[j] == 2* data[i] || data[i] == 3*data[j]){ //建立有向边 
				adj[i].push_back(j);//最终的一个答案就是深搜遍历整个图即可 
			}
		}
	}
	
	for(int i = 0;i < n;++i){
		memset(vis,0,sizeof(vis));
		memset(ans,0,sizeof(ans));
		ans[0] = data[i];//第一个数起点 
		dfs(i,1);
		if(flag == 1){//如果从一个顶点出发可以遍历完整个图，则可以退出 
			break;
		}
	}
	
	
	return 0;
}

