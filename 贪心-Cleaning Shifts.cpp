#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

typedef long long LL;

#define inf 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 25000;
int n = 0,t = 0;
struct node{
	int s,e;
	
	node(){
	}
	node(int a,int b){
		s = a;e = b;
	}
	
};
node cow[maxn+1000];

bool cmp(node a,node b){
	return (a.s != b.s) ?  a.s < b.s :  a.e < b.e;
}
/*
bool cmp1(node a,int b){
	return a.e < b;
}
void solve(){
	int ans  = 0;
	int temps = 1,tempe = 1;
	while(tempe < t){
		ans++;
		int loc = lower_bound(cow+1,cow+1+n,tempe,cmp1)- cow ;
		
		if(cow[loc].s > tempe + 1){
			printf("-1\n");
			return ;
		}
		bool flag = false;
		for(int i = loc;i >= temps;--i){
			if(cow[i].e > tempe){
				tempe = cow[i].e;
				temps = cow[i].s;
				flag = true;
			}
		}
		if(flag == false){
			printf("-1\n");
			return ;
		}
	}
	printf("%d\n",ans);
	
}
*/
/*
void solve(){
	int ans  = 0;
	int s = 1,e = 0,l = 1;
	while(e < t){
		s = e + 1;
		per(i,l,n){
			if(cow[i].s <= s && cow[i].e >= s){
				e = max(e,cow[i].e);
			}else if(cow[i].s > s){
				l = i;
				break;	
			} 
		}
		if(s > e){
			break;
		}else{
			ans++;
		}
	}
	if(e >= t){
		printf("%d\n",ans);
	}else{
		printf("-1\n");
	}
}
*/

void solve(){
	int ans  = 0;
	int s = 1,e = 0	,l = 1;
	while(e < t){
		s = e+1;//2 10 1-5 6-10´ð°¸Êä³öÊÇ2 
		//cout << s << endl;
		per(i,l,n){
			if(cow[i].s <= s && cow[i].e >= s){
				e = max(e,cow[i].e);
			}else if(cow[i].s > s){
				l = i;
				break;	
			} 
		}
		if(s == e + 1){
			break;
		}else{
			ans++;
		}
	}
	if(e >= t){
		printf("%d\n",ans);
	}else{
		printf("-1\n");
	}
}

int main(){
	while(~scanf("%d %d",&n,&t)){
		per(i,1,n){
			scanf("%d %d",&cow[i].s,&cow[i].e);;
		}
		sort(cow+1,cow+1+n,cmp);
		solve();
	}
	
	return 0;
}




