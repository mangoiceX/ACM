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
const int maxn = 3e5;
int n = 0,m = 0;
vector<int> g[maxn+10];
bool vis[maxn+10];
bool color[maxn+10];
void bfs(int s){
    per(i,1,n){
        color[i] = false;
    }
    queue<int> que;
    que.push(s);
    vis[s] = true;
    color[s] = true;
    int depth = 0;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        int size = g[u].size();
        per(i,0,size-1){
            int v = g[u][i];
            if(!vis[v]){
                que.push(v);
                vis[v] = true;
                color[v] = !color[u];
            }
        }
    }
}
int main(){
    
    int T = 0;
    scanf("%d",&T);
    while(T--){
        memset(vis,false,sizeof(vis));
        scanf("%d %d",&n,&m);
        per(i,1,n){
            g[i].clear();
        }

        per(i,1,m){
            int x = 0,y = 0;
            scanf("%d %d",&x,&y);
            g[x].push_back(y); g[y].push_back(x);
        }
        bfs(1);
        int cnt = 0;
        per(i,1,n){
            if(color[i]){
                ++cnt;
            }
        }
        if(cnt <= n/2){
            printf("%d\n",cnt);
            per(i,1,n){
                if(color[i]){
                    printf("%d ",i);
                }
            }
            puts("");
        }else{
            printf("%d\n",n - cnt);
            per(i,1,n){
                if(!color[i]){
                    printf("%d ",i);
                }
            }
            puts("");
        }
    }
    
    return 0;
}

