#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[55],b[55],cnt=0,num=0,c[55];
int n,m,T,flag=0;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        cnt=0;num=0;
        while(n>0)
        {
            a[++cnt]=n%2;
            n/=2;
        }
        while(m>0)
        {
            b[++num]=m%2;
            m/=2;
        }
        int flag=0;
        long long ans=0;
        for(int i=1;i<=max(num,cnt);i++)
        {
            
            if(a[i]==0&&b[i]==0) c[i]=0;
            if(a[i]==1&&b[i]==0) c[i]=0;
            if(a[i]==0&&b[i]==1) c[i]=0;
            if(a[i]==1&&b[i]==1) {c[i]=1;flag=1;}
        }
        // if(flag==0) {printf("1\n");continue;}
        if(flag == 0){
            int res = 1;
            for(int i = 1;i <= max(num,cnt);++i){
                if(!(a[i] == 0 && b[i] == 0)){
                    printf("%d\n",res);
                    break;
                }
                res <<= 1;
            }
            continue;
        }
        long long res=1;
        for(int i=1;i<=max(num,cnt);i++)
        {
            ans=ans+1ll*c[i]*res;res*=2;
        }
        printf("%lld\n",ans);
    }
}
