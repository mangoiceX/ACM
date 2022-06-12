#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int maxn = 2e5 + 10;
int n = 0,k = 0; 
int a[maxn];
int tree[maxn];
int sum[maxn];
//输入的是对区间的操作，如果最终要求的是单点的值，
//那么updata区间1 - m更新操作 - 从上往下，单点求和操作 - 从下往上。
int lowbit(int x){
	return x & (-x);
} 
void add(int loc,int val){//在1 - loc位置增加val 

	while(loc > 0){  
		tree[loc] += val;
		loc -= lowbit(loc);	
	}
	
}
int getsum(int num){
	int sum = 0;
	while(num <= n){
		sum += tree[num];
		num += lowbit(num);
	}
	return sum;
}


void solve(){
	int ans = 0;
	rep(i,n,1){
		sum[i] = getsum(n) - getsum(lower_bound(a+1,a+1+n,i) - a+1) - *lower_bound(a+1,a+1+n,i) *
		(lower_bound(a+1,a+1+n,i) - sum + 1) ;	
	}
	int h = a[n];
	while(h > a[1]){
		ans++;
		if(upper_bound(sum+1,sum+1+h,k) == sum + h + 1){
			h = a[1];
		}else{
			h = upper_bound(sum+1,sum+1+h,k) - sum + 1;
		}
		
		//cout << "ni " <<h << endl;
	}
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d %d",&n,&k)){
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		per(i,1,n){
			add(i,a[i]);
			add(i-1,-a[i]);
		} 
		//cout << "ji" << endl;
		solve();
	}
	
	return 0;
}
