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
int n = 0; 
const int size = 20;
int dir[size+5];
int f[size+5]; 
void solve(){
	int res1 = 0,res2 = 0;
	mem(f,0);
	if(dir[3] == 1){
		dir[0] = 1;
	}
	per(i,1,size){
		/*
		if(i==1){
			if((dir[1] + f[1]) % 2 != 0 && (dir[2] + f[2]) % 2 != 0 
			&& (dir[3] + f[3]) % 2 != 0){
				f[1]++;f[2]++;f[3]++;
			}
			if
		}
		*/
		if((dir[i-1] + f[i-1]) % 2 != 0){
			res1++;
			f[i]++;f[i-1]++;f[i+1]++;
		}
	}
	mem(f,0);
	//cout <<  "oo "<< dir[size-2] << endl;
	if(dir[size] == 1){
		dir[size+1] = 1;
	}
	//cout << dir[21] << endl;
	rep(i,size,1){
		
		if((dir[i+1] + f[i+1]) % 2 != 0){
			res2++;
			//cout << "nima " << i << endl;
			f[i]++;f[i-1]++;f[i+1]++;
			//cout << dir[20] + f[20]<< dir[19] +f[19]<< dir[18] +f[18]<<endl;
		}
	}
	cout << res1 << " " << res2 << endl; 
	printf("%d\n",min(res1,res2));
}
int main(){
	freopen("a.txt","r",stdin);
	per(i,1,size){
		scanf("%d",&dir[i]);
	} 
	solve();
	
	return 0; 
}
