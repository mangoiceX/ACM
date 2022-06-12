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
int n = 0,m = 0;
int a[maxn+10],s[maxn];
int b[maxn+10];
void solve(){
	rep(i,n-1,1){
		if(a[i] < a[i+1]){
			s[i] = ( (s[i+1] < 0 ? 0 : s[i+1]) + 1);
		}else if(a[i] > a[i+1]){
			s[i] = ((s[i+1] > 0 ? 0 : s[i+1]) - 1);
		}else{
			s[i] = 0;
		}
	}
	per(i,1,n){
		cout << s[i] << " ";
	}
	cout << endl;
	per(i,1,n){
		if(a[i] == 0){
			int t = i + 1;
			while(a[t] == a[i]){
				t++;
			}
			if((t - i) & 1){
				printf("%d ",s[t] > 0 ? (5 - s[t] == 1 ? 1 : 5 - s[t] - 1) : 
				(5 + s[i] == 4 ? 5 : 5 + s[i] + 1));	
			}else{
				printf("%d ",s[i] > 0 ? 5 - s[i] : 5 + s[i]);
			}
		}else{
			printf("%d ",s[i] > 0 ? 5 - s[i] : 5 + s[i]);
		}
	}
}
int main(){
	while(~scanf("%d",&n)){
		fill(s,s+maxn+10,0);
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		solve();
	}
	
	return 0;
}

