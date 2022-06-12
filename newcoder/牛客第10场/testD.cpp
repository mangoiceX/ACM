#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=100000+10;
int n;
ll a[N],r[N];
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1,y=0;return a;
    }    
    ll ret=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return ret;
}
ll excrt(){
    ll M=a[1],R=r[1],x,y,d;
    for(int i=2;i<=n;i++){
        d=exgcd(M,a[i],x,y);
        if((R-r[i])%d) return -1;
        x=(R-r[i])/d*x%a[i];
        R-=M*x;
        M=M/d*a[i];
        R%=M;
    }
    return (R%M+M)%M;
}
int main()
{
    ll m = 0;
    while(scanf("%d %lld",&n,&m)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%lld%lld",&a[i],&r[i]);
        }
        ll ans = excrt();
        if(ans > m){
            puts("he was probably lying");
            continue;
        }
        if(ans == -1){
            puts("he was definitely lying");
            continue;
        }
       printf("%lld\n",ans);
    }
    return 0;
}
