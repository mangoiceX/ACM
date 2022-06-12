#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
typedef long long LL;
const double eps = 1e-8;
const int maxn = 2e5 + 10;
int n = 0,q = 0;
int h[maxn];
int tim = 0;
struct Node{
	int l,r,cnt;
	LL sum;
}tree[40*maxn];
int root[maxn];//记录各个时间点的线段树的根节点位置
LL pre_sum[maxn];
LL cut_num = 0,cut_sum = 0;//分别记录该高度的数量和区间和
void build(int l,int r,int& cur){
	tree[cur].sum = tree[cur].l = tree[cur].r,tree[cur].cnt = 0;
	cur = ++tim;
	if(l == r){
		return ;
	}
	int mid = (l + r) >> 1;
	build(l,mid,tree[cur].l);
	build(mid+1,r,tree[cur].r);
}
void update(int l,int r,int& cur,int pre,int pos){
	cur = ++tim;//记录新的时间点的线段树
	tree[cur] = tree[pre];
	++tree[cur].cnt; tree[cur].sum += pos;
	if(l == r){
		return ;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid){
		update(l,mid,tree[cur].l,tree[pre].l,pos);
	}else{
		update(mid+1,r,tree[cur].r,tree[pre].r,pos);
	}
}
void query(int l,int r,int ql,int qr,int pos){
	if(pos > r){
		return ;
	}
	if(pos <= l){//如果查询高度，小于区间最小高度，那么便是该区间所有的数都大于pos
		cut_num += tree[qr].cnt - tree[ql].cnt;
		cut_sum += tree[qr].sum - tree[ql].sum;
		return ;
	}
	int mid = (l + r ) >> 1;
	query(l,mid,tree[ql].l,tree[qr].l,pos);
	query(mid+1,r,tree[ql].r,tree[qr].r,pos);
}
void init(){
	tim = 0;
}
int main(){
	scanf("%d %d",&n,&q);
	init();
	int maxv = -1;
	per(i,1,n){
		scanf("%d",&h[i]);
		maxv = max(maxv,h[i]);
		pre_sum[i] = pre_sum[i-1] + h[i];
	}
	per(i,1,n){
		update(1,maxv,root[i],root[i-1],h[i]);
	}
	while(q--){
		int ql = 0,qr = 0,x = 0,y = 0;
		scanf("%d %d %d %d",&ql,&qr,&x,&y);
		double H = 1.0*(pre_sum[qr] - pre_sum[ql-1]) * x / y;
		// double H = 1.0 * (tree[root[qr]].sum - tree[root[ql-1]].sum) * x / y;
		double l = 0,r = 1e5;
		
		while(fabs(r-l) > eps){//二分找答案
			cut_num = 0,cut_sum = 0;
			double mid = (l + r) / 2;
			query(1,maxv,root[ql-1],root[qr],ceil(mid));
			if(cut_sum - 1.0*cut_num * mid <= H){//如果砍掉的比应该砍掉的小，那么就多看一点，所以剩下的高度mid，就要变小
				r = mid;
			}else{
				l = mid;
			}
		}
		printf("%.15lf\n",r);
	}

	return 0;
}