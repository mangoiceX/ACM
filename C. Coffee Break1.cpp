#include<bits/stdc++.h>
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 2e5 + 100;
typedef long long LL;
struct node{
	int time;
	int loc;
	int flag;
};
node nod[maxn];
int a[maxn];
bool vis[maxn];
vector<int> mp[maxn];
int n = 0,m = 0,d = 0;
bool cmp1(node a,node b){
	return a.time < b.time;
}
bool cmp2(node a,node b){
	return a.loc < b.loc;
}
int loca[maxn];
void dfs(int st,int biao){
	loca[nod[st].loc] = biao;
//	if(st == 0){
	//	cout << "fa " << nod[st].loc << " " << biao << endl;
	//}
	for(int i = 0;i < n - mp[st][0];++i){
		int v = mp[st][i];
		if(!vis[v]){
			//if(i == 0){
			//	cout << "haha " << mp[0][0] << endl;
			//}
			vis[v] = true;
			//nod[i].flag = biao;
			loca[nod[v].loc] = biao;
			dfs(mp[st][i],biao+1);
		}
	}
}
int main(){
	while(~scanf("%d %d %d",&n,&m,&d)){
		int cnt = 1;
		fill(vis,vis+n,false);
		for(int i = 0;i < n;++i){
			nod[i].loc = i;
			scanf("%d",&nod[i].time);
		}
		sort(nod,nod+n,cmp1);
		for(int i = 0;i < n;++i){
			a[i] = nod[i].time;
		}
		for(int i = 0;i < n;++i){
			int loc = upper_bound(a,a+n,a[i]+d) - a;
			//if(loc == n){
			//	mp
			//}
			//cout << "em " << i << " " << loc << endl;
			mp[i].push_back(loc);
		}
		for(int i = 0;i < n;++i){
			if(vis[i] == false){
				vis[i] = true;
				dfs(i,cnt++);
			}
		}
		
		//sort(nod,nod+n,cmp2);
		printf("%d\n",cnt-1);
		for(int i = 0;i < n;++i){
			printf("%d ",loca[i]);
		}
	}
	
	return 0;
} 
