#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int maxn = 1e5 + 10;
int tree[maxn];
int n = 0;
int lowbit(int x){
	return x & (-x);
}
void add(int loc,int val){
	while(loc > 0){
		tree[loc] += val;
		loc -= lowbit(loc);
	}
}
int getsum(int loc){
	int ans = 0;
	for(int i = loc;i <= n;i += lowbit(i)){
		ans += tree[i];
	}
	return ans;
}
int main(){
	int a = 0,b = 0;
	while(cin >> n && n){
		memset(tree,0,sizeof(tree));
		
		for(int i = 0;i <n;++i){
			cin >> a >> b;
			add(b,1);
			add(a - 1,-1);	
		}
		for(int j = 1;j <= n;++j){
			if(j > 1){
				cout << " ";
			}
			cout << getsum(j);
			
		}
		cout << endl;
	}
	
	
	
	return 0;
}
