#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a;i >= (b);--i))
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 10;
LL n = 0,m = 0;
int q = 0;
int sx = 0,ex = 0;
LL sy = 0,ey = 0;
void solve(){

}
int main(){
	
	while(~scanf("%lld %lld %d",&n,&m,&q)){
		while(q--){
			scanf("%d %lld %d %lld",&sx,&sy,&ex,&ey);
			if(n % m == 0 || m % n == 0){
				if(n % m == 0){
					LL cnt = n / m;
					if(sx == 1 && ex == 1){
						if(((sy - 1)/cnt) ^ ((ey-1)/cnt)){
							puts("NO");
						}else{
							puts("YES");
						}
					}else if(sx == 2 && ex == 2){
						if(sy != ey){
							puts("NO");
						}else{
							puts("YES");
						}
					}else if(sx == 1 && ex == 2){
						if(((sy - 1)/cnt)+1 != ey){
							puts("NO");
						}else{
							puts("YES");
						}
					}else if(sx == 2 && ex == 1){
						if(((ey-1)/cnt)+1 != sy){
							puts("NO");
						}else{
							puts("YES");
						}
					}
				}else{
					LL cnt = m / n;
					if(sx == 1 && ex == 1){
						if(sy != ey){
							puts("NO");
						}else{
							puts("YES");
						}
					}else if(sx == 2 && ex == 2){
						if(((sy - 1)/cnt) ^ ((ey-1)/cnt)){
							puts("NO");
						}else{
							puts("YES");
						}
					}else if(sx == 1 && ex == 2){
						if(((ey-1)/cnt)+1 != sy){
							puts("NO");
						}else{
							puts("YES");
						}
						
					}else if(sx == 2 && ex == 1){
						if(((sy - 1)/cnt)+1 != ey){
							puts("NO");
						}else{
							puts("YES");
						}
					}
				}
			}else{
				if(n % 2 == 0 && m % 2 == 0){
					if(sx == 1 && ex == 1){
						if(((sy - 1)/(n/2)) ^ ((ey-1)/(n/2))){
							puts("NO");
						}else{
							puts("YES");
						}
					}else if(sx == 2 && ex == 2){
						if(((sy - 1)/(m/2)) ^ ((ey-1)/(m/2))){
							puts("NO");
						}else{
							puts("YES");
						}
					}else if(sx == 1 && ex == 2){
						if(((sy - 1)/(n/2)) ^ ((ey-1)/(m/2))){
							puts("NO");
						}else{
							puts("YES");
						}
					}else if(sx == 2 && ex == 1){
						if(((sy - 1)/(m/2)) ^ ((ey-1)/(n/2))){
							puts("NO");
						}else{
							puts("YES");
						}
					}
				}else{
					puts("YES");
				}
			}
		}
		// solve();
	}

	return 0;
}
