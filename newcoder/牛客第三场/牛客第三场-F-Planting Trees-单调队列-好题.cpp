#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e6
using namespace std;
const int maxn = 5e2 + 10;
int n = 0,m = 0;
int a[maxn][maxn];
void solve(){
	int mi[maxn],ma[maxn];
	int ans = 0;
	per(i,1,n){
		per(j,1,n){//对于每次枚举上边界，mi,ma数组都要初始化
			// mi[j] = INF; ma[j] = 0;
			mi[j] = ma[j] = a[i][j];
		}
		per(j,i,n){//枚举下边界
			per(k,1,n){//记录每列的最小值
				mi[k] = min(mi[k],a[j][k]); ma[k] = max(ma[k],a[j][k]);
			}
			// queue<int> miq,maq;//存储最小值最大值的下标
			int miq[maxn],maq[maxn];
			int head1 = 1,head2 = 1,tail1 = 0,tail2 = 0; 
			if((j-i+1)*n <= ans){//剪枝优化
				continue;
			}
			int pos = 1;
			per(k,1,n){//枚举右边界
				while(head1 <= tail1 && mi[miq[tail1]] >= mi[k]){
					--tail1;
				}
				miq[++tail1] = k;
				while(head2 <= tail2 && ma[maq[tail2]] <= ma[k]){
					--tail2;
				}
				maq[++tail2] = k;
				//下面注释的代码也是可以的
				// while(pos <= k && ma[maq[head2]] - mi[miq[head1]] > m){
				// 	++pos;
				// 	while(head1 <= tail1 && miq[head1] < pos){
				// 		++head1;
				// 	}
				// 	while(head2 <= tail2 && maq[head2] < pos){
				// 		++head2;
				// 	}
				// }
				// if((j-i+1)*(n-pos+1) < ans){
				// 	break;
				// }
				// ans = max(ans,(j-i+1)*(k-pos+1));
				while(pos <= k){
					if((j-i+1)*(k-pos+1) < ans){//剪枝优化
						break;
					}
					if(pos <= miq[head1] && pos <= maq[head2]){
						if(ma[maq[head2]] - mi[miq[head1]] <= m){
							ans = max(ans,(j-i+1)*(k-pos+1));
							break;
						}else{
							if(miq[head1] < maq[head2]){
								pos = miq[head1] + 1;
								++head1;
							}else if(miq[head1] > maq[head2]){
								pos = maq[head2] + 1;
								++head2;
							}else{
								pos = miq[head1] + 1;
								++head1; ++head2;
							}
						}
					}else{
						while(head1 <= tail1 && pos > miq[head1]){
							++head1;
						}
						while(head2 <= tail2 && pos > maq[head2]){
							++head2;
						}
					}
				}
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	// queue<int> qu;
	// qu.push(1);
	// qu.push(2);
	// qu.push(3);
	// printf("%d %d\n",qu.front(),qu.back());
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		per(i,1,n){
			per(j,1,n){
				scanf("%d",&a[i][j]);
			}
		}
		solve();
	}

	return 0;
}