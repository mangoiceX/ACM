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
const int maxn = 1e2;
int n = 0,k = 0; 
struct node{
	LL x,y;
};
node a[maxn+10];
vector<LL> vt;
bool cmp(LL x,LL y){
	return x > y;
}
int main(){
	//std::ios::sync_with_stdio(false);
	
	int T = 0;
	scanf("%d",&T);
	while(T--){
		//priority_queue<LL> pq;
		vt.clear();
		scanf("%d %d",&n,&k);
		per(i,1,n){
			scanf("%lld %lld",&a[i].x,&a[i].y);
		} 
		per(i,1,n){
			per(j,i+1,n){
				per(k,j+1,n){
					LL sum = abs((a[j].x-a[i].x)*(a[k].y-a[i].y) - (a[k].x-a[i].x)*(a[j].y-a[i].y));
					vt.push_back(sum);
					//pq.push(sum);
				}
			}
		}
		//sort(vt.begin(),vt.end(),cmp);//复杂度太高 
		nth_element(vt.begin(),vt.begin()+n*(n-1)*(n-2)/6-k,vt.end());
		/*
		STL中的nth_element()方法的使用 通过调用nth_element(start, start+n, end) 
		方法可以使第n小元素处于第n位置（从0开始,其位置是下标为 n的元素），
		并且比这个元素小的元素都排在这个元素之前，比这个元素大的元素都排在这个元素之后，
		但不能保证他们是有序的
		*/ 
		LL ans = vt[n*(n-1)*(n-2)/6-k];
		/* 
		LL ans = 0;
		while(k--){//优先队列的复杂度偏高 
			ans = pq.top();
			pq.pop();
		}
		*/
		if(ans % 2 == 0){//注意从0开始，还有就是整数/2的小树部分要么是.00,要么就是.50 
			printf("%lld.00\n",ans/2);
		}else{
			printf("%lld.50\n",ans/2);
		}
	}
	
	return 0;
}

