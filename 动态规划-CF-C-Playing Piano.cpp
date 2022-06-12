#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

typedef long long LL;

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 1e5;
int n = 0,m = 0;
int a[maxn+10],b[maxn+10];
int dp[maxn+10][6];
//dp[i][j]��ʾ��i������jʱi-1λ������� 
void solve(){
	fill(dp[0],dp[0] + (maxn + 10) * 6,0);
	per(i,1,5){//��ʼ�� 
		dp[1][i] = 1;
	}
	
	per(i,2,n){
		per(j,1,5){
			if(a[i] >= a[i-1]){
				per(k,1,j-1){
					if(dp[i-1][k] != 0){
						dp[i][j] = k;
						//break;//��break����AC���Ǿ�Ȼ�Ȳ���break����һЩ 
					}
				}
			}
			//���治����else if �������3���������-1 
			if(a[i] <= a[i-1]){
				per(k,j+1,5){
					if(dp[i-1][k] != 0){
						dp[i][j] = k;
						//break;
					}
				}
			}
		}
	}
	
	int ans = -1;
	per(i,1,5){
		if(dp[n][i] != 0){
			ans = i;
			break;
		}
	}
	if(ans == -1){
		printf("-1\n");
		return ;
	}
	rep(i,n,1){
		b[i] = ans;
		ans = dp[i][ans];
	}
	
	per(i,1,n){
		printf("%d%c",b[i],i == n ? '\n' : ' ');
	}
}
int main(){
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		solve();
	}
	
	return 0;
}

