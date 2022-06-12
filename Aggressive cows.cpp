#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
typedef long long LL;
const LL INF  = 1e9;
const int maxn = 1e5 + 10;
LL loc[maxn];
int n = 0,c = 0;
/*
bool judge(LL x){
	int niu = 1;
	int now = loc[0];
	int i = 1;
	while(i < n){
		while(loc[i] < now + x){
			++i;
		}
		if(i < n){
			++niu;
		}
		now = loc[i];
		if(niu >= c){
			return true;
		} 
	}
	if(niu < c){
		return false;
	}
	return true;
}
*/
bool judge(LL x){
	int last = 0;
	for(int i = 1;i < c;++i){
		int crt = last + 1;
		while(crt < n && loc[crt] - loc[last] < x){
			++crt;
		}
		if(crt == n){
			return false;
		}
		last = crt;
	}
	
	return true;
}
int solve(){
	LL l = 1,r = loc[n-1] - loc[0];
	while(l <= r){
		LL mid = (r - l)/2 + l;
		if(judge(mid)){
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	return r;//如果返回l不行，可以尝试r 
}
int main(){
	std::ios::sync_with_stdio(false);
	cin >> n >> c;
	//memset(loc,INF,sizeof(loc));
	for(int i = 0;i < n;++i){
		cin >> loc[i];
	}
	loc[n] = INF;
	sort(loc,loc + n);
	//cout << loc[n]  << " ";
	int ans = solve();
	cout << ans << endl;
	return 0;
}
