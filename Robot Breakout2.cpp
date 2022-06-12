#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
const LL mod = (1e9 + 7);
int n = 0,m = 0,k = 0;
int a[10];
int ansx = 0,ansy = 0;
void solve(){

}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		priority_queue<int> st1,st4;//最大堆
		priority_queue<int,vector<int>,greater<int> > st2,st3;//最小堆
		per(j,1,n){
			per(i,1,6){
				scanf("%d",&a[i]);
			}
			if(a[3] == 0){
				st1.push(a[1]);
			}
			if(a[4] == 0){
				st2.push(a[2]);
			}
			if(a[5] == 0){
				st3.push(a[1]);
			}
			if(a[6] == 0){
				st4.push(a[2]);
			}
		}
		int x1 = 1e6,x3 = 1e6,y2 = 1e6,y4 = 1e6;
		if(!st1.empty()){
			x1 = st1.top();
		}
		if(!st2.empty()){
			y2 = st2.top();
		}
		if(!st3.empty()){
			x3 = st3.top();
		}
		if(!st4.empty()){
			y4 = st4.top();
		}
		// int ,y2 =st2.top(),x3 = st3.top(),y4 = st4.top();
		if(x1 == 1e6 && x3 == 1e6){
			ansx = 0;
		}else if(x1 != 1e6 && x3 == 1e6){
			ansx = x1 ;
		}else if(x1 == 1e6 && x3 != 1e6){
			ansx = x3 ;
		}else{
			if(x1 > x3){
				puts("0");
				continue;
			}
			ansx = (x1 + x3)/2;
		}

		if(y2 == 1e6 && y4 == 1e6){
			ansy = 0;
		}else if(y2 != 1e6 && y4 == 1e6){
			ansy = y2 ;
		}else if(y2 == 1e6 && y4 != 1e6){
			ansy = y4 ;
		}else{
			if(y2 < y4){
				puts("0");
				continue;
			}
			ansy = (y2 + y4)/2;
		}
		printf("1 %d %d\n",ansx,ansy);
	}

	return 0;
}