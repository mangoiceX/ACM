#include<bits/stdc++.h>
#include<set>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 100;
struct node{
	int val;
	int id;
};
set<node> st;
int ans[maxn];
node nod[maxn];
vector<int> vt;
int n = 0,m = 0,d = 0;
bool cmp(node a,node b){
	return a.val < b.val;
}
bool operator < (node a,node b){
	if(a.val== b.val){
		return a.id < b.id;
	}else{
		return a.val < b.val;
	}
}
int main(){
	while(~scanf("%d %d %d",&n,&m,&d)){
		for(int i = 0;i < n;++i){
			scanf("%d",&nod[i].val);
			nod[i].id = i;
		}
		sort(nod,nod+n,cmp);
		set<node>::iterator it;
		int cnt = 0;
		for(int i = 0;i < n;++i){
			node temp;
			temp.val = nod[i].val;temp.id = -1;
			it = st.upper_bound(temp);
			if(it == st.begin()){
				temp.val += d;
				temp.id = ++cnt;
				ans[nod[i].id] = cnt;
				//it--;
				//st.erase(st.begin());
				st.insert(temp);
			}else{
				it = st.begin();
				//temp = *it;
				temp.val = nod[i].val + d;
				ans[nod[i].id] = it->id;
				temp.id = it->id;
				st.erase(it);
				st.insert(temp);
			}
		}
		printf("%d\n",cnt);
		for(int i = 0;i < n;++i){
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	
	return 0;
} 
