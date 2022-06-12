#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 4e5 + 10;
int n = 0,m = 0;
int a[maxn];
void solve(){

}
int main(){

	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		map<int,int> mp;
		per(i,1,4*n){
			// int x = 0;
			scanf("%d",&a[i]);
			++mp[a[i]];
		}
		if(mp.size()==1){
			puts("YES");
			continue;
		}
		bool fg = false;
		map<int,int>::iterator it = mp.begin();
		for(it = it;it != mp.end();++it){
			if(it->second & 1){
				puts("NO");
				fg = true;
				break;
			}
			// num[++si] = it->second;
			// val[si] = it->first;
		}
		if(fg){
			continue;
		}
		sort(a+1,a+1+4*n);
		int sum = a[1] * a[4*n];
		fg = true;
		per(i,2,2*n){
			if(a[i] * a[4*n+1-i] != sum){
				fg = false;
				break;
			}
		}
		if(fg){
			puts("YES");
		}else{
			puts("NO");
		}
		// if(mp.size() == 3 || mp.size() > 4){
		// 	puts("NO");
		// 	continue;
		// }
		
		// int num[10],val[10];
		// int si = 0;
		// map<int,int>::iterator it = mp.begin();
		// for(it = it;it != mp.end();++it){
		// 	num[++si] = it->second;
		// 	val[si] = it->first;
		// }

		// if(si == 2){
		// 	if(num[1] == num[2]){
		// 		puts("YES");
		// 	}else{
		// 		puts("NO");
		// 	}
		// }else{
		// 	if(num[1] == num[2] && num[2] == num[3] && num[3] == num[4] && (val[1] * val[4] == val[2] * val[3])){
		// 		puts("YES");
		// 	}else{
		// 		puts("NO");
		// 	}
		// }
	}

	return 0;
}
