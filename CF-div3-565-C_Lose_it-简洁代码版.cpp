#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
#define per(i,a,b) for(int i = (a);i <= (b);++i)
int b[7] = {0,4,8,15,16,23,42};
int n = 0;
int a[maxn] = {0};
int pre[10] = {0};
/*
想法不要过于直白，转化思维，简化写法，没必要记录与题目无关的信息。
可以利用在线算法，屏蔽后面的特点求解
*/
int main(){
	while(~scanf("%d",&n)){//在线算法，写法简单
		memset(pre,0,sizeof(pre));
		per(i,1,n){
			scanf("%d",&a[i]);
			int pos = lower_bound(b+1,b+1+6,a[i]) - b;
			if(pos == 1){
				++pre[1];
			}else{
				if(pre[pos-1] > 0){
					--pre[pos-1];
					++pre[pos];
				}
			}
		}
		printf("%d\n",n - 6*pre[6]);
	}


	return 0;
}