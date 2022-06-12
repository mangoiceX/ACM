#include<iostream>
#include<string>
#include<vector>
#include<cstring> 
#include<algorithm>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
int n = 0;
LL c[210];
struct node{
	LL h,p,c;
	bool operator < (const node& x)const{
		return this->h < x.h;
	}
}tree[maxn];
void init(){
	per(i,0,n){
		c[i] = 0;
	}
}
LL find_min(LL k){
	LL sum = 0;
	rep(i,200,1){
		sum += 1ll*i * min(c[i],k);
		k -= c[i];			
		if(k <= 0){
			break;
		}
	}
	return sum;
}
/*
因为大于某高度的树都要砍掉，小于该高度的数只留下该高度的数量-1，因为不知道要删除多少树，但是可以知道要留下多少树，所以可以正难则反，
遍历高度，然后从小于该高度的数留下代价最大的树，这样反过来，花费就最少。
因为遍历高度h时，只需要小于h的树的每种价格树的数量的信息，所以h从小到大遍历（先按照h从小到大）排个序，因为cost<200,所以可以直接
从高到低遍历。
*/
int main(){
	while(~scanf("%d",&n)){
		init();
		LL sum = 0;
		per(i,1,n){
			scanf("%lld %lld %lld",&tree[i].h,&tree[i].c,&tree[i].p);
			sum += (tree[i].p * tree[i].c);
		}
		sort(tree+1,tree+1+n);
		LL ans = sum;
		int i = 1,j = 1;
		for(i = 1;i <= n;i = j){
			LL tot = tree[i].p;
			LL cost = tree[i].p*tree[i].c;
			for(j = i+1;j <= n && tree[j].h == tree[i].h;++j){
				tot += tree[j].p;
				cost += (tree[j].p * tree[j].c);
			}
			ans = min(ans,sum - cost - find_min(tot-1));
			per(k,i,j-1){//更新ans之后才能添加
				c[tree[k].c] += tree[k].p;
			}
		}
		printf("%lld\n",ans);
	}



	return 0;
}

