//解一元线性同余方程组。

#include <iostream>
#include<cstdio>

using namespace std;

typedef long long ll;
ll m = 0;
ll ex_gcd(ll a,ll b,ll& x,ll& y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    ll r,tx,ty;
    r=ex_gcd(b,a%b,tx,ty);
    x=ty;
    y=tx-a/b*ty;
    return r;
}

int main(){
    ll i,n,a1,r1,a2,r2,ans,a,b,c,d,x0,y0;
    while(scanf("%lld %lld",&n,&m)!=EOF){
        bool flag = 1;
        bool fg0 = true,fg1 = false;
        scanf("%lld%lld",&a1,&r1);
        if(a1 != r1){
            fg0 =false;
        }
        if(a1 < r1){
            fg1 = true;
        }
        for( i=1;i<n;i++){
            scanf("%lld%lld",&a2,&r2);
            if(a2 != r2){
                fg0 =false;
            }
            if(a2 < r2){
                fg1 = true;
            }
            a = a1;
            b = a2;
            c = r2-r1;
            ll d = ex_gcd(a,b,x0,y0);
            if(c%d!=0){
                flag = 0;
            }
            ll t = b/d;
            x0 = (x0*(c/d)%t+t)%t;//保证x0为正
            r1 = a1*x0 + r1;
            a1 = a1*(a2/d);

        }
        if(fg0){
            puts("0");
            continue;
        }
        if(!flag || fg1){
            puts("he was definitely lying");
            continue;
        }
        if(r1 > m){
            puts("he was probably lying");
            continue;
        }
        printf("%lld\n",r1);
    }
    return 0;
}


