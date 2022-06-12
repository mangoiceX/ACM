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
const int maxn=1e3 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n = 0,r = 0; 
int a[maxn],pos[maxn];
bool vis[maxn];
void solve(){
	fill(vis,vis+maxn,false);

	int ans = 0,fg = 0,flag = 0;
	for(int i = 1;i <= n;){
		fg = 0;
		for(int j = max(i-1,1);j >= max(i-r+1,1);--j){//首先遍历该点前面的点是否有heater 
			if(vis[j] == true){	//如果有，i++,重新开始 
				i++;
				fg = 1;
				break;
			}
		}
		if(fg == 1){
			continue;
		}
		for(int j = min(i+r-1,n);j >= i+1;--j){//然后从他的后面找heater，从最远的地方开始找	
			if(a[j] == 0 ){//0直接跳过 
				continue;
			}
			if(vis[j] == true){//找到一个heater,则跳到j+r 
				i = j + r-1+1;
				fg = 1;
				break;
			}
			if(vis[j] == false){//找到一个没开的1，那么就打开 
				ans++;
				vis[j] = true;
				i = j + r-1+1;
				fg = 1;
				break;
			}
		}
		if(fg == 1){
			continue;
		}
		//如果后半部分没有找到，就只有去前面打开1了 
		for(int j = max(i-1,1);j >= i-r+1 && j >= 1;--j){
			if(a[j] == 0){
				continue;
			}
			if(vis[j] == true){//找到一个已经打开的，就跳过 
				i = j + r-1+1;
				fg = 1;
				break;
			}
			if(vis[j] == false && a[i] != 1){//找到一个没开的1，但是本身不能是1，
			//因为本身是1的话 ，不如点开本身，就不开前面的1了 
				ans++;
				vis[j] = true;
				i = j + r-1+1;
				fg = 1;
				break;
			}
		}
		if(a[i] == 1 && fg == 0){//如果后面没有找到1，并且前面没有已经打开的1, 
			ans++;//那么就打开本身的1 
			vis[i] = true;
			i++;
			fg = 1;
			continue;
		}
		if(fg == 0){//如果都找不到，那么这里不能被heat 
			flag = 1;
			break;
		}
	}
	printf("%d\n",flag == 1 ? -1 : ans);
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%d %d",&n,&r)){
		per(i,1,n){
			scanf("%d",&a[i]);
		} 
		solve();
	}
	
	return 0; 
}
