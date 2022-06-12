#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string> 
#include<cstring>
#include<set>

using namespace std;
const int maxn = 1000 + 10;
int n = 0,m = 0,k = 0;
struct Node{
	int x,y;
};
Node a[maxn*maxn];
int tree[maxn];

bool cmp(Node a,Node b){
	if(a.y != b.y){
		return a.y > b.y;
	}else{
		return a.x < b.x;
	}
}

int lowbit(int x){
	return x & (-x);
}

void add(int loc,int val){
	for(int i = loc;i <= n;i += lowbit(i)){
		tree[i] += val;
	}
}

long long getsum(int loc){
	long long sum = 0;
	for(int i = loc;i > 0;i -= lowbit(i)){
		sum += tree[i];
	}
	return sum;
}
int main(){
	int T = 0,kase = 0;
	scanf("%d",&T);
	while(T--){
		memset(tree,0,sizeof(tree));
		//memset(level,0,sizeof(level));
		long long ans = 0;
		scanf("%d %d %d",&n,&m,&k);
		for(int i = 1;i <= k;++i){
			scanf("%d %d",&a[i].x,&a[i].y);
		
		}
		sort(a + 1, a + k + 1,cmp);	//y½µÐò£¬xÉýÐò£¬Çó×óÉÏ½Ç 
		
		for(int i = 1;i <= k;++i){
			/*
			if( i-1 >= 1 && (a[i].x == a[i - 1].x || a[i].y == a[i-1].y )){
				//add(a[i].x,-1);
				//continue;
				ans -= 1;
			}
			ans += getsum(a[i].x);
			//cout << a[i].x << " " << a[i].y << endl;
			*/
			add(a[i].x,1);
		}
			//cout << a[0].x << " " << a[0].y << endl;
		
		printf("Test case %d:",++kase);
		printf(" %lld\n",ans);
	//	for(int i = 0;i < n;++i){
	//		cout  << tree[i] << " ";
	///	}	
	}

	return 0;
}
