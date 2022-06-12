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
const int maxn = 1e2;
int n = 0,l = 0;
int cnt = 0; 
int s[maxn+10]; 
bool dfs(int cur){
	if(cnt == n){//递归结束 
		per(i,0,cur-1){//从0开始可以避免多打空格，不从1开始
			
			if(i % 64 == 0 && i != 0){//这个时候就不用打空格了 
				printf("\n");
			}else if(i % 4 == 0 && i != 0){
				printf(" ");
			}
			printf("%c",'A' + s[i]);
		}
		printf("\n");
		printf("%d\n",cur);
		return true;
	}
	for(int i = 0;i < l;++i){
		s[cur] = i;
		bool hard = true;
		for(int j = 1;2*j <= cur+1;++j){//只用检查后缀，前面的已经在之前判断过了 
			bool easy = true;
			for(int k = 0;k < j;++k){
				if(s[cur-k] != s[cur-k-j]){
					easy = false;
					break;
				}
			}
			if(easy == true){
				hard = false;
				break;
			}
		}
		if(hard == true){
			++cnt;
			if(dfs(cur+1) == true){
				return true;//这里是返回true,而不是false; 
			}
		}
	}
	return false;	
}
int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%d %d",&n,&l) && n && l){
		cnt = 0;
		dfs(0);
	}
	return 0;
}

