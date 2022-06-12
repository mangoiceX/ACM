#include<iostream>
#include<string>
#include<vector>
#include<cstring> 
#include<algorithm>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
typedef long long LL;
const int maxn = 3e3 + 10;
int n = 0,m = 0;
char s[maxn][maxn];
struct Tree{
	int h,loc;
};
struct node{
	int h,l,r;
}st[maxn][maxn];
void init(){
	per(i,0,n){
		per(j,0,m){
			st[i][j].h = 0;
		}
	}
}
void solve(){
	per(i,1,n){
		Tree t[maxn];
		int head = 1,tail = 0;
		per(j,0,m-1){
			st[i][j].l = st[i][j].r = j;
			if(s[i][j] == '1'){
				st[i][j].h = st[i-1][j].h + 1;
			}else{
				st[i][j].h = 0;
			}
			//  if(st[i][j].h == 0){
			// 	continue;
			// }
			while(head <= tail && st[i][j].h <= t[tail].h){
				st[i][j].l = st[i][t[tail].loc].l;
				--tail;
			}
			if(st[i][j].h != 0){
				t[++tail].h = st[i][j].h;
				t[tail].loc = j;
			}
		}
		head = 1,tail = 0;
		rep(j,m-1,0){
			// if(st[i][j].h == 0){
			// 	continue;
			// }
			while(head <= tail && st[i][j].h <= t[tail].h){
				st[i][j].r = st[i][t[tail].loc].r;
				--tail;
			}
			if(st[i][j].h != 0){
				t[++tail].h = st[i][j].h;
				t[tail].loc = j;
			}
		}
	}
	// cout << "ji" << endl;
	int h[maxn];
	per(i,0,m-1){
		h[i] = n;
	}
	int ans = 0;
	rep(i,n,1){
		// int hh = 0;
		per(j,0,m-1){
			if(s[i][j] == '0'){
				continue;
			}
			// if(j >= 0 && st[i][j-1].r >= j && st[i][j-1].h == st[i][j].h){
			// 	continue;
			// }
			if(i > h[j]){
				// if(i+1 <= n && s[i+1][j] != '0' && (st[i+1][j].l <= st[i][j].l && st[i][j].r <= st[i+1][j].r)){
				// 	continue;
				// }
				// if(s[i+1][j] == '0'){
				// 	continue;
				// }
				continue;
				// && i - st[i][j].h >= h[j]
				 // if(i+1 <= n && s[i+1][j] != '0' && st[i][j].l >= st[i+1][j].l && st[i][j].r <= st[i+1][j].r){
				 // 	continue;
				 // }
				 // if(i+1 <= n && s[i+1][j] == '0'){
				 // 	continue;
				 // }
			}
			++ans;
			cout << ans  << " " << i << " "  << j << " "<< h[j] << " " <<st[i][j].h << " " << st[i][j].l << " " << st[i][j].r << endl;
			// hh = st[i][j].h;
			per(k,st[i][j].l,st[i][j].r){
				// if(st[i][k].h > st[i][j].h){
				// 	continue;
				// }
				h[k] = i-st[i][j].h;
				// if(i == 3){
				// 	cout << "jia " <<h[k] << endl;
				// }
				// cout << "nihao " << i << " " <<j << h[k] << endl;
			}
			// j = st[i][j].r;
		}
	}
	printf("%d\n",ans);
}
int main(){
	// char str[maxn];
	// scanf("%s",str+1);
	// printf("%c\n",str[1]);
	while(~scanf("%d %d",&n,&m)){
		init();
		per(i,1,n){
			scanf("%s",s[i]);
		}
		solve();
	}

	return 0;
}
/*
4 4
0110
1110
1111
0001
*/
