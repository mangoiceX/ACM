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
const int maxn=1e6 + 10;

int cnt1=0,cnt2=0,cnt3=0,tmp = 0,a[maxn],b[maxn],ma=-inf,flag;
int n = 0; 
const int r = 5,c= 6; 
int title[r+2][c+2]; 
int f[r+2][c+2];
int flip[r+2][c+2];
int ans[r+2][c+2];
int dx[5] = { 0,1,-1,0,0};
int dy[5] = { 1,0,0,-1,0};
int get(int x,int y){
	int num = title[x][y];//之前我用的是c = title[x][y]
	per(i,0,4){//他与下面y1 <= c的c是相冲突的，所以局部变量尽量不要与全局变量同名 
		int x1 = x + dx[i],y1 = y + dy[i];
		if(1 <= x1 && x1 <= r && 1 <= y1 && y1 <= c){
			num += flip[x1][y1];
		}
	}
	return num % 2;
}
int cal(){
	per(i,2,r){
		per(j,1,c){
			if(get(i-1,j) == 1){
				//cnt++;
				flip[i][j] = 1;
			}
		}
	}
	per(i,1,c){
		if(get(r,i) == 1){
			//cout << "nima" <<endl;
			return -1;
		}
	}
	int res = 0;
	per(i,1,r){
		per(j,1,c){
			res += flip[i][j];
		}
	}
	return res;
}
void solve(){
	
	int res = -1;
	per(i,0,(1<<c)-1){
		mem(f,0);mem(flip,0);
		per(j,0,c-1){//一个第一行情况的枚举 
			if((i>>j)&1){
				//f[1][c-j] = 1;
				flip[1][c-j] = 1;
			}
		}
		int num = cal();
		if(num >= 0 && (res < 0 ||  num < res)){
			res = num;
			memcpy(ans,flip,sizeof(flip));
		}
	}
	if(res >= 0){
		per(i,1,r){
			per(j,1,c){
				printf("%d%c",ans[i][j],(j == c)? '\n':' ');
			}
		}
	}else{
		printf("no\n");
	}
}
int main(){
	/*
	#ifndef ONLINE_JUDGE
	   // freopen("in.txt", "r", stdin);
	//  freopen("out.txt", "w", stdout);
	#endif
	//freopen("a.txt","r",stdin);
	*/
	int T = 0,times = 0;
	scanf("%d",&T);
	while(T--){
		per(i,1,r){
			per(j,1,c){
				scanf("%d",&title[i][j]);
			}
		}
		printf("PUZZLE #%d\n",++times);
		solve();
	}
	
	return 0; 
}
