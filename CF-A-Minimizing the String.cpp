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

using namespace std;
const int maxn = 2e5;

typedef long long LL;

#define inf 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
int n = 0;
//char str[maxn+10];
string str;
void solve(){
	//char ans[maxn+10];
	string ans;
	int cnt = 0;
	bool flag = true;
	per(i,1,n){
		if(i == n && flag){
			continue;
		}
		if(str[i] - '0' < str[i-1] - '0' && flag){
			flag = false;
			continue;
		}
		//ans[cnt++] = str[i-1];
		ans.push_back(str[i-1]);
	}
	//ans[cnt++]='\0';//char加上这个就可以过了 
	//printf("%s\n",ans);
	cout << ans << endl;
}
int main(){
	/*
	while(~scanf("%d",&n)){//这种方法反正会莫名的WA 
		scanf("%s",str);
		solve();
	}
	*/
	while(cin >> n){
		cin >> str;
		solve();
	}
	
	
	return 0;
}




