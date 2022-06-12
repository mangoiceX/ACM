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
const int maxn = 16;
int n = 0;
int num[maxn+10]; 
bool vis[maxn+10],isp[2*maxn];//注意空间要足够用，写代码时，要时刻注意一些细节，否则调试半天 

void init(){	
	memset(isp,true,sizeof(isp));
	isp[0] = isp[1] = false;
	per(i,2,6){
		if(isp[i]){
			for(int j = i*i;j <= 32;j += i){
				isp[j] = false;
			}
		}
	}
}
void dfs(int curr){
	if(curr == n && isp[num[n-1] + num[0]]){
		printf("%d",num[0]); 
		per(i,1,n-1){
			printf(" %d",num[i]);
		}
		printf("\n");
	}else{
		per(i,2,n){
			if(!vis[i] && isp[num[curr-1] + i]){
				num[curr] = i;
				vis[i] = true;
				dfs(curr+1);
				vis[i] = false;
			}
		}
	}
}
int main(){
	init();
	//std::ios::sync_with_stdio(false);
	int kase = 0;
	num[0] = 1;//第一个数一定是1 
	while(~scanf("%d",&n)){
		memset(vis,false,sizeof(vis));
		if(kase != 0){//最后一个样例后面不能有空行 
			printf("\n");
		}
		printf("Case %d:\n",++kase);
		dfs(1);
	
	}
	
	return 0;
}

