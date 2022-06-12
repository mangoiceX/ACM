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
	int l = -1,r = size+1,l1 = 0,r1 = 0;
	for(int i = 0;i <= size - 4;++i){
		if(str[i] == '['){
			l = i;
			break;
		}
	}
	for(int i = size - 1;i >= 3;--i){
		if(str[i] == ']'){
			r = i;
			break;
		}
	}
	if(l >= r || l == -1 || r == size+1){
		printf("-1\n");
		return ;
	}
	for(int i = l+1;i <= r-2;++i){
		if(str[i] == ':'){
			l1 = i;
			break;
		}
	}
	for(int i = r - 1;i >= l+2;--i){
		if(str[i] == ':'){
			r1 = i;
			break;
		}
	}
	if(l1 == 0 || r1 == 0 || l1 >= r1){
		printf("-1\n");
		return ;
	}
	int cnt = 0;
	for(int i = l1+1;i <= r1-1;++i){
		if(str[i] == '|'){
			cnt++;
		}
	}
	
	printf("%d\n",cnt+4);
}
int main(){
	while(cin >> str){

		solve();
	}
		
	return 0;
}

