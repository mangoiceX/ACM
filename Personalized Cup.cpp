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

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 1e2;
int n = 0,m = 0;
char str[maxn+10];
void solve(){
	int size = strlen(str);
	int xin = 0;
	per(i,1,5){
		if(ceil(size / i) <= 20){
			xin = (i == 1) ? 0:( (size % i == 0) ? 0 : ((size / i + 1)*i - size));
			int cl = (size % i == 0) ? (size / i) : (size / i + 1);
			if(cl > 20){
				continue;
			} 
			printf("%d %d\n",i,i == 1 ? size : cl);
			int cnt = xin % i,cnt2 = 0;
			per(j,1,i){
				per(k,1,xin / i){
					printf("%c",'*');
				}
				if(j > i - cnt){
					printf("%c",'*');
					int ma = i == 1 ? size :cl - xin / i - 1;
					per(k,1,ma){
						printf("%c",str[cnt2++]);
					}
					printf("\n");
				}else{
					int ma = i == 1 ? size :cl - xin / i;
					per(k,1,ma){
						printf("%c",str[cnt2++]);
					}
					printf("\n");
					
				}
			}
			return ;	
		}
	}
}
int main(){
	while(~scanf("%s",str)){
		solve();
	}
	
	return 0;
}

