#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
typedef long long LL;
const int maxn = 2e4 + 100;
int n,wood[maxn];
void solve(){
	//声明一个从小到大取出数值的优先队列 
	priority_queue<int,vector<int>,greater<int> >que;
	LL ans = 0;
	for(int i = 1;i <= n;++i){
		que.push(wood[i]);
	}
	while(que.size() > 1){//循环到只剩一块木板为止 
		//取出最短和次短的木块 
		int a1 = que.top();
		que.pop();
		int a2 = que.top();
		que.pop();
		//把两块木块合并 
		ans += a1 + a2;
		que.push(a1 + a2);
	}
	printf("%I64d\n",ans);
}
int main(){
	while(scanf("%d",&n) != EOF){
		for(int i = 1;i <= n;++i){
			scanf("%d",&wood[i]);
		}
		solve();
	}
	
	return 0;
}
