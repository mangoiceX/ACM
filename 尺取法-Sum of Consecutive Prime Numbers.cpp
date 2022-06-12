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
const int maxn=1e4 + 10;

int cnt1=0,cnt2=0,cnt3=0,n = 0,tmp = 0,a[maxn],b[maxn],c[maxn],ma=-inf,flag;
bool is_prime[maxn];
int prime[maxn];
int cnt = 0;
void ais(){	
	fill(is_prime,is_prime+maxn,true);
	is_prime[0] = is_prime[1] = false;
	per(i,2,maxn-1){
		if(is_prime[i]){
			prime[++cnt] = i;
			//per(j,2*i,maxn-1){
			for(int j = 2*i;j < maxn;j += i){
				is_prime[j] = false;
			}
		}
	}
}

void solve(){
	int sum = 0,ans = 0;
	int s = 1,e = 1;
	int flag = 0;
	while(true){
		while(e < cnt && sum < n){
			if(prime[e] > n){//剪枝，如果区间的末尾大于n，则直接退出 
				flag = 1;
				break;
			}
			sum += prime[e++];
		}
		if(flag == 1){
			break;
		}
		if(sum < n){//模板中的退出 
			break;
		}
		if(sum == n){//相等 
			ans++;
		}
		
		sum -= prime[s++];
		while(sum > n){//一直减去区间的开头，知道sum <= n 
			sum -= prime[s++];
		}
		
	}
	printf("%d\n",ans);
}
int main(){
	//freopen("in.txt","r",stdin);
	ais();
	while(~scanf("%d",&n) && n){
		solve();
	}
	
	return 0; 
}
