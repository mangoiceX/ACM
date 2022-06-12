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
	//����һ����С����ȡ����ֵ�����ȶ��� 
	priority_queue<int,vector<int>,greater<int> >que;
	LL ans = 0;
	for(int i = 1;i <= n;++i){
		que.push(wood[i]);
	}
	while(que.size() > 1){//ѭ����ֻʣһ��ľ��Ϊֹ 
		//ȡ����̺ʹζ̵�ľ�� 
		int a1 = que.top();
		que.pop();
		int a2 = que.top();
		que.pop();
		//������ľ��ϲ� 
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
