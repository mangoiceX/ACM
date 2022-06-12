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
const int mod=1e2;

int y = 0,mo = 0,d = 0,h = 0,m = 0,s = 0;
int mon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int pre[14];
void solve(){
	memset(pre,0,sizeof(pre));
	int sum = 0;
	per(i,y+1,2049){
		if(i % 4 == 0){
			sum = (366 * 24 * 3600 + sum ) % mod;
		}else{
			sum = (365 * 24 * 3600 + sum) % mod;
		}
	}
	per(i,1,12){
		pre[i] = mon[i] + pre[i-1];
	}
	
	int tt = pre[mo-1] + d;
	
	if(y % 4 == 0 && mo > 2){
		tt += 1;
	}
	sum = (sum + ((y % 4 == 0 ? 366 : 365) - tt)*24*3600) % mod;
	
	//À„√Î
	sum = (sum + max(0,(24 - h - 1)*3600)) % mod;
	sum = (sum + max(0,(60 - m - 1)*60) )% mod;
	sum = (sum + (60 - s)) % mod;
	printf("%d\n",sum);
}
int main(){
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d-%d-%d",&y,&mo,&d);
		scanf("%d:%d:%d",&h,&m,&s);
		//cout << y << " " << mo <<" " << d << " " << h << " " << " " << m <<" " << s << endl;
		solve();
	}
	return 0;
}
