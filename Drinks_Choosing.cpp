#include<bits/stdc++.h>
// #include<iostream>
// #include<cstdio>
// #include<vector>
// #include<cstring>
using namespace std;
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
const int maxn = 2e5 + 10;
#define INF 0x3f3f3f
typedef long long LL;
int n = 0,k = 0;

int main(){
	while(~scanf("%d %d",&n,&k)){
		map<int,int> mp;
		per(i,1,n){
			int x = 0;
			scanf("%d",&x);
			++mp[x];
		}
		map<int,int>::iterator it = mp.begin();
		int ans = 0,res = ceil(n*1.0/2);
		for(it = it;it != mp.end();++it){
			if(it->second % 2 == 0){
				if(res - (it->second / 2) < 0){
					ans += res * 2;
					res = 0;
					break;
				}
				res -= (it->second / 2);
				ans += it->second;
			}
		}
		// cout << res << endl;
		for(it = mp.begin();it != mp.end();++it){
			if(it->second & 1){
				if(res - (it->second + 1) / 2 < 0){
					ans += res * 2;
					res = 0;
					break;
				}
				// cout << "ji " <<ans << endl;
				res -= ((it->second + 1) / 2);
				ans += it->second;
				// cout << "jij " << ans <<" " << res << endl; 
				// it->second = 0;
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}