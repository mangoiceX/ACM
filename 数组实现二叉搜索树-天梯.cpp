#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
#define INF 0x3f3f3f3f
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
typedef long long LL;
int n = 0;
int a[maxn+10];
void bt(int val,int root){
	if(a[root] == -INF){
		a[root] = val;
		return ;
	}else if(val >= a[root]){
		bt(val,2*root);
		return ;
	}else{
		bt(val,2*root+1);
		return ;
	}
	return ;
}
void bfs(int root){
	queue<int> que;
	que.push(root);
	int cnt = 1;//num = 1;
	//int up = pow(2,log2(n+1));//rest = n - up,up1 = pow(2,log(2,n+1)-1);
	bool flag = true;
	while(!que.empty()){
		int s = que.front();
		que.pop();
		printf("%d%c",a[s],cnt == n ? '\n' : ' ');
		++cnt;
		if(a[2*s] != -INF){
			que.push(2*s);
			if(2*s > n){
				flag = false;
			}
		}
		if(a[2*s+1] != -INF){
			que.push(2*s+1);
			if(2*s+1 > n){
				flag = false;
			}
		}
	}
	if(flag == true){
		printf("Yes");
	}else{
		printf("No");
	}
	return ;
}
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= 100*n;++i){
		a[i] = -INF;
	}
	per(i,1,n){
		int x = 0;
		scanf("%d",&x);
		bt(x,1);
	}
	bfs(1);
	
	return 0;
}
