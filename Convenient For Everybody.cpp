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
const int maxn = 1e5;
int n = 0,s = 0,f = 0; 
int pre[maxn+10];
int a[maxn+10];
void solve(){
	int size = f - s;
	int maxv = 0;
	int max_id = 1e6;
	per(i,1,n){
		int sum = 0;
		if(size + i - 1 <= n){
			sum = pre[size+i-1] - pre[i-1];
		}else{
			sum = pre[(size+i-1)%n] + pre[n] - pre[i-1];//区间右端点大于n，则要循环回去 
		}
		if(maxv < sum){//小于的话直接更新 
			max_id = (s - i + 1 + n) % n == 0 ? n : (s - i + 1 + n) % n;
			maxv = sum;
		}
		if(maxv == sum){//等于的话，再去较小值（最后的结果最小值） 
			max_id = min(max_id,(s - i + 1 + n) % n == 0 ? n : (s - i + 1 + n) % n);
		}
	}
	printf("%d\n",max_id);
}
int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%d",&n)){
		memset(pre,0,sizeof(pre));
		per(i,1,n){
			scanf("%d",&a[i]);
			pre[i] = pre[i-1] + a[i];
		}
		scanf("%d %d",&s,&f);
		solve();
	}
	
	
	return 0;
}

