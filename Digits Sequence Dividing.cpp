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
int main(){
	//std::ios::sync_with_stdio(false);	
	int T = 0;
	cin >> T;
	while(T--){
		cin >> n;
		cin >> str;
		if(str.size() == 2 && str[0] >= str[1]){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES"  << endl;
		cout << "2" << endl;
		string s1 = str;
		s1[0] = ' ';//把首字母改成空格即可 
		cout << str[0] << s1 << endl;
	}
	
	return 0;
}

