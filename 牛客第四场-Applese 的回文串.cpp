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
int n = 0,m = 0;
string str; 
void solve(){
	int size = str.size();
	int r = size - 1,l = 0;
	int cnt = 0;
	while(l < r){
		if(str[l] == str[r]){
			++l;--r;
			continue;
		}else{
			cnt++;
			if(str[l+1] == str[r]){
				++l;
			}else if(str[r-1] == str[l]){
				--r;
			}else{
				puts("NO");
				return ;	
			}
		}
	}
	if(cnt == 1 || size == 1 || l == ((size & 1) ? size/2: size/2)){
		puts("YES");
	}else{
		puts("NO");
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	while(cin >> str){
		solve();
	}
	
	return 0;
}

