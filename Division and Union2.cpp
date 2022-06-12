#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1e3;
pair<int,int> p[maxn+10];
int pre[maxn+10],suf[maxn+10];
int m = 0,n = 0;
bool cmp(pair a,pair b){
	return (a.first == b.first) ? (a.second < b.second) : (a.first < b.first);
}
void solve(){
	int ans[manx+10];
	ans[1] = 1;
	int l = p[1].first,r = p[1].second;	
	for(int i = 2;i <= n;++i){
		if(p[i].second >= l && p[i].first <= r){
			ans[i] = 2;
		}
	}
	
}
int main(){
	int T = 0;
	while(T--){
		scanf("%d",&n);
		for(int i = 1;i <= n;++i){
			scanf("%d %d",p[i].first,p[i].second);
		}
		sort(p+1,p+1+n,cmp);
		pre[1] = -1;
		for(int i = 2;i < n;++i){
			pre[i] = max(p[i].second,pre[i-1]);
		} 
		solve();
	}
	
	return 0;
}
