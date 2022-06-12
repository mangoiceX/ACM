#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
const int maxn = 1000 + 10;
using namespace std;
struct Node{
	int x,y;
};
int n = 0;
Node node[maxn];
bool cmp0 (Node a,Node b){
	return a.x < b.x;
}
bool cmp1(Node a,Node b){
	if(a.x == b.x){
		return a.y < b.y;
	} else{
		return a.x < b.x;
	}
}
bool cmp2(Node a,Node b){
	if(a.x == b.x){
		return a.y > b.y;
	} else{
		return a.x < b.x;
	}
}
bool solve(){
	int sym = (node[0].x + node[n-1].x) ;

	for(int i = 0;i < n / 2;++i){
		
		if((node[i].x + node[n- 1 - i].x)  != sym){
			return false;
		}
		// 要加上两个点的x坐标要不相等的条件，否则会WA 边界条件是中间对称轴上有很多点 
		if(node[i].x != node[n- 1 - i].x && node[i].y != node[n - 1 -i].y ){
			return false;
		}
	}
	return true;
}
int main(){
	int T = 0;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 0;i < n;++i){
			cin >> node[i].x >> node[i].y;
		}
		sort(node,node + n,cmp0);
		sort(node,node + n/2,cmp1);
		sort(node + n/2,node + n,cmp2);
		if(solve()){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
			
	}
	
	
	
	return 0;
}
