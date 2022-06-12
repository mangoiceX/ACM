#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
const int maxn = 2e5;

int a[maxn+10],b[maxn+10];
int p[maxn+10];
int n = 0;
void solve(){
	/*
	结合题解，然后谈一下自己的理解。
	为什么要分1在b或不在b里面特殊讨论，因为如果1在b中可能构成。。。。。1 2 3，这个时候可以省去
	一些步骤。其他情况。为什么是这样的，如果1不满足这个特殊条件（包括1不在b里面），都要先把所有
	p[i]在i的前面（p[i] < i),这样的活只要取max(p[i]-i+1),然后就是开始按顺序出1-n，因为有了
	前面的保证，所以当要使用i时，i一直经过前面的交换到了a里面，所以+n;还有就是只有前面的保证后，
	在b中放1才会得到结果。

	抽象：先使b中的每个元素都满足某种条件，然后才开始（放1）构造答案才是有意义的。这样也分离出了
	两个简单过程。由前面想法自然会想到1在b中的特殊条件


	如果1在b中，要特殊讨论，可能构成。。。。。1 2 3
	这种情况后面可以省去步骤，并且前面要满足条件p[j] <= j - (i+1)，所以后面使用j循环，如果全部
	满足条件，即j > n跳出循环，则输出答案。
	*/
	if(p[1]){
		for(int i = 1;p[i] == p[1] + i - 1;++i){
			if(p[i] == n){
				int j = 0;
				for(j = i+1;j <= n && p[j] <= j - (i+1);++j);
				if(j > n){
					printf("%d\n",n-i);
					return ;
				}
			}
		}
	}

	int ans = 0;
	per(i,1,n){
		ans = max(ans,p[i]-i+1 + n);
	}
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d",&n)){
		memset(p,0,sizeof(p));
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		per(i,1,n){
			scanf("%d",&b[i]);
			p[b[i]] = i;
		}
		solve();
	}

	return 0;
}