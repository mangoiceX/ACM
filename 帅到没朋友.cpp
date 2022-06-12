#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 1e5;
int n = 0,m = 0,k = 0; 
int main(){
	while(~scanf("%d",&n)){
		map<int,int> mp,fg;
		per(i,1,n){
			scanf("%d",&m);
			per(i,1,m){
				int x = 0;
				scanf("%d",&x);
				if(m >= 2){
					++mp[x];
				}
			}
		}
		scanf("%d",&k);
		vector<int> ans;
		per(i,1,k){
			int x = 0;
			scanf("%d",&x);
			if(mp[x] == 0 && fg[x] == 0){
				ans.push_back(x);
				++fg[x];
			}
		}
		if(ans.size() == 0){											
			puts("No one is handsome");
			continue;
		}
		for(int i = 0;i < ans.size();++i){
			printf("%d%c",ans[i],i == ans.size()-1 ? '\n' : ' ');
		}
	}
	
	
	return 0;
}
