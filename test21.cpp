#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
int a[N],b[N],n,nn,m;
struct node
{
    int l,r,num;
    ll val;
}tree[N<<2];
void build(int l,int r,int cur)
{
    tree[cur].l=l;
    tree[cur].r=r;
    tree[cur].val=0;
    tree[cur].num=0;
    if(l==r)
        return ;
    int m=(l+r)>>1;
    build(l,m,cur<<1);
    build(m+1,r,cur<<1|1);
    return ;
}
int query(int cur,int val)
{
    if(tree[cur].val<=val)
        return tree[cur].num;
    if(tree[cur].l==tree[cur].r)
        return min(tree[cur].num,val/b[tree[cur].l]); 
    if(tree[cur<<1].val>=val)
        return query(cur<<1,val);
    else 
		return tree[cur<<1].num+query(cur<<1|1,val-tree[cur<<1].val);
}
void update(int tar,int cur)
{
    if(tree[cur].l==tree[cur].r)
    {
        tree[cur].val+=b[tar];
        tree[cur].num++;
        return ;
    }
 
    if(tar<=tree[cur<<1].r) update(tar,cur<<1);
    else update(tar,cur<<1|1);
    
    tree[cur].val=tree[cur<<1].val+tree[cur<<1|1].val;
    tree[cur].num=tree[cur<<1].num+tree[cur<<1|1].num;
    return ;
}
int main(void)
{
    int t,pos;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),b[i]=a[i];
        sort(b+1,b+1+n);
        nn=unique(b+1,b+1+n)-(b+1);
        build(1,nn,1);
        
        for(int i=1;i<=n;i++)
        {
            if(i==1)
                printf("0 ");
            else printf("%d ",i-1-query(1,m-a[i]));
            pos=lower_bound(b+1,b+1+n,a[i])-b;
            update(pos,1);
        }
        printf("\n");
    }
    return 0;
}