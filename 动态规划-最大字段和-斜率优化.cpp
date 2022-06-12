#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+233;
ll a[maxn],b[maxn],f[maxn];
int q[maxn];
int l=1,r=1;
int n;
int brf(int k)
{
    if(l == r) return q[l];
    int L=l,R=r;
    while(L<R)
    {
        int mid=(L+R)>>1;
        if(b[q[mid + 1]] * q[mid + 1] - a[q[mid + 1]] - b[q[mid]] * q[mid] + a[q[mid]] 
            >= b[k] * (q[mid + 1] - q[mid])) L = mid + 1;
        else R = mid;
    }
    return q[L];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        b[i]=b[i-1]+k;
        a[i]=a[i-1]+k*i;
    }
    memset(f,0x3f,sizeof f);
    f[0]=0;
    q[1]=0;
    ll ans=-0x7ffffffff;
    for(int i=1;i<=n;i++)
    {
        int p=brf(i);
        f[i] = a[i] - a[p] - b[i] * p + b[p] * p;
        while(l < r && (b[i] * i - a[i] - b[q[r]] * q[r] + a[q[r]]) * (q[r] - q[r - 1]) 
            >= (b[q[r]] * q[r] -a[q[r]] - b[q[r - 1]] * q[r - 1] + a[q[r - 1]]) * (i - q[r])) r--;
        ans=max(ans,f[i]);
        q[++ r]=i;
    }
    cout<< ans;
}

