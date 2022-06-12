#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 300; 
int dp[300];
int main()
{
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i=1; i<= 17; i++)
    {
        for(int j=i*i; j<=maxn; j++)
            dp[j] += dp[j-i*i];
    }
    int n;
    while(scanf("%d",&n) != EOF && n != 0)
    {
        printf("%d\n",dp[n]);
    }
}
