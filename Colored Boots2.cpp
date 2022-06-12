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
struct node{
	int id;
	char ch;
};
node s1[maxn+10],s2[maxn+10];
bool cmp(node x,node y){
	return (x.ch == y.ch) ? (x.id < y.id) : (x.ch < y.ch);
}
int a[30],b[30];
void solve(){
	queue<int> st1[30],st2[30];
	queue<int> sg1,sg2;
	int cnt1 = 0,cnt2 = 0;
	int i1 = 0,i2 = 0;
	while(s1[i1].ch == '?'){
		++cnt1;
		sg1.push(s1[i1++].id);
	}
	while(s2[i2].ch == '?'){
		++cnt2;
		sg2.push(s2[i2++].id);
	}
	per(i,i1,n-1){
		++a[s1[i].ch - 'a'];
		st1[s1[i].ch - 'a'].push(s1[i].id);
	}
	per(i,i2,n-1){
		++b[s2[i].ch - 'a'];
		st2[s2[i].ch - 'a'].push(s2[i].id);
	}
	vector<pii> ans;
	per(i,0,25){
		int times = min(a[i],b[i]);
		for(int j = 1;j <= times;++j){
			ans.push_back(pii(st1[i].front(),st2[i].front()));
			st1[i].pop();st2[i].pop();
		}
	}
	for(int i = 1;i <= cnt1;){
		per(j,0,25){
			while(!st2[j].empty() && i <= cnt1 ){
				ans.push_back(pii(sg1.front(),st2[j].front()));
				sg1.pop();st2[j].pop();
				++i;
			}
		}
		cnt1 = (i > cnt1 ? 0 : (cnt1 - i+1)); 
	}
 
	for(int i = 1;i <= cnt2;){
		per(j,0,25){
			while(!st1[j].empty() && i <= cnt2){
				ans.push_back(pii(sg2.front(),st1[j].front()));
				sg2.pop();st1[j].pop();
				++i;
			}
		}
		cnt2 = (i > cnt2 ? 0 : (cnt2 - i+1)); 
	}
	int ti = min(cnt1,cnt2);
	per(i,1,ti){
		ans.push_back(pii(sg1.front(),sg2.front()));
		sg1.pop();sg2.pop();
	}
	int size = ans.size();
	printf("%d\n",size);
	per(i,0,size-1){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	while(~scanf("%d",&n)){
		getchar();
		per(i,0,n-1){
			scanf("%c",&s1[i].ch);
			s1[i].id = i+1;
		}
		getchar();
		per(i,0,n-1){
			scanf("%c",&s2[i].ch);
			s2[i].id = i+1;
		}
		/*
		per(i,1,n){
			printf("%c",s1[i].ch);
		}
		puts("");
		per(i,1,n){
			printf("%c",s2[i].ch);
		}
		*/
		sort(s1,s1+n,cmp);sort(s2,s2+n,cmp);
		solve();
	}
	
	return 0;
}
