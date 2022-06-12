// #include<iostream>
#include<bits/stdc++.h>
using namespace std;
int T,n,k,a[100010];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k); 
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1,cmp);
        long long left=k,cnt=n-1;
        for(int i=2;i<=n;i++)
        {
            if(i==n)
            {
                left+=a[i];
                break;
            }
            if(a[i]<=k)
            {
                if(cnt>=1) left+=k,cnt--;
                else       left+=a[i];
            }
            else
            {
                cnt-=a[i]/k;
                left+=a[i];
            }
        }
        printf("%lld\n",left);
    }
}
