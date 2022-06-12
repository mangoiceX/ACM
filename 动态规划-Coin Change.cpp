#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
    
int a[5] = {1,5,10,25,50};
const int maxn = 300;
const int maxnums = 100;
int dp[maxn][110];  // dp[i][j] ��ʾ���ǻ����ܶ�ǡ��Ϊiʱ�� �������û���������С�ڵ���j �ķ�������
int main(){	//dp[j][k] = dp[j-a[i]][k-1] + a[i]; // j��С����  k��С���� i��������
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=100;i++){
		dp[0][i] = 1;
	}
	for(int i=0;i<5;i++){
		for(int j=a[i];j<=300;j++){
			for(int k=1;k<=100;k++)  {
				dp[j][k] += dp[j-a[i]][k-1] ;
			}
		}
	}

    int x;
	while(scanf("%d",&x) != EOF){
		printf("%d\n",dp[x][100]);
	}
    return 0;
}

