#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 100050
#define INF 2000000010
int a[N];
struct Node
{
    int v,id;
}sum[N];
bool cmp(Node a,Node b)
{
    return a.v<b.v;
}
int main()
{
    int n,k,t;
    while(~scanf("%d %d",&n,&k)&&(n+k))
    {
        sum[0].v=0;sum[0].id=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i].v=sum[i-1].v+a[i];
            sum[i].id=i;
        }
        sort(sum,sum+1+n,cmp);
        int ans;
        while(k--)
        {
            scanf("%d",&t);
            ans=INF;
            int l=0,r=1;
            int anss,ansl,ansr;
            while(l<=n&&r<=n)
            {
                int w=abs(sum[r].v-sum[l].v);
                int q=abs(w-t);
                if(q<ans)
                {
                    anss=w;
                    ans=q;
                    ansl=sum[l].id;
                    ansr=sum[r].id;
                }
                if(w>t) l++;
                else if(w<t) r++;
                else break;
                if(l==r) r++;
            }
            if(ansl>ansr) swap(ansl,ansr);
            printf("%d %d %d\n",anss,ansl+1,ansr);
        }
    }
    return 0;
}
