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
const int maxn = 1e2;

typedef long long LL;

#define inf 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
map<int,int> mp;
int a = 0,b = 0;
int gcd(int x,int y){
	return y == 0 ? x : gcd(y,x%y);
}
int x[maxn][maxn],y[maxn][maxn];
void solve(){
	fill(x,x+maxn,1);
	fill(y,y+maxn,1);
	int temp = b;
	for(int i = 2;i * i <= temp;++i){//质因数分解 
		while(temp % i == 0){
			temp /= i;
			mp[i]++;
		}
	}
	if(temp > 1){
		mp[temp]++;
	}
	map<int,int>::iterator it;
	if(mp.size() == 1){
		printf("-1 -1\n");
		return;
	} 

	int maxv = 0;
	for(it = mp.begin();it != mp.end();it++){
		maxv = max( it->second,maxv );
	}
	
	int cnt = 0;
	for(it = mp.begin();it != mp.end();it++){
		for(int i = 0;i <= it->second;++i){
			x[cnt++][i] *= pow(it->first,i);
		}
	}
	
	cnt = 0;
	for(it = mp.begin();it != mp.end();it++){
		for(int i = 0;i <= it->second;++i){
			y[cnt++][i] *= pow(it->first,i);
		}
	}
	
	for(int i = 0;i <= maxv;++i){
		//cout << x[i] << " " << y[lower_bound(y,y+maxv,a - x[i]) - y] << endl;
		if(y[lower_bound(y,y+maxv,a - x[i]) - y] == a - x[i]){
			printf("%d %d\n",x[i],a - x[i]);
			return ;
		}
	}
	printf("-1 -1\n");
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&a,&b);
		solve();
	}
	
	
	return 0;
}




