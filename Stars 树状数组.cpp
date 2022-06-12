#include<iostream>
#include<cstdio>
#include<algorithm>	
#include<string>
#include<cstring>
#include<set>
using namespace std;
const int maxn = 32000 + 10;

int tree[maxn],level[maxn];
int n = 0;

int lowbit(int x){
	return x & (-x);
}

void add(int loc,int val){
	for(int i = loc;i <= maxn;i += lowbit(i)){
		tree[i] += val;
	}
	/*
	int  i = loc;
	while(i <= loc){
		tree[i] += val;
		i += lowbit(i);
	}
	*/
}

int getsum(int loc){
	int ans = 0;
	for(int i = loc;i > 0;i -= lowbit(i)){
		ans += tree[i]; 
	}
	/*
	int  i = loc;
	while(i > 0){
		ans += tree[i];
		i -= lowbit(i);
	}
	*/
	return ans;
}
int main(){
	int x = 0,y = 0;
	memset(tree,0,sizeof(tree));
	memset(level,0,sizeof(level));
	
	scanf("%d",&n);
	for(int i = 0;i < n;++i){//因为y是递增的，所以可以不用考虑y
		scanf("%d %d",&x,&y);
		++x;				//避免0的出现 
		++level[getsum(x)];	//当前从区间1-x的和（闭区间），即是水平数
		add(x,1);			//但是，因为是递增的，所以 只能看当前1-x区间的总和
							//然后再单点更新（不包括本身） 
	}
	for(int i = 0;i < n;++i){
		printf("%d\n",level[i]);
	}
	
	
	return 0;
} 
