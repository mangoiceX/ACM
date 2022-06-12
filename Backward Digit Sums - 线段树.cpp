#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string> 
#include<cstring>
#include<set>
#define INF 0x7fffffff
using namespace std;
const int maxn = 50000 + 10;
//线段树适合解决“相邻的区间的信息可以被合并成两个区间的并区间的信息”的问题
//当你的根结点是0时，左孩子 是2*i+1,有孩子是2*i+2 
//当你的根结点是1时，左孩子 是2*i,有孩子是2*i+1
struct SegTreeNode{
	int min,max;
	int add_mark;//延迟标记 
	int l ,r;
}seg_tree[maxn*4];//定义线段树 
int arr[maxn];
/* 
功能：构建线段树
 root：当前线段树的根节点下标
 arr: 用来构造线段树的数组
 istart：数组的起始位置
 iend：数组的结束位置
*/
void build(int root,int is,int ie){ //递归构建线段树 
	seg_tree[root].l = is,seg_tree[root].r = ie;
	
	if(is == ie){		//叶子结点 
		seg_tree[root].min = arr[is];
		seg_tree[root].max = arr[is];
	}else{
		int mid = (ie - is)/2 + is;
		build(root * 2,is,mid);//递归构造左子树 
		build(root * 2 + 1, mid + 1,ie);//递归构造右子树 
		//根据左右子树根结点的值，更新当前根节点的值 
		seg_tree[root].min = min(seg_tree[root*2].min,seg_tree[root*2+1].min);
		seg_tree[root].max = max(seg_tree[root*2].max,seg_tree[root*2+1].max);
			
	}
		
}

/*
2 功能：线段树的区间查询
3 root：当前线段树的根节点下标
4 [nstart, nend]: 当前节点所表示的区间
5 [qstart, qend]: 此次查询的区间
6 */
 
int query_min(int root,int qstart,int qend){//线段树的区间查询 
	int nstart = seg_tree[root].l,nend = seg_tree[root].r;
	//查询区间与当前区间没有交集时 
	if(nend < qstart || nstart > qend){
		return INF;
	//当前区间包含在查询区间内 
	}else if(nstart >= qstart && nend <= qend){
		return seg_tree[root].min;
	//当前区间部分包含在查询区间内 
	}else{
		//int mid = (nend - nstart)/2 + nstart;
		//分别从左子树和右子树查询，返回两者查询结果的较小值 
		return min( query_min(root*2,qstart,qend),
		query_min(root*2+1,qstart,qend) );
	}
	
}
	
int query_max(int root,int qstart,int qend){//线段树的区间查询 
	int nstart = seg_tree[root].l,nend = seg_tree[root].r;
	//查询区间与当前区间没有交集时 
	if(nend < qstart || nstart > qend){
		return 0;
	//当前区间包含在查询区间内 
	}else if(nstart >= qstart && nend <= qend){
		return seg_tree[root].max;
	//当前区间部分包含在查询区间内 
	}else{
		//push_down(root); //----延迟标志域向下传递
		
		//int mid = (nend - nstart)/2 + nstart;
		//分别从左子树和右子树查询，返回两者查询结果的较小值 
		return max( query_max(root*2,qstart,qend),
		query_max(root*2+1,qstart,qend) );
	}
	
}

int main(){
	
	int n = 0,q = 0,s = 0,e = 0;
	while(scanf("%d %d",&n,&q) != EOF){
		
	
	for(int i = 1;i <= n;++i){
		scanf("%d",&arr[i]);
	}
	build(1,1,n);
	for(int i = 0;i < q;++i){
		scanf("%d %d",&s,&e);
		printf("%d\n",query_max(1,s,e) - query_min(1,s,e));
	}
}
	
	return 0;
}
