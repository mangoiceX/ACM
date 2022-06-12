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
const int maxn=1e2 + 10;

int cnt1=0,cnt2=0,cnt3=0,tmp = 0,a[maxn],b[maxn],c[maxn],ma=-inf,flag;
int n = 0;  
int size = 20;
int dir[maxn];
int f[maxn];

int solve(){
	int sum = 0,res = 0;
	int times[30];
	mem(f,0);mem(times,0);
	per(i,1,size){
		//if(i == 3){
		//	cout << "em " << dir[3] + times[3] << " " << dir[4] + times[4] << endl;
	//	}
		if((dir[i] + times[i]) % 2 != 0 && ((dir[i+1] + times[i+1]) % 2 == 0)){
			times[i]++;
			res++;
			continue;
		}
		if((dir[i] + times[i]) % 2 != 0 && ((dir[i+1] + times[i+1]) % 2 != 0)
		&& ((dir[i+2] + times[i+2]) % 2 != 0)){
			//cout << "haha " << i << endl; 
			times[i]++;times[i+1]++;times[i+2]++;
			res++;
			i+=2;
			continue; 
		}
		if((dir[i] + times[i]) % 2 != 0 && 
		((dir[i+1] + times[i+1]) % 2 != 0)){
			if(i==1){
				if(dir[4] == 1 && dir[5] == 1 && (dir[8] != 1 || dir[7] != 1)){
					times[i+2]++;times[i+1]++;times[i]++;
					res++;
					//cout << "nima " << endl; 
					continue;
				}
				
				times[i-1]++;times[i]++;times[i+1]++;
				res++;
				continue;	
			}
			times[i+2]++;times[i]++;times[i+1]++;
			res++;
		} 
		/*
		if((times[i-1] + dir[i-1]) % 2 != 0 && i != 1){
			times[i-1]++;
			res++;
		}
		*/
	}
	return res;
}
int main(){
	//freopen("a.txt","r",stdin);
	per(i,1,size){
		scanf("%d",&dir[i]);
	}
	//cout << dir[20] << endl;
	dir[0] = 0;dir[21] = dir[22] = dir[23] = 0; 
	printf("%d\n",solve());
	return 0; 
}
