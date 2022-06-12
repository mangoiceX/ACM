#include<bits/stdc++.h>
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 2e5 + 100;
typedef long long LL;
struct node{
	int time;
	int loc;
	int flag;
	//node const* const nod;
	friend bool operator < ( const node &a,const node &b){
		a.time < b.time;
	}
	bool operator () (node const x, node const index) const{
  		return x.time < index.time;
 }//
	//node(int a){
	//	time = a;
	//}
};
node nod[maxn];
//int nod[maxn];
int n = 0,m = 0,d = 0;
bool cmp1(node a,node b){
	return a.time < b.time;
}
int main(){
	while(~scanf("%d %d %d",&n,&m,&d)){
		for(int i = 0;i < n;++i){
			nod[i].loc = i;
			scanf("%d",&nod[i].time);
		}
		sort(nod,nod+n,cmp1);
		for(int i = 1;i < n;++i){
			//if(nod[i].time - nod[i-1].time > d){
			//	nod[i-1].flag = i;
			//}
			node x ;
			//nod[i].flag = upper_bound(nod,nod+n,nod[i].time + d,x,[&]
			//(const node x,const node y){
			//	return x.time < y.time;
			//});
			nod[i].flag = upper_bound(nod,nod+n,nod[i].time + d);
		}
		
	}
	
	return 0;
} 
