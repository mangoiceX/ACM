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
int r[10][10];
int dp[10][10][2];//1±íÊ¾ÏÂ½µ 
int x = 0,y = 0;
void solve(){
	per(i,0,m){
		dp[i][0][0] = dp[i][0][1] = 0;
	}
	per(i,0,n){
		dp[0][i][0] = dp[0][i][1] = 0;
	}
	dp[x][y][0] = dp[x][y][1]= r[x][y];
	
	per(i,1,m){
		per(j,1,n){
			if(i == x && j == y){
				continue;
			}
			dp[i][j][1] = (dp[i-1][j][0] == 0 ? dp[i][j][1] : dp[i-1][j][0] + r[i][j]);
			dp[i][j][1] = (dp[i-1][j][1] == 0 ? dp[i][j][1] : dp[i-1][j][1] + r[i][j]);
				
				
			dp[i][j][0] = (dp[i][j-1][1] == 0 ? dp[i][j][0] : max(dp[i][j][0],dp[i][j-1][1] + r[i][j]));
			dp[i][j][0] = (dp[i][j+1][1] == 0 ? dp[i][j][0] : max(dp[i][j][0],dp[i][j+1][1] + r[i][j]));
	
		}
	}
	
	per(i,1,m){
		per(j,1,n){
			printf("%d%c",max(dp[i][j][0],dp[i][j][1]),j == n ? '\n' : ' ');
		}
	} 
	/*
	per(i,1,m){
		per(j,1,n){
			printf("%d%c",dp[i][j][1],j == n ? '\n' : ' ');
		}
	} 
	*/
	int maxv = -1,loc = 0;
	bool fg = -1;
	per(i,1,n){
		if(dp[m][i][0] > maxv){
			maxv = dp[m][i][0];
			loc = i;
			fg = 0;
		}
		if(dp[m][i][1] > maxv){
			maxv = dp[m][i][1];
			loc = i;
			fg = 1;
		}
	}
	printf("%d %d %d\n",maxv,loc,fg);
}
int main(){
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	while(~scanf("%d %d",&m,&n)){
		per(i,1,m){
			per(j,1,n){
				scanf("%d",&r[i][j]);
			}
		}
		scanf("%d %d",&x,&y);
		solve();
	}
	return 0;
}
