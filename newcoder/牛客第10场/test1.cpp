#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 5e2 + 10;
int n = 0,m = 0;
LL k = 0;
string s1 = "COFFEE",s2 = "CHICKEN";
string s3;
int main(){
	for(int i = 3;i <= 10;++i){
		s3 = s1 + s2;
		s1 = s2;
		s2 = s3;
		cout << i << " : " << s3 <<endl;
	}

	return 0;
}