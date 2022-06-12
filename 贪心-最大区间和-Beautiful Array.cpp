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

#define pii pair<int, int>
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,a,b) for(int i=(a);i>=(b);i--)
#define pi acos(-1.0)
#define INF 0x3f3f3f3f
#define Rand() (rand()|rand()<<15)
#define Srand() srand(time(0)^(unsigned)(unsigned long long)(new char))
#define typemax(type)   numeric_limits<type>::max()
#define typemin(type)   numeric_limits<type>::min()
typedef long long LL;

template<typename T> inline void read(T &x) {x = 0;int f = 1;char ch=getchar();while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}x=x*f;}
template<typename E> E gcd(E a,E b){return b==0?a:gcd(b,a%b);}
template<typename E> E lcm(E a,E b){return a*b/gcd(a,b);}
template<typename E> E ex_gcd(E a,E b,E &x,E&y) {if(b==0){x=1;y=0;}else {ex_gcd(b,a%b,y,x);y-=(a/b)*x;}}
template<typename E> E quick_mul(E a,E b,E c){E ans=0;while(b){if(b&1) ans=(ans+a)%c;a=(a+a)%c;b>>=1;}  return ans;}
template<typename E> E quick_pow(E a,E b,E c){E ans=1;while(b){if(b&1) ans=ans*a%c;a=a*a%c;b>>=1;}return ans;}
template<typename E> E inv1(E a,E b){return quick_pow(a,b-2,b);}
template<typename E> E inv2(E a,E b){E x,y;ex_gcd(a,b,x,y);return (x%b+b)%b;}

/*==================================Header Template=============================================*/

const double eps=1.0e-5;
const int maxn=3e5;
const LL mod=1e9+7;

int n = 0,x = 0;
LL maxl[maxn+10],maxr[maxn+10],pre[maxn+10];
LL a[maxn+10];
void solve(){
	per(i,1,n){
		maxl[i] = maxl[i-1] + a[i];
		if(maxl[i] < 0){
			maxl[i] = 0;
		}
	}
	
	rep(i,n,1){
		maxr[i] = maxr[i+1] + a[i];
		if(maxr[i] < 0){
			maxr[i] = 0;
		}
	}
	LL minv = 0,ans = -1e18;//minv = 0,不能1e18,因为前面l可能 = 0;也就是前面的都要，这个时候减去0，
	//但是1e18没有这种情况 ,ans = 0也可以，如果max < 0，那么ans = 0;l == r 
	per(i,1,n){//只用枚举r即可，l与r没有联系，所以只要记录前面的minv即可 
		minv = min(minv,pre[i]*x - maxl[i]);
		ans = max(ans,pre[i]*x + maxr[i+1] - minv);
	}
	printf("%I64d\n",ans);
}
int main(){
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	while(~scanf("%d %d",&n,&x)){
		memset(pre,0,sizeof(pre));
		per(i,1,n){
			scanf("%I64d",&a[i]);
			pre[i] = pre[i-1] + a[i];
		}
		solve();
	}
	
	return 0;
}
