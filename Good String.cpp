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
//------------------------------------------Big integer I/O
/*
void scan(__int128 &x){//input
	x = 0;
	int f = 1;
	char ch;
	if((ch = getchar()) == '-'){
		f = -1;
	}else{
		x = x * 10 + (ch - '0');
	}
	while((ch = getchar()) >= '0' && ch <= '9'){
		x = x * 10 + (ch - '0');
	}
	x *= f;
}
void print(__int128 x){//output 
	if(x < 0){
		x = -x;
		putchar('-');
	}
	if(x > 9){
		print(x/10);//recursion
	}
	putchar(x%10+'0');
}
*/
//-----------------------------------------
const double eps=1.0e-5;
const int maxn=2e5;
const LL mod=1e9+7;

int n = 0,m = 0;
char str[110];
void solve(){
	int mi1 = INF,mi2 = INF;
	int l = -1,r = -1;
	per(i,0,n-1){
		if(str[i] == '<'){
			l = i;
		}
	}
	per(i,l+1,n-1){
		if(str[i] == '>'){
			r = i;
		}
	}
	if(l == -1 || r == -1){
		printf("0\n");
		return ;
	}
	mi1 = min(mi1,n-l-1);
	l = r = - 1;
	rep(i,n-1,0){
		if(str[i] == '>'){
			r = i;
		}
	}
	rep(i,r-1,0){
		if(str[i] == '<'){
			l = i;
		}
	}
	if(l == -1 || r == -1){
		printf("0\n");
		return ;
	}
	mi2 =min(mi2,r);
	printf("%d\n",min(mi1,mi2));
}
int main(){
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",str);
		solve();
	}
	return 0;
}
