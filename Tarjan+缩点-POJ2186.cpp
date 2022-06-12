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
//#include<bits/stdc++.h>
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
int dfn[maxn+10],low[maxn+10];
int fa[maxn+10];
int tim = 0,cnt = 0;
vector<int> g[maxn+10],g_cp[maxn+10];
int big[maxn+10];
void init(){
	tim = 0;
	memset(dfn,-1,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(fa,0,sizeof(fa));
	memset(big,0,sizeof(big));
}
void Tarjan(int u){
	dfn[u] = low[u] = (++tim);
	//cout << "niam " << u << " " <<tim << endl;
	int size = g[u].size();
	per(i,0,size-1){
		int v = g[u][i];
		if(dfn[v] == -1){
			Tarjan(v);
			//low[u] = min(low[u],low[v]);
		}else{
			low[u] = min(low[u],low[v]);
		}
		//low[u] = min(low[u],low[v]);
	}
}
void cp(){
	per(i,1,n){
		cout << "jaja " << low[i] << endl;
	}
	per(i,1,n){
		int size = g[i].size();
		++big[low[i]];
		per(j,0,size-1){
			int v = low[g[i][j]];
			if(v == low[i]){
				continue;
			}
			g_cp[low[i]].push_back(v);
		}
	}
}
void solve(){
	per(i,1,n){
		if(dfn[i] == -1){
			Tarjan(i);
		}
	}
	cp();
	int deg_i[maxn+10],deg_o[maxn+10];
	memset(deg_i,0,sizeof(deg_i));memset(deg_o,0,sizeof(deg_o));
	per(i,1,n){
		int size = g_cp[i].size();
		per(j,0,size-1){
			++deg_o[i];++deg_i[g_cp[i][j]];
		}
	}
	int ans = 0,flag = 0;
	per(i,1,n){
		if(deg_o[i] == 0 && deg_i[i] != 0){
			ans = i;
			++flag; 
		}
		if(flag > 1){
			printf("0\n");
			return ;
		}
	} 
	printf("%d\n",big[ans]);
}
int main(){
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	while(~scanf("%d %d",&n,&m)){
		init();
		per(i,1,m){	
			int x = 0,y = 0;
			scanf("%d %d",&x,&y);
			g[x].push_back(y);
		}
		solve();
	}

	return 0;
}
