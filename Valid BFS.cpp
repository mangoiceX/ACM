#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 100;
vector<vector<int> > mp(maxn);
int a[maxn];
int vis[maxn];
int n = 0;
bool bfs(){
	queue<int> que;
	que.push(1);
	int cnt = 1;
	while(!que.empty() && cnt < n){
		int u = que.front();
		vis[u] = 1;
		que.pop();
		for(int j = 0;j < mp[u].size();++j){
			int flag = 0;
			for(int i = 0;i < mp[u].size();++i){
				//cout << "e "<< a[cnt] << "haha "<< mp[u][i] << "nan " <<u<< endl;
				if(mp[u][i] == a[cnt] && vis[a[cnt]] == 0){
					que.push(a[cnt]);
					++cnt;
					if(cnt == n-1){
						return true;
					}
					flag = 1;
					break;
				}
			}
			if(cnt == n-1){
				return true;
			}
			if(flag == 0){
				//cout << "en " << cnt << endl;
				return false;
			}
		}
	}
	return true;
}
int main(){
	while(scanf("%d",&n) != EOF){
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		for(int i = 0;i < n-1;++i){
			int x = 0,y = 0;
			scanf("%d %d",&x,&y);
			mp[x].push_back(y),mp[y].push_back(x);
		}
		for(int i = 0;i < n;++i){
			scanf("%d",&a[i]);
		}
		if(a[0] != 1){
			printf("No\n");
			continue;
		}
		if(bfs()){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	
	return 0;
}
