/*  
Function：Tarjan无向图求割点割桥, O(n+m), 无重边/重边情况均可处理 
1. 求出所有的桥，再将 
*/
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<=b; ++i)
#define repp(i,a,b) for(int i=b; i>=a; --i)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int>vi;
const int maxn = 2e4+7;
// 建边 
struct edge{
    int to, next;
}e[maxn << 1]; //两倍空间 
int fi[maxn], id=0;
void adde(int u, int v){
    e[id].to = v;
    e[id].next = fi[u];
    fi[u] = id++;
    return ;
}
int dfn[maxn], low[maxn], sig;  
bool cut[maxn]; //是否为割点

typedef pair<int, int> pii; 
vector<pii>cutbg; //保存割桥

void init(){
    ms(fi, -1), ms(dfn, 0), ms(low, 0), ms(cut, false);
    sig = id = 0;
    cutbg.clear();
    return ;
} 
void tarjan(int u,int eid) // eid指父亲边   
{  
    low[u] = dfn[u] = ++sig;  
    int i, son = 0; // 记录子树 
    for(i = fi[u]; ~i; i = e[i].next){  
        int to = e[i].to;  
        if( i == (eid^1) ) continue;  //重边 
        if( !dfn[to] ){  
            son++;
            tarjan( to, i );  

            low[u]=min(low[u],low[to]);  
            if(low[to] > dfn[u]){ // 判断割桥 
                cutbg.push_back(make_pair(u, e[i].to)); 
            }
            if(low[to] >= dfn[u]){ // 判断割点 
                cut[u] = true;
            }
        }  
        else low[u]=min(low[u],dfn[to]);  
    }  
    if(eid == -1 && son <= 1) cut[u] = 0; // 当u为根节点，且u只有一个子树或没有子树的时候 , u一定不是割点 
}  
int main(){
    int T = 0;
    scanf("%d",&T);
    int n, m;
    while(T--){
        scanf("%d%d",&n,&m);
        init();
        int u, v;
        rep(i, 1, m){  
            scanf("%d%d",&u,&v);  
            adde(u,v);
            adde(v, u); 
        }  
        tarjan(1,-1); // 若确定为联通图
        /*
            若不确定是否是联通图
            rep(i, 1, n){
                if(!dfn[i]){
                    tarjan(i,-1);
                }
            }
        */ 
        int len = cutbg.size();
        printf("%d\n",len);
    }  
    return 0;
}

