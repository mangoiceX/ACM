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
const int maxn = 1e5;
int n = 0,k = 0,m = 0; 
map<string,int> mp; 
int a[maxn+10],b[maxn+10];
vector<string> str;
int main(){
	std::ios::sync_with_stdio(false);
	while(cin >> n >> k >> m){
		str.clear();
		mp.clear();
		string s;
		per(i,1,n){
			cin >> s;
			str.push_back(s);
			mp[s] = 1;
		}
		int x = 0;
		map<string,int>::iterator it = mp.begin();
		//for(it = mp.begin();it != mp.end();++it){
		per(i,1,n){
			cin >> x;
			mp[str[i-1]] = x;
			a[i] = x;
		}
		per(i,1,k){
			int num = 0,minv = INF;
			cin >> num;
			per(i,1,num){
				cin >> b[i];
				minv = min(minv,a[b[i]]);
			}
			per(i,1,num){
				a[b[i]] = minv;
			}
		}
		//for(it = mp.begin();it != mp.end();++it){
		per(i,1,n){
			mp[str[i-1]] = a[i];
		}
		LL ans = 0;
		per(i,1,m){
			cin >> s;
			ans += mp[s];
		}
		cout << ans << endl;
	}	
	return 0;
}

