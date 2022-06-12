#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
const int maxn = 1e3 + 10;
int n = 0,m = 0;
char mp[maxn][maxn];
int h[maxn][maxn];
struct node{
	int he,cnt;
};
void init(){
	per(i,0,n){
		per(j,0,m){
			h[i][j] = 0;
		}
	}
}
void solve(){
	init();
	int ans1 = 0,ans2 = 0;
	int len = 0;
	per(i,1,n){
		stack<node> st;
		per(j,1,m){
			if(mp[i][j] == '1'){
				h[i][j] = h[i-1][j] + 1;
			}else{
				h[i][j] = 0;
			}
			len = 0;//记录该点的高度向后可延伸的距离
			//cnt距离该点的高度向前可延伸的距离（他弹出的点的宽度之和）
			while(!st.empty() && st.top().he >= h[i][j]){
				int s1 = st.top().he * (st.top().cnt + len);
				int s2 =  st.top().he * (st.top().cnt + len - 1);

				if(s1 >= ans1){
					ans2 = ans1;
					ans1 = s1;
				}else if(s1 >= ans2){
					ans2 = s1;
				}
				if(s2 >= ans2){//执行s1 >= ans1之后s2 >= ans2仍然可以执行，s1 >= ans0
					ans2 = s2;
				}

				len += st.top().cnt;
				st.pop();
			}
			st.push(node{h[i][j],len + 1});
		}
		len = 0;
		while(!st.empty()){
			int s1 = st.top().he * (st.top().cnt + len);
			int s2 = st.top().he * (st.top().cnt + len - 1);

			if(s1 >= ans1){
				ans2 = ans1;
				ans1 = s1;
			}else if(s1 >= ans2){
				ans2 = s1;
			}
			if(s2 >= ans2){
				ans2 = s2;
			}

			len += st.top().cnt;
			st.pop();
		}
	}
	printf("%d\n",ans2);
}
int main(){
	while(~scanf("%d %d",&n,&m)){
		per(i,1,n){
			scanf("%s",mp[i]+1);
		}
		solve();
	}

	return 0;
}