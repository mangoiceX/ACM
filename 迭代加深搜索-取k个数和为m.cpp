#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int A[maxn+10];
int n = 0,m = 0;
int maxd = 0;
bool vis[maxn+10];
bool dfs(int depth,int sum){
	if(depth == maxd){
		cout << "niam " << depth << " " << sum << endl;
		return sum == m;
	}
	//for(int i = depth+1;i <= n;++i){
	
		//if(vis[i]){
		//	continue;
	//	}
	vis[depth+1] = true;
	if(dfs(depth+1,sum + A[depth+1]) == false || dfs(depth+1,sum) == false){
		vis[depth+1] = false;
		return false;
	}
	vis[depth+1] = false; 
	//}
	return true;
}
int main(){
	while(~scanf("%d",&n)){
		for(int i = 1;i <= n;++i){
			scanf("%d",&A[i]);
		}
		scanf("%d",&m);
		sort(A+1,A+1+n);
		bool flag = false;
		for(maxd = 1;maxd <= n;++maxd){
			memset(vis,false,sizeof(vis));
			if(dfs(0,0)){
				printf("%d\n",maxd);
				flag = true;
				break;
			}
		}
		if(flag == false){
			printf("There is no answer!!!\n");
		}
	}
	
	return 0;
}
