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

#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
typedef long long LL;
const double eps=1.0e-5;
const int maxn=5e3 + 10;

int cnt1=0,cnt2=0,cnt3=0,n = 0,tmp = 0,a[maxn],b[maxn],c[maxn],ma=-inf,flag;
int dir[maxn],f[maxn];
int cal(int k){
	mem(f,0);
	int sum = 0,times = 0;
	per(i,1,n-k+1){
		if((sum + dir[i]) % 2 != 0){
			times++;
			f[i] = 1;
		}
		sum += f[i];
		if(i - k + 1 >= 1){
			sum -= f[i - k + 1];
		} 
	}
	
	per(i,n-k+1+1,n){
		if((sum + dir[i]) % 2 != 0){
			return -1;
		}
		if(i - k + 1 >= 1){
			sum -= f[i - k + 1];
		}
	}
	
	return times;
}
void solve(){
	int m = 0,k = 1,minv = n;
	per(i,1,n){
		m = cal(i);
		if(m > 0 && minv > m){
			minv = m;
			k = i;
		}
	}

	printf("%d %d\n",k,minv);
}
int main(){
	//freopen("in.txt","r",stdin);
	while(~scanf("%d",&n)){
		char ch[3];
		per(i,1,n){
			scanf("%s",ch);
			getchar(); 
			dir[i] = ((ch[0] == 'B') ? 1 : 0);
		}
		solve();
	}
	
	return 0; 
}
