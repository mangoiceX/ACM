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
const int maxn=2e5;
const LL mod=1e9+7;

int n = 0,m = 0,q = 0;
LL a[maxn+10],b[maxn+10],pre[maxn+10];
LL l = 0,r = 0;
int main(){
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	while(~scanf("%d",&n)){
		memset(pre,0,sizeof(pre));
		per(i,1,n){
			scanf("%I64d",&a[i]);
		}
		sort(a+1,a+1+n);
		per(i,2,n){
			b[i] = a[i] - a[i-1] - 1;//5(+2) 9 中间只空了2 
		}
		sort(b+2,b+1+n);
		pre[1] = 0;
		per(i,2,n){
			pre[i] = pre[i-1] + b[i];
		}
		scanf("%d",&q);
		per(i,1,q){
			scanf("%I64d %I64d",&l,&r);
			LL minus = r - l;
			LL sum = a[n] + minus - a[1] + 1;
			int loc = upper_bound(b+2,b+1+n,minus) - b;
			LL overlap = (pre[n] - pre[loc-1]) - minus * (n - loc + 1);//空白的 
			printf("%I64d\n",sum - overlap);
		}
	}
	
	return 0;
}
