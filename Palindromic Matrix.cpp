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
const int maxn = 30;
int n = 0,m = 0;
int a[maxn+10][maxn+10];
int b[500];
int num[1000+10];
int sig = 0;
void solve(){
	//set<int> st;
	int ans[1000+10],cnt = 0;
	per(i,1,1000){
		if(num[i] >= 4){
			cout <<"niam " << i <<endl;
			ans[++cnt] = i;
		}
	}
	int mid = (n+1)/2;
	int pi = 1;
	if(n & 1){
		a[mid][mid] = sig;
		--num[sig];
		per(i,1,n-1){
			per(j,1,n-1){
				a[i][j]  = ans[pi];
				a[n-i+1][n-j+1] = ans[pi];
				a[n-j+1][n-i+1] = ans[pi];
				a[j][i] = ans[pi++];
			}
		}
	}else{
		per(i,1,n-1){
			per(j,1,n-1){
				//a[i][j] = a[n-i+1][n-j+1] = a[n-j+1][n-i+1] = a[j][i] = ans[pi++];
				a[i][j]  = ans[pi];
				a[n-i+1][n-j+1] = ans[pi];
				a[n-j+1][n-i+1] = ans[pi];
				a[j][i] = ans[pi++];
			}
		}
	}
	printf("YES\n");
	per(i,1,n){
		per(j,1,n){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
int main(){
	while(~scanf("%d",&n)){
		memset(num,0,sizeof(num));
		per(i,1,n*n){
			scanf("%d",&b[i]);
			++num[b[i]];
		}
		int cnt = 0;
		int flag = 0;
		per(i,1,1000){
			if(num[i] != 0 && num[i] < 4 && (num[i] % 2 == 0)){
				++cnt;
			}
			if(num[i] & 1){
				++flag;
				sig = i;
			}
			if(flag > 1 || cnt >= 1){
				printf("NO\n");
				return 0;
			}
			if(flag == 1 && (n % 2 == 0)){
				printf("NO\n");
				return 0;
			}
		}
		solve();
	}
	
	
	return 0;
}

