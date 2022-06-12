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
typedef long long ll;
const double eps=1.0e-5;
const int maxn=1e6 + 10;

int cnt1=0,cnt2=0,cnt3=0,n = 0,tmp = 0,a[maxn],b[maxn],c[maxn],ma=-inf,flag;

int solve(){
	map<int,int> mp;
	set<int> st;
	per(i,1,n){
		st.insert(a[i]);
	}
	int size = st.size();
	int s = 1,e = 1,num = 0;
	int minv = n + 1;
	while(true){
		while(e <= n && num < size){
			if(mp[a[e++]]++ == 0){
				num++;
			}
		}
		if(num < size){
			break;	
		}
		minv = min(minv,e - s);
		if(--mp[a[s++]] == 0){
			num--;
		}
	}
	if(minv > n){
		return 0;
	}
	return minv;
}
int main(){
	//freopen("in.txt","r",stdin);
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%d",&a[i]);
		} 
		printf("%d\n",solve());
	}
	
	return 0; 
}
