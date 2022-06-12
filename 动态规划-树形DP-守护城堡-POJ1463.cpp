#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 1500 + 10;
int dp[maxn][2];
bool is_root[maxn];
int n = 0;
vector<int> vt[maxn];
void dfs(int u){
	dp[u][0] = 0;
	dp[u][1] = 1;
	for(int i = 0;i < vt[u].size();++i){
		int v = vt[u][i];
		dfs(v);
		dp[u][1] += min(dp[v][0],dp[v][1]);
		dp[u][0] += dp[v][1];
	}
}
int main(){
	while(~scanf("%d",&n)){
		fill(is_root,is_root+n+1,true);
		for(int i = 0;i < n;++i){
			vt[i].clear();
		}
		/*
		for(int i = 0;i < n;++i){
			char str[5];
			scanf("%s",str);
			for(int j = 0;j < str[3] - '0';++j){
				int e = 0;
				scanf("%d",&e);
				is_root[e] = false;
				vt[str[0] - '0'].push_back(e);
			}
		}
		*/
		for(int i = 0;i < n;++i){
			int s = 0,num = 0;
			scanf("%d:(%d)",&s,&num);//格式输入，使用char会MLE，可能非法访问内存 
			for(int j = 0;j < num;++j){
				int e = 0;
				scanf("%d",&e);
				is_root[e] = false;
				vt[s].push_back(e);
			}
		}
		int root = 0;
		for(int i = 0;i < n;++i){
			if(is_root[i]){
				root = i;
				break;
			}
		}
		dfs(root);
		printf("%d\n",min(dp[root][1],dp[root][0]));
	}
	
	return 0;
}
