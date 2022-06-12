#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int a[maxn];
int n = 0,r = 0;

int main(){
	while(~scanf("%d %d",&n,&r)){
		for(int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
		}
		int fg = 0;
		int last = 1,pre = 1;
		int ans = 0;
		while(last <= n){
			int flag = -1;
			for(int j = max(last-r+1,1);j <= min(last+r-1,n);++j){
				if(a[j] == 1){
					flag = j;
				}
			}
			if(flag == -1){
				fg = 1;
				printf("-1\n");
				break;
			}
			ans++;
			last = flag + r ;
			 
			if(last == pre){
				last += 1;
			}
			pre = last;
		}
		if(fg == 1){
			continue;
		}
		printf("%d\n",ans);
	}
	return 0;
}
