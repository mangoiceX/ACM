#include <iostream> 
#include <cstdio> 
#include <algorithm>  
#include <cmath>  
#include <cstring>  
#include <map>  
#include<set>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
// typedef int LL;
const int times = 4;
int number = 0;
const int maxn = 1e5 + 10;
int nj = 0,mj = 0;
map<int, int>m;
int num1[maxn],num2[maxn];
int si1= 0 ,si2 = 0;

int Random( int n )
{
	return ((double)rand( ) / RAND_MAX*n + 0.5);
}
 
int q_mul( int a, int b, int mod ) 
{
	int ans = 0;
	while(b)
	{
		if(b & 1)
		{
			//ans += a;
			ans = (ans + a) % mod;
		}
		b /= 2;
		a = (a + a) % mod;
 
	}
	return ans;
}
 
int q_pow( int a, int b, int mod ) 
{
	int ans = 1;
	while(b)
	{
		if(b & 1)
		{
			ans = q_mul( ans, a, mod );
		}
		b /= 2;
		a = q_mul( a, a, mod );
	}
	return ans;
}
 
bool witness( int a, int n )
{
	int tem = n - 1;
	// cout << "jibe" << endl;
	int j = 0;
	while(tem % 2 == 0)
	{
		tem /= 2;
		j++;
	}
	
	int x = q_pow( a, tem, n ); 
	if(x == 1 || x == n - 1) return true;
	while(j--)
	{
		x = q_mul( x, x, n );
		if(x == n - 1) return true;
	}
	return false;
}
 
bool miller_rabin( int n )  
{
 
	if(n == 2)
		return true;
	if(n < 2 || n % 2 == 0)
		return false;
 
	for(int i = 1; i <= times; i++)  
	{
		int a = Random( n - 2 ) + 1;
		if(!witness( a, n )){
			return false;
		} 
		
	}
	return true;
}
 
int gcd( int a, int b )
{
	if(b == 0)
		return a;
	return gcd( b, a%b );
}
 
int pollard_rho( int n, int c )
{
	int x, y, d, i = 1, k = 2;
	x = Random( n - 1 ) + 1;
	// cout << x << endl;
	y = x;
	while(1)
	{
		i++;
		x = (q_mul( x, x, n ) + c) % n;
		d = gcd( y - x, n );
		if(1<d&&d<n)
			return d;
		if(y == x)
			return n;
		if(i == k) 
		{
			y = x;
			k <<= 1;
		}
	}
}
 
void find( int n, int c )
{
	if(n == 1)
		return;
	if(miller_rabin( n )) 
	{	
		m[n]++;
		number++;
		return;
	}
 	// cout << "ok" << endl;
	int p = n;
	while(p >= n){
		//cout << "nima" << endl;
		p = pollard_rho( p, c-- );	
	}
	
	find( p, c );
	find( n / p, c );
}
// LL gcd(LL x,LL y){
// 	return y == 0 ? x : gcd(y,x%y);
// }
void solve(){
	vector<int> g1[maxn],g2[maxn];
	long long ansj = 0;
	// cout << "ji " << nj << " " << mj << endl;
	for(int i = 2;i <= nj;++i){
		// cout << "haha " <<i << " " << ansj <<endl;
		bool fg = true;
		// LL gc = gcd(n,mj);
		// LL lc = n/gc*mj;
		int tar = i;
		number = 0;
		m.clear();
		find( tar, 2137342 );
		for(map<int, int>::iterator c = m.begin(); c != m.end();++c)
		{
			// printf( "%%I64d^%d", c->first, c->second );
			g1[si1].push_back(c->first);
			if(c->second > 1){
				fg = false;
				break;
			}
		}
		if(fg){
			if(m.size() & 1){
				ansj -= 1;
			}else{
				ansj += 1;
			}
			num1[si1++] = m.size();
			// ++si1;
		}else{
			g1[si1].clear();
		}
	}
	// cout << "ha" << endl;
	for(int i = 2;i <= mj;++i){
		bool fg = true;
		// LL gc = gcd(n,mj);
		// LL lc = n/gc*mj;
		int tar = i;
		number = 0;
		m.clear();
		find( tar, 2137342 );
		for(map<int, int>::iterator c = m.begin(); c != m.end();++c)
		{
			g2[si2].push_back(c->first);
			// printf( "%%I64d^%d", c->first, c->second );
			if(c->second > 1){
				fg = false;
				break;
			}
		}
		if(fg){
			// cout << "nima" << endl;
			if(m.size() & 1){
				ansj -= 1;
			}else{
				ansj += 1;
			}
			num2[si2++] = m.size();
		}else{
			g2[si2].clear();
		}
	}
	
	// printf( "%%I64d = ", tar );
	// if(m.empty())
	// {
	// 	printf( "%%I64d\n", tar );
	// }
	// for(map<int, int>::iterator c = m.begin(); c != m.end();)
	// {
	// 	printf( "%%I64d^%d", c->first, c->second );
	// 	if((++c) != m.end())
	// 		printf( " * " );
	// }
	// if(m.size()&1){
	// 	puts("-1");
	// }else{
	// 	puts("1");
	// }
	// cout << "hahja " << ansj  << " " <<si1 << si2<<endl;
	per(i,0,si1-1){
		per(j,0,si2-1){
			set<int> st;
			per(k,0,num1[i]-1){
				st.insert(g1[i][k]);
			}
			per(k,0,num2[j]-1){
				st.insert(g2[j][k]);
			}
			if(st.size()&1){
				ansj -= 1;
			}else{
				ansj += 1;
			}
		}
	}
	printf("%I64d\n",ansj+1);
}
 
int main( )
{
	int T = 0;
	scanf("%d",&T);
	while(T--){
		si1 = 0,si2 = 0;
		scanf("%d %d",&nj,&mj);
		solve();
	}
	
	return 0;
}

