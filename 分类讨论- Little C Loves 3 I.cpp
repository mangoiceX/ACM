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
const int maxn=2e5 + 10;

int cnt1=0,cnt2=0,cnt3=0,n = 0,tmp = 0,a[maxn],b[maxn],c[maxn],ma=-inf,flag;
void solve(){
	if(n % 3 == 0){
		int tmp = n/3;
		if(tmp % 3 == 0){
			printf("%d %d %d\n",n/3-2,n/3+1,n/3+1);	
		}else{
			printf("%d %d %d\n",n/3,n/3,n/3);
		}
	}else{
		int tmp = n / 3;
		int res = n % 3;
		if(tmp % 3 == 0){
			printf("%d %d %d\n",n/3-1,n/3+1,n/3+res);	
		}else{
			if((tmp%3 + res) % 3 == 0){
				if(tmp%3 == 1){
					printf("%d %d %d\n",n/3+1,n/3+1,n/3);
				}else{
					printf("%d %d %d\n",n/3-1,n/3,n/3+2);
				}
				//printf("%d %d %d",n/3,n/3,n/3);
			}else{
				if(tmp%3 == 1){
					printf("%d %d %d\n",n/3+1,n/3,n/3);
				}else{
					printf("%d %d %d\n",n/3,n/3-1,n/3+3);
				}
			}
			//printf("%d %d %d",n/3,n/3,n/3);
		}
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	while(~scanf("%d",&n)){
		solve();
	}
	
	return 0; 
}

