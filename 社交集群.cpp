#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f
typedef long long LL;
using namespace std;
const int maxn = 1e3;
int n = 0,m = 0;
int a[maxn+10];
int ran[maxn+10],f[maxn+10];
void init(){
	per(i,1,n){
		ran[i] = 0;
		f[i] = i;
	}
}
int find(int a){
	if(f[a] == a){
		return a;
	}
	return f[a] = find(f[a]);
}
void unite(int a,int b){
	a = find(a);b = find(b);
	if(a == b){
		return ;
	}else{
		if(ran[a] < ran[b]){
			f[a] = b;
		}else{
			f[b] = a;
			if(ran[a] == ran[b]){
				++ran[a];
			}
		}
	}
}
bool same(int a,int b){
	return find(a) == find(b);
}
struct rule{
	bool operator()(int a,int b){
		return a >= b;
	}
};
int main(){
	while(~scanf("%d",&n)){
		map<int,int> mp;
		init();
		per(i,1,n){
			scanf("%d:",&m);
			per(j,1,m){
				int x = 0;
				scanf("%d",&x);
				if(mp[x] != 0){
					unite(mp[x],i);
					continue;
				}	
				mp[x] = i;
			}
		} 
		//per(i,1,n){
		//	printf("%d%c",f[i],i == n ? '\n' : ' ');
		//}
		set<int> st[maxn+10];
		per(i,1,n){
			st[f[i]].insert(i);
		}
		multiset<int,rule> ss;//这里用的是multiset 
		per(i,1,n){
			if(st[i].size() != 0){
				ss.insert(st[i].size());
			}
		}
		printf("%d\n",ss.size());
		multiset<int,rule>::iterator it = ss.begin();
		printf("%d",*it);
		++it;
		for(it = it;it != ss.end();++it){
			printf(" %d",*it);
		}
		printf("\n");
	}
	
	return 0;
} 
