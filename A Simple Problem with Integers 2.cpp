#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string> 
#include<cstring>
#include<set>
#define INF 0x7fffffff
using namespace std;
const int maxn = 100000 + 10;//开1e5小了，线段树一般开原来的4倍 
typedef long long LL;
struct SegTree{
	int l,r;
	LL sum;
	LL add_mark;
};
SegTree seg_tree[4 *maxn];
LL arr[maxn]; 
int n = 0,q = 0;
void build(int root,int is,int ie){
	seg_tree[root].add_mark = 0;//设置延迟标记 
	seg_tree[root].l = is;
	seg_tree[root].r = ie;
	
	if(is == ie){
		seg_tree[root].sum = arr[is];
		return ;
	}else{
		int mid = (ie - is)/2 + is;
		build(root*2,is,mid);
		build(root*2+1,mid+1,ie);
		seg_tree[root].sum = seg_tree[root*2].sum + seg_tree[root*2+1].sum;
	}
	
}
void push_up(int root){
	seg_tree[root].sum = seg_tree[root*2].sum + seg_tree[root*2+1].sum;
	
}
void push_down(int root){
	if(seg_tree[root].add_mark != 0){
		/*
		tree[root<<1].tot+=tree[root].add*(tree[root<<1].right-tree[root<<1].left+1);

　　　　tree[root<<1|1].tot+=tree[root].add*(tree[root<<1|1].right-tree[root<<1|1].left+1);
		*/
		seg_tree[root*2].add_mark += seg_tree[root].add_mark;
		seg_tree[root*2+1].add_mark += seg_tree[root].add_mark;
		
		//seg_tree[root*2].sum += seg_tree[root].add_mark;
		//seg_tree[root*2+1].sum += seg_tree[root].add_mark;
		//当前区间加上了懒惰标记的值实际上加的值是lazy_tag*区间长度,之前一直没注意到这一点 
seg_tree[root*2].sum += seg_tree[root].add_mark * (seg_tree[root*2].r - seg_tree[root*2].l+1);
seg_tree[root*2+1].sum += seg_tree[root].add_mark * (seg_tree[root*2+1].r - seg_tree[root*2+1].l+1);		
		seg_tree[root].add_mark = 0;
	}
}

//void update(int root,int is,int ie,int us,int ue,int add_val){
void update(int root,int us,int ue,int add_val){
	
	int is = seg_tree[root].l,ie = seg_tree[root].r ;
	
	if(is > ue || ie < us){
		return ;
	}else if(is >= us && ie <= ue){
		
		seg_tree[root].add_mark += add_val;
		//当前区间加上了懒惰标记的值实际上加的值是lazy_tag*区间长度,之前一直没注意到这一点 
		seg_tree[root].sum += add_val * (seg_tree[root].r - seg_tree[root].l + 1);
		return ;
	}else{
		push_down(root);//mid 没必要，因为root已经用结构体存储了l,r的信息，这与模板不同 
		//int mid = (ie - is)/2 + is;
		//update(root*2,is,mid,us,ue,add_val);
		//update(root*2+1,mid+1,ie,us,ue,add_val);
		update(root*2,us,ue,add_val);
		update(root*2+1,us,ue,add_val);
		seg_tree[root].sum = seg_tree[root*2].sum + seg_tree[root*2+1].sum;
	}
}

LL query(int root,int us,int ue){
	
	int is = seg_tree[root].l,ie = seg_tree[root].r;
	
	if(is > ue || ie < us){
		return 0;
	}else if(is >= us && ie <= ue){
		return seg_tree[root].sum;
	}else{
		push_down(root);		//mid 没必要，因为root已经用结构体存储了l,r的信息，这与模板不同 
		//int mid = (ie - is)/2 + is;
		
		//return query(root*2,is,mid) + query(root*2+1,mid+1,ie);
		
		return query(root*2,us,ue) + query(root*2+1,us,ue);
	}
	
	
}
int main(){
	int a = 0,b = 0,c = 0;
	//char str;
	string str;
	//while(scanf("%d %d",&n,&q) != EOF){
	//while(cin >> n >> q){
		cin >> n >> q;
		memset(arr,0,sizeof(arr));
		memset(seg_tree,0,sizeof(seg_tree));
		for(int i = 1;i <= n;++i){
			//scanf("%lld",&arr[i]);
			cin >> arr[i];
		} 
		build(1,1,n);
		
		for(int i = 0;i < q;++i){
			cin >> str;
		//	scanf("%c",&str);
			//getchar();
			if(str == "C"){
				//scanf("%d %d %d ",&a,&b,&c);
				cin >> a >> b >> c;
				update(1,a,b,c);
				
			}else{
				//scanf("%d %d",&a,&b);
				cin >> a >> b;
				//printf("%lld\n",query(1,a,b));
				cout << query(1,a,b) << endl;
			}
		}
	//}
	return 0;
}
