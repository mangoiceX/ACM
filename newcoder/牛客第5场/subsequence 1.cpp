// #include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define mod 998244353
typedef long long LL;
int T,m,n;
char s1[3300],s2[3300];
int dp[3300][3300];
LL fac[3300],inv[3300];
void init(int N){
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<=N;i++)
        fac[i]=(LL)fac[i-1]*i%mod;
    for(int i=2;i<=N;i++)
        inv[i]=(LL)(mod-mod/i)*inv[mod%i]%mod;
    for(int i=2;i<=N;i++)
        inv[i]=(LL)inv[i]*inv[i-1]%mod;
}
int C(int n,int m){
    if(n<m) return 0;
    return (int)fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
    init(3000);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        // memset(dp,0,sizeof(dp));
        per(i,0,n){
            per(j,0,m){
                dp[i][j] = 0;
            }
        }
        scanf("%s%s",s1,s2);
        for(int i=n-1;i>=0;i--)
            for(int j=m-1;j>=0;j--){
                if(s1[i]>s2[j]){
                    dp[i][j]=(dp[i][j]+C(n-1-i,m-j-1))%mod;
                    dp[i][j]=(dp[i][j]+dp[i+1][j])%mod;
                }
                if(s1[i]==s2[j]){
                    dp[i][j]=(dp[i][j]+dp[i+1][j+1])%mod;
                    dp[i][j]=(dp[i][j]+dp[i+1][j])%mod;
                }
                if(s1[i]<s2[j])  dp[i][j]=dp[i+1][j]%mod;
            }  
        int ans=dp[0][0];
        for(int i=0;i<n;i++)
            if(s1[i]!='0'&&n-1-i>=m)
                for(int j=m;j<=n-1-i;j++)
                    ans=(ans+C(n-1-i,j))%mod;
        printf("%d\n",ans);
    }
    return 0;
}
