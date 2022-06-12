#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 1e5;
int n = 0,m = 0;
int main(){
	while(~scanf("%d",&n)){
		vector<int> vt;
		per(i,1,n){
			int x = 0;
			scanf("%d",&x);
			if(x&1){
				vt.push_back(x);
			}
		}
		sort(vt.begin(),vt.end());
		per(i,0,vt.size()-1){
			printf("%d%c",vt[i],i == vt.size()-1 ? '\n' : ','); 	
		}
	}	
	return 0;
}
