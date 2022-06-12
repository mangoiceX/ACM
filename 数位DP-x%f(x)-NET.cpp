#include <bits/stdc++.h>
using namespace std;
int num[12];
int dp[12][85][85][85];
int dfs(int len,int sum,int mod,int tmp ,int f){
    if(len<0)
    return sum==tmp&&mod==0;
    if(!f&&dp[len][sum][mod][tmp]!=-1)
    return dp[len][sum][mod][tmp];
    int fp=f?num[len]:9;
    int ret=0;
    for(int i=0;i<=fp;i++)
    {
        ret+=dfs(len-1,sum+i,(mod*10+i)%tmp,tmp,f&&i==fp);
    }
    if(!f)
    dp[len][sum][mod][tmp]=ret;
    return ret;
}
int get_num(int x){
    int len=0;
    while(x)
    {
        num[len++]=x%10;
        x=x/10;
    }
    int ans=0;
    for(int i=1;i<=81;i++)
    ans+=dfs(len-1,0,0,i,1);
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    int p=0;
    while(t--){
        p++;
        int a,b;
        scanf("%d %d",&a,&b); 
        printf("Case %d: ",p);
        printf("%d\n",get_num(b)-get_num(a-1));
    }
    return 0;
}

