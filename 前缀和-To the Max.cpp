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
int a[maxn+10][maxn+10];//a[i][j]表示前i行，第j列的所有元素和 
/*
如果朴素枚举的话，复杂度O(n4),如果使用前缀和，可以降一维，所以O(n3); 
*/
int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%d",&n)){
		memset(a,0,sizeof(a));
		per(i,1,n){
			per(j,1,n){
				int t = 0;
				scanf("%d",&t);
				a[i][j] = a[i-1][j] + t;
			}
		}
		int maxv = a[1][1];
		per(i,1,n){
			per(j,i,n){
				int sum = 0;
				per(k,1,n){
					sum += (a[j][k] - a[i-1][k]);
					if(sum < 0){//及时纠正，这样如果中间的和会更大就会枚举到他 
						sum = 0;
					}
					if(sum > maxv){
						maxv = sum;
					}
				}
			}
		}
		printf("%d\n",maxv);
	}
	
	return 0;
}

