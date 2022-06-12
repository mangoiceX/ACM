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
#define inf 0x3f3f3f3f
typedef long long LL;
const double eps=1.0e-5;
const int maxn=2e4 + 10;

int cnt1=0,cnt2=0,cnt3=0,tmp = 0,b[maxn],c[maxn],ma=-inf,flag;
LL n = 0; 
//set<int> st[maxn];
struct node{
	int l,r;
	//,size;
};
node a[maxn];
int cal = 0;//,cnt1 = 0,cnt2 = 0;
void solve(){			//只需要存储区间的开头和结尾即可，因为是连续区间 
	LL s = 1,e = 1;		//我傻傻地用set去存 
	LL sum = 0;
	int flag = 0;
	while(true){
		while(e * e <= n && sum < n){
			sum += e*e;
			//if(e*e > n){//无用的判断 
			//	return ;
			//}
			e++;
		}
		if(sum < n){//注意退出条件 
			return;
		}
		/*
		if(s*s > n){//等价的退出条件 
			return ;
		}
		*/
		if(sum == n){
			a[cal].l = s;a[cal].r = e-1;
			cal++;
		}
		sum -= s*s;
		s++;
		
		while(sum > n){
			sum -= s*s;
			s++;
		}

	}
}

int main(){
	//freopen("in.txt","r",stdin);
	while(~scanf("%I64d",&n)){
		cal = 0;
		solve();
		printf("%d\n",cal);
		per(i,0,cal-1){
			printf("%d ",a[i].r - a[i].l + 1);
			per(j,a[i].l,a[i].r){
				printf("%d%c",j,(j == a[i].r)?'\n':' ');
			}
		}
	}
	
	return 0; 
}
