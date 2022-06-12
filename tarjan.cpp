#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5;
vector<int> a[maxn+10];
int dfn[maxn+10];
int low[maxn+10];int vis[maxn+10];
int cnt=1;
int dig=0;
//������tarjan����ģ�����
void tarjan(int w,int u){
    vis[u]=1;
    low[u]=dfn[u]=(cnt++);
    for(int i=0;i<a[u].size();i++){
        int v = a[u][i];
        if(v==w) continue;//��Ϊ������ͼ����ֹ��󷵻�ȥ����
        if(vis[v]!=1) tarjan(u,v);//û�б��������ͽ������±�����ֱ���ҵ�����ִ������Ĵ��룬Ҳ���ǻ��ݡ�
        if(vis[v]==1) low[u]=min(low[u],low[v]);
    }
    if(low[u]==dfn[u]){
        dig++;
    }
}
void init(){//��ʼ������
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
    //cout << m - (dig-1) << endl;//���Ǹ�ߵı� 
    cout<<dig-1<<endl;//���� 
    return 0;
}
