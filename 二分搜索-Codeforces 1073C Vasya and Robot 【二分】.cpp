#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long LL;
int sx[maxn],sy[maxn];
char s[maxn];
int n = 0,x = 0,y = 0;
bool check(int m){
	for(int i = 1;i + m -1 <= n;++i){//枚举所有长度为m的区间 
		int xx = sx[n] - (sx[i+m-1] - sx[i-1]);//不需要改变区间对x,y的贡献值 
		int yy = sy[n] - (sy[i+m-1] - sy[i-1]);
		
		int tx = x - xx,ty = y - yy;//要改变区间对x,y的贡献值 
		if(abs(tx) + abs(ty) <= m && (m - (abs(tx) + abs(ty))) % 2 == 0){
			return true;
		}
	}
	return false;
}
int main(){
	while(~scanf("%d",&n)){
		fill(sx,sx+maxn,0);fill(sx,sx+maxn,0);
		scanf("%s",s+1);
		scanf("%d %d",&x,&y);
		
		for(int i = 1;i <= n;++i){//计算前缀和 
			sx[i] = sx[i-1] + (s[i] == 'R' ? 1 : (s[i] == 'L' ? -1 : 0));
			sy[i] = sy[i-1] + (s[i] == 'U' ? 1 : (s[i] == 'D' ? -1 : 0));
		}
		
		int ans = -1,l = 0,r = n;
		while(l <= r){//二分搜索区间长度 
			int mid = (l + r ) >> 1;
			if(check(mid)){
				ans = mid;
				r = mid -1;
			}else{
				l = mid + 1;
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}

