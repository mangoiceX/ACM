#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

typedef long long LL;

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 100;
int n = 0,m = 0; 
//string str;
char str[1000];
//vector<int> vt[maxn];
int s[maxn+10],sy[maxn+10];
int mp[maxn+2][maxn+2];
int ans = 20;
bool vis[maxn+10];
int id[maxn+10];
void dfs(int cur,int bw){
	if(cur == n){
		//if(bw != 0 && bw < ans){
			//memcpy(sy,s,sizeof(s));
		memcpy(sy,s,sizeof(s));
		ans = bw; 
		//}
		return ;
	}
	
	for(int i = 0;i < n;++i){
		if(vis[i]){
			continue;
		}
		int tmp = bw;
		s[cur] = id[i];
		//最理想化剪枝
		 
		per(j,0,cur-1){
			if(mp[id[i]][s[j]] == 1 || mp[s[j]][id[i]] == 1){
				bw = max(bw,cur-j);
				//j = cur;//退出两重循环 
				break;
			}
		}
		if(bw < ans){//最优性剪枝 
			vis[i] = true;
			dfs(cur+1,bw);
			vis[i] = false;
		} 
		bw = tmp;
	}
}
int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%s",str) && str[0] != '#'){
		memset(vis,false,sizeof(vis));
		memset(mp,0,sizeof(mp));
		ans = 20;
		set<int> st;
		//if(strcmp(str,"#") == 0){
		//	break;
		//}
		int size = strlen(str);
		int i = 0;
		while(i < size){
			int node = str[i] - 'A';
			st.insert(node);
			i += 2;
			while(i < size && str[i] != ';'){
				st.insert(str[i] - 'A');
				mp[str[i] - 'A'][node] = 1;
				mp[node][str[i] - 'A'] = 1;
				++i;
			}
			++i;
		}
		int cnt = 0;
		set<int>::iterator it = st.begin();
		for(it = it;it != st.end();++it){
			id[cnt++] = *it;
		} 
		n = st.size();
		dfs(0,0);
		per(j,0,n-1){
			printf("%c ",'A' + sy[j]);
		}
		printf("-> %d\n",ans);
	}
	
	return 0;
}

