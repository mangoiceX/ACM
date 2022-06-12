#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

//#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
typedef long long LL;
typedef pair<int,int> pii;
const double eps=1.0e-5;
const int maxn=1e5 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n = 0; 
//int a[30];
//int ans[maxn];
char str[maxn];
map<char,int> mp;
/*
void solve(){
	//int sou[30],sig[30];
	set<int> st1,st2,st3;
	mem(ans,0);
	int cnt1 = 0,cnt2 = 0;
	per(i,1,26){
		if(a[i] % 2 == 0 && a[i] != 0){
			st1.insert(i);
		}
		if(a[i] % 2 == 1 && a[i] > 1){
			st2.insert(i);
		}
		if(a[i] == 1){
			st3.insert(i);
		}
	}
	set<int>::iterator it;
	if(n % 2 == 1){
		it = st3.begin();
		ans[n/2+1] = *it;
		st3.erase(st3.begin());
		
	}
		per(i,1,26){
		if(a[i] == 0){
			continue;
		}
		per(i,1,a[i]){
			printf("%c",a+)
		}
	}
}
*/
void solve(){//÷«’œÃ‚ƒø 

	map<char,int>::iterator it = mp.begin();
	for(it = mp.begin();it != mp.end();it++){
		int cnt = it->second;
		while(cnt--){
			printf("%c",it->first);
		}
	}
	printf("\n");
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%d",&n)){
		//mem(a,0);
		mp.clear();
		scanf("%s",str);
		per(i,0,strlen(str)-1){
			//a[str[i] - 'a' + 1]++;
			mp[str[i]]++;
		}
		solve();
	}
	
	return 0; 
}
