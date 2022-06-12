#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
typedef long long LL;
#define INF 1e9
const int maxn = 2e6 + 10;
int n = 0,m = 0; 
char s[maxn];
int ans[10][10];
int cnt[10][10];
int val(char ch){
	return ch - '0';
}
void solve(){
	
	int len = strlen(s);
	per(i,0,9){
		per(j,0,9){
			per(k,0,9){
				per(l,0,9){
					cnt[k][l] = INF;
				}
			}
			per(k,0,9){
				per(l,0,9){

					per(p,0,9){
						per(q,0,50){
							if(q*i >= ((p*10+l) - k)){
								break;
							}
							if(j == 0){
								if((((p*10+l) - k) - q*i) == 0){
									cnt[k][l] = min(q,cnt[k][l]);
									break;
								}
								continue;	
							}
							if((((p*10+l) - k) - q*i) % j == 0){
								cnt[k][l] = min(q+((p*10+l) - k - q*i) / j,cnt[k][l]);
							}
						}
					}
				}
			}
			rep(k,len-2,0){
				if(cnt[val(s[k+1])][val(s[k])] == INF){
					ans[i][j] = -1;
					break;
				}
				ans[i][j] += cnt[val(s[k+1])][val(s[k])];
			}
			per(k,0,9){
				per(l,0,9){
					printf("%d%c",cnt[k][l],l == 9 ? '\n' : ' ');
				}
			}
		}
	}
	per(i,0,9){
		per(j,0,9){
			printf("%d%c",ans[i][j],j == 9 ? '\n' : ' ');
		}
	}
}
int main(){
	while(~scanf("%s",s)){
		solve();
	}

	return 0;
}