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
const int maxn=1e3;
const LL mod=1e9+7;

int n = 0,m = 0,h = 0;
int r[10][10];
int dp[10][10][10];
int vis[maxn+10][maxn+10];
int dfs(int x,int y,int hn,bool sta){
	if(x == m && hn == h){
		//if(!vis[x][y]){
		//	sum += r[x][y];
		//}
		//dp[x][y][hn] = max(dp[x][y][hn],sum);
		return (vis[x][y] == 0) ? r[x][y] : 0;
	}
	if(sta &&dp[x][y][hn] != 0){
		/*
		if(!vis[x][y]){
			sum += r[x][y];
		}
		dp[x][y][hn] = max(sum,dp[x][y][hn]);
		*/
		return dp[x][y][hn];
	}
	int bonus = (vis[x][y] == 0 ) ? r[x][y] : 0;
	//vis[x][y] = true;
	++vis[x][y];
	int res = 0;
	if(hn + 1 <= h){
		if(y-1 >= 1){
			res = dfs(x,y-1,hn+1,false);	
		}
		if(y+1 <= n){
			res = max(res,dfs(x,y+1,hn+1,false));	
		}
	}
	if(x != m){
		if(y - 1 >= 1){
			res = max(res,dfs(x+1,y-1,hn,true));	
		}
		res = max(res,dfs(x+1,y,hn,true));
		if(y+1 <= n){
			res = max(res,dfs(x+1,y+1,hn,true));
		}
	}
	if(sta){
		dp[x][y][hn] = max(res + bonus,dp[x][y][hn]);//(dp[x][y][hn] == 0 ? (res+bonus) : max(res + bonus,dp[x][y][hn]));
	}
	//vis[x][y] = false;
	--vis[x][y];
	
	return res + bonus;
}
int main(){
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	while(~scanf("%d %d %d",&m,&n,&h)){
		per(i,1,m){
			per(j,1,n){
				scanf("%d",&r[i][j]);
			}
		}
		memset(dp,0,sizeof(dp)); memset(vis,0,sizeof(vis));
		int maxv = -1,loc = 0;
		per(i,1,n){
			int ans = dfs(1,i,0,true);
			if(ans > maxv){
				loc = i;
				maxv = ans;
			}
		}
		printf("%d %d\n",loc,maxv);
	}
	return 0;
}
