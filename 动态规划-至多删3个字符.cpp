#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<vector>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f
#define Irish_Moonshine main
const int maxn = 1e6 + 10;
char str[maxn];
ll dp[maxn][4];
int main()
{
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i <= len; i++) dp[i][0] = 1;
    dp[0][1] = 1;
    for (int i = 1; i < len; i++) {
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        if (str[i] == str[i - 1]) dp[i][1]--;

    }
    dp[1][2] = 1;
    for (int i = 2; i < len; i++) {
        dp[i][2] = dp[i - 1][1] + dp[i - 1][2];
        if (str[i] == str[i - 1]) dp[i][2] -= dp[i - 2][1];
        else if (str[i] == str[i - 2]) dp[i][2]--;
    }
    dp[2][3] = 1;
    for (int i = 3; i < len; i++) {
        dp[i][3] = dp[i - 1][3] + dp[i - 1][2];
        if (str[i] == str[i - 1]) dp[i][3] -= dp[i - 2][2];
        else if (str[i] == str[i - 2]) dp[i][3] -= dp[i - 3][1];
        else if (str[i] == str[i - 3]) dp[i][3]--;
    }
    for(int i = 0;i < len;++i){
    	for(int j = 0;j <= 3;++j){
    		printf("%d ",dp[i][j]);
		}
		puts("");
	}
    ll ans = dp[len - 1][0] + dp[len - 1][1] + dp[len - 1][2] + dp[len - 1][3];
    printf("%lld\n", ans);
    return 0;
}

