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

//#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
typedef long long LL;
typedef pair<int,int> pii;
const double eps=1.0e-5;
const int maxn=1e5 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n = 0; 
int a[maxn],b[maxn],c[maxn];
void solve(){
	fill(c,c+maxn,-1);
	per(i,0,3){
		per(j,0,3){
			if((i|j) == a[1] && (i&j) == b[1]){//枚举t1,t2 
				c[1] = i;c[2] = j;
				if(n == 2){
					printf("YES\n");
					printf("%d %d\n",c[1],c[2]);
					return ;
				} 
				per(k,2,n-1){
					//int cnt = 0;
					per(l,0,3){
						if((l|c[k]) == a[k] && (l&c[k]) == b[k]){
							c[k+1] = l;
							if(k == n-1){//说明生成了一个可满足的，立即打印，防止后面覆盖 
								printf("YES\n");
								per(u,1,n){//注意循环变量 
									printf("%d%c",c[u],u == n ? '\n':' ');
								}	
								return ;
							}
							//cnt++;
							//break; //注释掉，好像还运行快点 
						}
					}
					//printf("nima %d\n",cnt);
				}
			}
		}
	}
	printf("NO\n");
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%d",&n)){
		per(i,1,n-1){
			scanf("%d",&a[i]);
		} 
		per(i,1,n-1){
			scanf("%d",&b[i]);
		} 
		solve();
	}
	
	return 0; 
}
