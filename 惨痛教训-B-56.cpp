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
bool check(string s){
	int n = s.size();
	per(i,1,n-1){
		if(s[i] != s[i-1]){
			return false;
		}
	}
	return true;
}
void solve(){
	string str1 = str;
	sort(str1.begin(),str1.end());
	if(check(str)){//只有全部一样时输出-1，但是之前排序之后，str1 == str就输出-1,是错的
	//因为之前可能已经排好序了，比如ab,但是这种会输出-1 
		cout << "-1" << endl;
		return ;
	}
	cout << str1 << endl;
}
int main(){
	
	int T = 0;
	cin >> T;
	while(T--){
		cin >> str;
		solve();
	}
	
	return 0;
}

