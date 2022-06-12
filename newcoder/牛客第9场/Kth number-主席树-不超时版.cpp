#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include<iomanip>
// #include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FOR2(i,a,b) for(int i=a;i<=b;i++)
#define sync ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define MAXN 100010
using namespace std;
typedef struct{
    int l,r,sum;
}NODE;NODE nodes[20*MAXN];
int root[MAXN],a[MAXN],b[MAXN];
int n,m,cnt,p;

int getid(int x){//离散化 
    return lower_bound(b+1,b+1+p,x)-b;
}
void build(int l,int r,int &cur){//建立空树 
    nodes[cur].sum=nodes[cur].l=nodes[cur].r=0;
    cur=++cnt;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(l,mid,nodes[cur].l);
    build(mid+1,r,nodes[cur].r);
}
void update(int l,int r,int &cur,int pre,int pos){
    cur=++cnt;//表示新开的节点 
    nodes[cur].l=nodes[pre].l;
    nodes[cur].r=nodes[pre].r;
    nodes[cur].sum=nodes[pre].sum+1;//记录该点该时间之前有多少的数字 
    if(l==r)return ;
    int mid=(l+r)>>1;//每次按照pos的值插入到1~p的范围中 
    if(pos<=mid)update(l,mid,nodes[cur].l,nodes[pre].l,pos);
    else update(mid+1,r,nodes[cur].r,nodes[pre].r,pos);
}
int query(int l,int r,int x,int y,int key){
    if(l==r)return l;
    int mid=(l+r)>>1;
    int sum=nodes[nodes[y].l].sum-nodes[nodes[x].l].sum;//时间区间内个数 
    if(key<=sum)//查找右区间 
        return query(l,mid,nodes[x].l,nodes[y].l,key);
    else//查找左区间 
        return query(mid+1,r,nodes[x].r,nodes[y].r,key-sum);
}
void start(){
    int x,y,k;

    // memset(root,0,sizeof(root));
    cnt=0;
    FOR2(i,1,n){
        // cin>>a[i];
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    cnt=0;
    sort(b+1,b+n+1);//离散化 
    p=unique(b+1,b+n+1)-b-1;//数据范围 
    build(1,p,root[0]); //建立时间点为0 的空树 
    FOR2(i,1,n)//i表示时间 ，按时间插入a[i]元素到线段树 
        update(1,p,root[i],root[i-1],getid(a[i])); //按照a[i]在b[i]中的大小插入到不同位置 
    while(m--){
        // cin>>x>>y>>k;//k=y-x-k+2;第K大和第K小的差别 
        scanf("%d %d %d",&x,&y,&k);//k=y-x-k+2;第K大和第K小的差别 
        // cout<<b[query(1,p,root[x-1],root[y],k)]<<endl;//区间第K大就是求 时间区间的第K大 
        printf("%d\n",b[query(1,p,root[x-1],root[y],k)]);
    }
}
int main(){
    // std::ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    int T;
    // cin>>t;
    scanf("%d",&T);
    while(T--){
        memset(root,0,sizeof(root));
        // cin>>n>>m;
        scanf("%d %d",&n,&m);
        start();
    }

    //  while(~scanf("%d %d",&n,&m)){
    //     memset(root,0,sizeof(root));
    //     // cin>>n>>m;
        
    //     start();
    // }
    return 0;
}