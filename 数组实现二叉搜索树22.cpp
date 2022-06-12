#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
#define INF 100000
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
typedef long long LL;
int n = 0;
int a[maxn+10];
void bt(int val,int root){
	if(a[root] == -INF){
		a[root] = val;
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
	//	if(cnt == n){
	//		break;
	//	}
		++cnt;
		if(a[2*s] != -INF && a[2*s+1] != -INF){
			que.push(2*s);que.push(2*s+1); 
		}else if(a[2*s] == -INF && a[2*s+1] != -INF){
			flag = false;
			que.push(2*s+1);
		}else if(a[2*s] != -INF && a[2*s+1] == -INF){
			flag = false;
			que.push(2*s);
		}
	
	}
	if(flag == true){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
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
	//per(i,1,10*n){
	//	printf("%d ",a[i]);
	//}
	bfs(1);
	
	return 0;
}
