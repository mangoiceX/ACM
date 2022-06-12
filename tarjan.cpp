#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5;
vector<int> a[maxn+10];
int dfn[maxn+10];
int low[maxn+10];int vis[maxn+10];
int cnt=1;
int dig=0;
//这里是tarjan代码模板核心
void tarjan(int w,int u){
    vis[u]=1;
    low[u]=dfn[u]=(cnt++);
    for(int i=0;i<a[u].size();i++){
        int v = a[u][i];
        if(v==w) continue;//因为是无向图，防止向后返回去遍历
        if(vis[v]!=1) tarjan(u,v);//没有便利过，就接着向下遍历，直到找到后，再执行下面的代码，也就是回溯。
        if(vis[v]==1) low[u]=min(low[u],low[v]);
    }
    if(low[u]==dfn[u]){
        dig++;
    }
}
void init(){//初始化函数
    memset(dfn,0,sizeof dfn);
    memset(low,0,sizeof low);
    memset(vis,0,sizeof vis);
}
int main(){
    int n,m;
    cin>>n>>m;
    init();
    for(int i=0;i<m;i++){
        int k1,k2;
        cin>>k1>>k2;
        a[k1].push_back(k2);
        a[k2].push_back(k1);
    }
    tarjan(1,1);
    //cout << m - (dig-1) << endl;//求不是割边的边 
    cout<<dig-1<<endl;//求割边 
    return 0;
}
