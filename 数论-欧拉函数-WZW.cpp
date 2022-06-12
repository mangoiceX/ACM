#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<stack>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
typedef long long ll;

template <class T> inline void read(T &x) {
	x = 0;int f = 1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x=x*f;
}

template<typename E>
E gcd(E a,E b){return b==0?a:gcd(b,a%b);}

template<typename E>
E ex_gcd(E a,E b,E &x,E&y) {if(b==0){x=1;y=0;}else {ex_gcd(b,a%b,y,x);y-=(a/b)*x;}}

template<typename E>
E quick_pow(E a,E b,E c){E ans=1;while(b){if(b&1) ans=ans*a%c;a=a*a%c;b>>=1;}return ans;}

template<typename E>
E inv1(E a,E b){return quick_pow(a,b-2,b);}

template<typename E>
E inv2(E a,E b){E x,y;ex_gcd(a,b,x,y);return (x%b+b)%b;}

template<typename E>
E oula(E n){
	E res=n;
	for(E i=2;i*i<=n;i++){
		if(n%i==0){
			while(n%i==0) n/=i;
			res-=res/i;
		}
	}
	if(n>1) res-=res/n;
	return res;
}

const double eps=1.0e-5;
const int maxn=200000+10;
const ll mod=10007;

int t,n,a;
pii p[1001005];

bool cmp(const pii a,const pii b)
{
	return a.first==b.first?a.second<b.second:a.first<b.first;
}
bool operator <(const pii a,const pii b){
	return a.first==b.first?a.second>b.second:a.first<b.first;
} 
void get_eular()
{
	p[1]=make_pair(0,1);
	per(i,2,1001000){
		int tmp=i,res=i;
		for(int j=2;j*j<=tmp;j++){
			if(tmp%j==0){
				while(tmp%j==0) tmp/=j;
				res-=res/j;
			}
		}
		if(tmp>1) res-=res/tmp;
		p[i]=make_pair(res,i);
	}
	
	sort(p+1,p+1001001,cmp);
}

int main()
{
	scanf("%d",&t);get_eular();
	per(cas,1,t){
		scanf("%d",&n);ll ans=0;
		per(i,1,n){
			scanf("%d",&a);
		
			ans+=1ll*p[lower_bound(p+1,p+1001001,make_pair(a,-1))-p].second;
		}
		printf("Case %d: %lld Xukha\n",cas,ans);
	}
}
