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
const int maxn=1e6;
const LL mod=1e9+7;

int n = 0,k = 0;
int a[maxn+10];

int main(){
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	while(~scanf("%d %d",&n,&k)){
		stack<int> st_min,st_max;
		stack<int> tmp1,tmp2;
		int mi[maxn+10],ma[maxn+10];
		per(i,1,n){
			int x = 0;
			scanf("%d",&x);
			a[i] = x;
			while(!st_min.empty() && x > st_min.top()){
				tmp1.push(st_min.top());
				st_min.pop();
			}
			st_min.push(x);
			while(!tmp1.empty()){
				st_min.push(tmp1.top());
				tmp1.pop();
			}
			//-------------------------
			while(!st_max.empty() && x < st_max.top()){
				tmp2.push(st_max.top());
				st_max.pop();
			}
			st_max.push(x);
			while(!tmp2.empty()){
				st_max.push(tmp2.top());
				tmp2.pop();
			}
			//---------------
			if(i >= k){
				if(i > k){
					while(!st_min.empty() && st_min.top() !=a[i-k]){
						tmp1.push(st_min.top());
						st_min.pop();
					}
					st_min.pop();
					while(!tmp1.empty()){
						st_min.push(tmp1.top());
						tmp1.pop();
					}
					//----------------------------------------- 
					while(!st_max.empty() && st_max.top() !=a[i-k]){
						tmp2.push(st_max.top());
						st_max.pop();
					}
					st_max.pop();
					while(!tmp2.empty()){
						st_max.push(tmp2.top());
						tmp2.pop();
					}
				}
				//--------------------
				mi[i-k+1] = st_min.top();
				ma[i-k+1] = st_max.top();
			}
		}
		per(i,1,n-k+1){
			printf("%d%c",mi[i],i == (n-k+1) ? '\n' : ' ');
		}
		per(i,1,n-k+1){
			printf("%d%c",ma[i],i == (n-k+1) ? '\n' : ' ');
		}
	}
	
	return 0;
}
