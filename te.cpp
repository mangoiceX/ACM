#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define R register int
const int N=200009,M=5000009;
int P,a[N],b[N],rt[N],lc[M],rc[M],s[M];
#define G c=getchar()
inline void in(R&z)
{
    register bool f=0;
    register char G;
    while(c<'-')G;
    if(c=='-')f=1,G;
    z=c&15;G;
    while(c>'-')z=(z<<3)+(z<<1)+(c&15),G;
    if(f)z=-z;
}
void build(R&t,R l,R r)
{
    t=++P;
    if(l!=r)
    {
        R m=(l+r)>>1;
        build(lc[t],l,m);
        build(rc[t],m+1,r);
    }
}//线段树操作，建一个空线段树
inline void insert(R*t,R u,R l,R r,R v)
{
    while(l!=r)
    {
        s[*t=++P]=s[u]+1;//注意这里要+1
        R m=(l+r)>>1;
        if(v<=m)r=m,rc[*t]=rc[u],t=&lc[*t],u=lc[u];
        else  l=m+1,lc[*t]=lc[u],t=&rc[*t],u=rc[u];
    }
    s[*t=++P]=s[u]+1;
}
inline int ask(R t,R u,R l,R r,R k)
{
    while(l!=r)
    {
        R m=(l+r)>>1,v=s[lc[u]]-s[lc[t]];
        if(k<=v)r=m,t=lc[t],u=lc[u];
        else  l=m+1,t=rc[t],u=rc[u],k-=v;
    }
    return b[l];
}
typedef long long ll;
int main()
{
    R n,m,i,l,r,sz;
    in(n);in(m);
    for(i=1;i<=n;++i)
        in(a[i]),b[i]=a[i];
    sort(b+1,b+n+1);
    sz=unique(b+1,b+n+1)-b-1;
    build(rt[0],1,sz);
    for(i=1;i<=n;++i)
        insert(&rt[i],rt[i-1],1,sz,lower_bound(b+1,b+sz+1,a[i])-b);
    while(m--)
    {
        in(l);in(r);int yy=r-l-1;
        if(r-l+1<3) {printf("-1\n");continue;}
        ll a1=ask(rt[l-1],rt[r],1,sz,r-l+1);
        ll a2=ask(rt[l-1],rt[r],1,sz,r-l);
        ll a3=ask(rt[l-1],rt[r],1,sz,r-l-1);
        while(a2+a3<=a1&&yy>1)
        {
            a1=a2;a2=a3;a3=ask(rt[l-1],rt[r],1,sz,yy-1);
            yy--;
        }
        if(yy==0){printf("-1\n");continue;}
        if(a2+a3<=a1){printf("-1\n");continue;}
        long long ans=a1+a2+a3;
        printf("%lld\n",ans);
    };
    return 0;
}
