#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a;i >= (b);--i))
using namespace std;
typedef long long LL;
const int maxn = 3e3 + 10;
int n = 0,m = 0;
int pre[maxn][maxn];
char s[maxn][maxn];
struct node{
	int h,l,r;
}hei[maxn][maxn];
struct Tree{
	int h,pos;
};
void init(){
	per(i,0,n){
		per(j,0,m){
			pre[i][j] = 0;
		}
	}
}
int val(char ch){
	return ch - '0';
}
void solve(){
	per(i,1,n){
		per(j,1,m){
			pre[i][j] = pre[i][j-1] + val(s[i][j]);//利用前缀和判断矩形（左右，上边界都已经确定）下边界是否可以拓展
		}
	}
	int ans = 0;
	per(i,1,n){
		int head = 1,tail = 0;
		Tree st[maxn];
		per(j,1,m+1){//m+1设置一个哨兵，将最后剩余的栈的元素弹出
			if(j != m+1){
				if(s[i][j] == '1'){
					hei[i][j].h = hei[i-1][j].h+1;
				}else{
					hei[i][j].h = 0;
				}
			}else{
				hei[i][j].h = 0;
			}
			hei[i][j].l = hei[i][j].r = j;
			while(head <= tail && hei[i][j].h <= st[tail].h){
				int pos = st[tail].pos;
				if(hei[i][j].h != st[tail].h){//高度相等的时候不能计算，因为此时还没有到达极大值，极大值由弹出他的高度决定
					int l = hei[i][pos].l,r = j-1;
					if(pre[i+1][r] - pre[i+1][l-1] != (r-l+1)){//不可以向下拓展
						++ans;
					}
				}
				hei[i][j].l = hei[i][pos].l;
				--tail;
			}
			st[++tail].h = hei[i][j].h;st[tail].pos = j;
		}
	}
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d %d",&n,&m)){
		init();
		per(i,1,n){
			scanf("%s",s[i]+1);
		}
		solve();
	}
	return 0;
}

