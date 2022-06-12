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

string str; 
void solve(){
	string ans;
	int len = str.size();
	int cen = 0;
	if(len % 2 == 0){
		cen = len / 2 - 1;
	}else{
		cen = len / 2;
	}
	int l = cen - 1,r = cen + 1; 
	ans.push_back( str[cen]);
	int cnt = 0;
	while(l >= 0 && r < len){
		if(cnt % 2 == 0){
			ans += str[r++];
		}else{
			ans += str[l--];
		}
		cnt++;
	}
	if(r < len){
		ans.push_back(str[r]);
	}
	if(l >= 0){
		ans.push_back(str[l]);
	}
	cout << ans << endl;
}
int main(){
	while(cin >> str){
		solve();
	}
	
	return 0;
}

