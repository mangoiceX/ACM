#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
typedef long long LL;
const double eps=1.0e-5;
const int maxn=100 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n = 0; 
char str[maxn];
int num[maxn];
LL gcd(LL x,LL y){
	return y == 0 ? x : gcd(y,x % y);
}
void solve(){
	int len = strlen(str);
	int size = 0;
	for(int i = 2;i < len && str[i] != '.';++i){
		num[++size] = (str[i] - '0'); 
	} 
	LL ans1 = 0,ans2 = 0,minv = INF;
	per(i,0,size-1){
		LL a1 = 0,a2 = 0,mul1 = 1,mul2 = 1,div = 0;
		rep(k,i,1){
			a1 += num[k] * mul1;
			mul1 *= 10;
		}
		
		rep(j,size,i+1){
			a2 += num[j] * mul2;//将循环节部分化为整数 
			div += 9 * mul2;//与循环节位数相同的9999... 
			mul2 *= 10;
		}
		LL gc1 = gcd(a2,div);
		a2 /= gc1;div /= gc1;//循环节/99999的最简分母 
		
		a2 += (a1 * div);//将非循环节整数部分加入到循环节/999...上 
		div *= mul1;//之前非循环节扩大的倍数算上 

		LL gc2 = gcd(a2,div);
		a2 /= gc2;div /= gc2;//求他们之间的最简分母 

		if(div < minv){//寻找分母最小的 
			minv = div;
			ans1 = a2;
			ans2 = div;
		}
	}
	printf("%I64d/%I64d\n",ans1,ans2);
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%s",str) && strcmp(str,"0") != 0){
		solve();
	}
	
	return 0; 
}
