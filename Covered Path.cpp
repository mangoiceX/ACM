#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int maxn = 1e5 + 10;
int v1 = 0,v2 = 0;
int t = 0,d = 0;
int ans = 0,maxv = 0;
void dfs(int u,int time,int sum){
	if(abs(u-v2) > (t - time)*d){
		return ;
	}
	if(time == t){
		if(u == v2){
			ans = max(ans,sum);
			return ;
		}else{
			return ;
		}	
	}
	for(int i = 0;i <= d;++i){
		if(u - v2 < d){
			dfs(u + i,time + 1,sum + u + i);
		}else{
			dfs(u - i,time + 1,sum + u - i);	
		}
	}
}
int main(){
	scanf("%d %d",&v1,&v2);
	scanf("%d %d",&t,&d);
	dfs(v1,1,v1);
	printf("%d\n",ans);
	
	return 0;
} 
