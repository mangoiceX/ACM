#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long LL;
int sx[maxn],sy[maxn];
char s[maxn];
int n = 0,x = 0,y = 0;
bool check(int m){
	for(int i = 1;i + m -1 <= n;++i){//ö�����г���Ϊm������ 
		int xx = sx[n] - (sx[i+m-1] - sx[i-1]);//����Ҫ�ı������x,y�Ĺ���ֵ 
		int yy = sy[n] - (sy[i+m-1] - sy[i-1]);
		
		int tx = x - xx,ty = y - yy;//Ҫ�ı������x,y�Ĺ���ֵ 
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
		
		for(int i = 1;i <= n;++i){//����ǰ׺�� 
			sx[i] = sx[i-1] + (s[i] == 'R' ? 1 : (s[i] == 'L' ? -1 : 0));
			sy[i] = sy[i-1] + (s[i] == 'U' ? 1 : (s[i] == 'D' ? -1 : 0));
		}
		
		int ans = -1,l = 0,r = n;
		while(l <= r){//�����������䳤�� 
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

