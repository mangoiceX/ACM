#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int A[maxn+10];
int n = 0,m = 0;
int maxd = 0;
bool vis[maxn+10];
int ans[maxn+10];
int ct = 0;
bool check(int *a){
	map<int,int> mp;
	for(int i = 1;i <= maxd;++i){
		++mp[a[i]];
		if(m - a[i] == a[i]){
			continue;
		}
		++mp[m - a[i]];
	}
	for(int i = 1;i <= maxd;++i){
		if(mp[a[i]] == 2){
			return true;
		}
	}
	return false;
}
bool dfs(int depth,int* ans,int cnt){
	if(depth == n){
		if(cnt < maxd){
			return true;
		}
	}
	if(cnt == maxd){
		++ct;
		cout << "nima " << cnt << endl;
		//for(int i = 1;i <= cnt;++i){
		//	cout << "nihao " << ans[i] << endl;
	//	}
		//if(check(ans)){
		//	cout <<"hahaa" << endl;
		//}
		return check(ans);
	}
	for(int i = depth+1;i <= n;++i){
		ans[cnt+1] = A[i];
		if(dfs(i,ans,cnt+1) == false){
			return false;
		}
		if(dfs(i,ans,cnt) == false){
			return false;	
		}
	}
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
			ct = 0;
			if(dfs(0,ans,0)){
				printf("%d\n",maxd);
				flag = true;
				cout << maxd << " ju " << ct << endl;
				break;
			}
		
		}
		if(flag == false){
			printf("There is no answer!!!\n");
		}
	}
	
	return 0;
}
