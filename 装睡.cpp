#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 1e5;
int n = 0;
int main(){
	while(~scanf("%d",&n)){
		string name;
		vector<string> ans;	
		per(i,1,n){
			int x = 0,y = 0;
			cin >> name;
			scanf("%d %d",&x,&y);
			if(x >= 15 && x <= 20 && y >= 50 && y <= 70){
				continue;
			}
			ans.push_back(name);
		}
		per(i,0,ans.size()-1){
			cout << ans[i]  << "\n";
		}
	}
	
	
	return 0;
}
