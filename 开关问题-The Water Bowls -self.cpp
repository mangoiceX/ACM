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

int cnt1=0,cnt2=0,cnt3=0,tmp = 0,a[maxn],b[maxn],c[maxn],ma=-inf,flag;
int n = 0,size = 20; 
int dir[30],f[30];
void solve(){
	int res = 0;
	mem(f,0);
	per(i,1,20){
		if(i == 1){
			if(dir[1] == 1 && dir[2] == 1 && dir[3] != 1){
				f[1]++;f[2]++;
				res++;
				continue;
			}
		}
		if((dir[i] + f[i]) % 2 != 0 && (dir[i+1] + f[i+1]) % 2 != 0 
		&& (dir[i+2] + f[i+2]) % 2 != 0 ){
			f[i]++;f[i+1]++;f[i+2]++;
			res++;
			i += 2;
			continue; 
		}
		if((dir[i] + f[i]) % 2 != 0 && (dir[i+1] + f[i+1]) % 2 != 0){
			f[i]++;f[i+1]++;f[i+2]++;
			//i += 1;
			res++;
		}
	}
	printf("%d\n",res);
}

int main(){
	//freopen("a.txt","r",stdin);
	per(i,1,size){
		scanf("%d",&dir[i]);
	}
	solve();
	
	return 0; 
}
