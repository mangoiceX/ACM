#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int maxn = 2e5 + 100;
map<int,int> mpx,mpy;
struct node{
	int x,y;
	int time;
	node(){
		x = y =0;
		time = 1;
	}
	/*
	bool operator  < (const node &a){
		
		//return (a.x == x ) && (a.y == y);
		
		if(a.x < x){
			return false;
		}
		if(a.y < y){
			return false;
		}
		return true;	
	}
	*/
//	bool operator < (const node &a) const{
   //     return (a.x != x) || (a.y != y);
   // }
    
};
map<node,int> mp;
node data[maxn];
int same_node[maxn],samex[maxn],samey[maxn];
long long cal(int x){
	return (x-1)*x/2;
}
bool cmp(node a,node b){
	if(a.x != b.x){
		return a.x < b.x;
	}else{
		return a.y < b.y;
	}
}
bool operator == (node a ,node b){
	return (a.x == b.x) && (a.y == b.y);
}
int main(){
	int n = 0,x = 0,y = 0;
	while(scanf("%d",&n) != EOF && n){
		memset(same_node,0,sizeof(same_node));
		memset(samex,0,sizeof(samex));
		memset(samey,0,sizeof(samey));
		mp.clear();mpx.clear();mpy.clear();
		
		for(int i = 0;i < n;++i){
			scanf("%d %d",&x,&y);
			data[i].x = x,data[i].y = y;
			++mpx[x];
			++mpy[y];
			//++mp[data[i]];
		}
		sort(data,data+n,cmp);
		//map<node,int>::iterator it;
		map<int,int>::iterator it1;
		map<int,int>::iterator it2;
		/*
		int size1 = 0;
		for(it = mp.begin(); it != mp.end();it++){
			if(it->second > 1){
				same_node[size1++] = it->second;
				cout << "um " << same_node[size1-1] << endl;
			}
		}
		*/
		int size1 = 0;
		for(int i = 1;i < n;++i){
			int p = 1;
			while(data[i] == data[i-1]){
				++i;
				++p;
			}
			same_node[size1++] = p;
		}
		int size2 = 0;
		for(it1 = mpx.begin(); it1 != mpx.end();it1++){
			if(it1->second > 1){
				samex[size2++] = it1->second;
			}
		}
		int size3 = 0;
		for(it2 = mpy.begin(); it2 != mpy.end();it2++){
			if(it2->second > 1){
				samey[size3++] = it2->second;
			}
		}
		
		
		long long ans = 0;
		//int ans = 0;
		for(int i = 0;i < size2;++i){
			ans += cal(samex[i]);
		}
		for(int i = 0;i < size3;++i){
			ans += cal(samey[i]);
		}
		for(int i = 0;i < size1;++i){
			ans -= cal(same_node[i]);
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
