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
#define inf 0x3f3f3f3f
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
//-----------------------------------------
const double eps=1.0e-5;
const int maxn=200000+10;
const LL mod=1e9+7;

typedef long long ll;
__int128 ex_gcd(__int128 a,__int128 b,__int128& x,__int128& y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    __int128 r;
    __int128 tx,ty;
    r=ex_gcd(b,a%b,tx,ty);
    x=ty;
    y=tx-a/b*ty;
    return r;
}

int main(){
	//std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	 __int128 a1,r1,a2,r2,a,b,c,i,n,m;
	 __int128 x0,y0;
	 scan(n); scan(m);
    bool flag = 1,fg0 = true;
  	scan(a1); scan(r1);
  	if(a1 != r1){
  		fg0 = false;
  	}
    for( i=1;i<n;i++){
       	scan(a2); scan(r2);
       	if(a2 != r2){
	  		fg0 = false;
	  	}
        a = a1;
        b = a2;
        c = r2-r1;
        __int128 d = ex_gcd(a,b,x0,y0);
        if(c%d!=0){
            flag = 0;
        }
        __int128 t = b/d;
        x0 = (x0*(c/d)%t+t)%t;//保证x0为正
        r1 = a1*x0 + r1;
        a1 = a1*(a2/d);
    }
    if(fg0){
    	puts("0");
    	return 0;
    }
    if(!flag){
        puts("he was definitely lying");
        return 0;
    }
    if(r1 > m){
        puts("he was probably lying");
        return 0;
    }
    print(r1);
    
	return 0;
}