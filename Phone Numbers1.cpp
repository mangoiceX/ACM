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
const int maxn = 3e5;
int n = 0,k = 0; 
string str;
void solve(){
	set<char> st;
	map<char,char> mp;
	per(i,0,n-1){
		st.insert(str[i]);
	}
	set<char>::iterator it1 = st.begin(),it2 = st.begin();
	++it2;
	char maxv ,minv = *st.begin();
	for(it2 = it2;it2 != st.end();++it1,++it2){
		mp[*it1] = *it2;
		maxv = *it2;
	}
	string ans;
	if(n < k){
		ans = str;
		//sort(str.begin(),str.end());
		for(int i = 1;i <= k - n;++i){
			ans.push_back(minv);
		}
		cout << ans << endl;
	}else if(n == k){
		int cnt = n-1;
		while(str[cnt] == maxv){
			--cnt;
		}
		per(i,0,cnt-1){
			ans.push_back(str[i]);
		}
		ans.push_back(mp[str[cnt]]);
		per(i,cnt+1,n-1){
			ans.push_back(minv);
		}
		cout << ans << endl;
	}else{
		int cnt = k-1;
		while(str[cnt] == maxv){
			--cnt;
		}
		per(i,0,cnt-1){
			ans.push_back(str[i]);
		}
		ans.push_back(mp[str[cnt]]);
		per(i,cnt+1,k-1){
			ans.push_back(minv);
		}
		cout << ans << endl;
	}
}
int main(){
	//std::ios::sync_with_stdio(false);
	std::ios::sync_with_stdio(false); 
	while(cin >> n >> k){
		cin >> str;
		solve();
	}
	return 0;
}

