#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
typedef long long LL;
const double eps=1.0e-5;
const int maxn=1e4 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int dir[4] = {1,10,100,1000};
int n = 0,m = 0; 
int prime[maxn];
bool is_prime[maxn];
bool vis[maxn];
struct node{
	int num,step;
	node(int numm,int ss):num(numm),step(ss){
	}
	node(){
	}
};
void ouler(int n){
	fill(is_prime,is_prime+maxn,true);
	is_prime[0] = is_prime[1] = false;
	int cnt = 0;
	per(i,2,n){
		if(is_prime[i] == true){
			prime[cnt++] = i;
		}
		for(int j = 0;j < cnt && i * prime[j] <= n;++j){
			is_prime[i*prime[j]] = false;
			if(i % prime[j] == 0){
				break;
			}
		}
	}
	//return cnt;
} 
void bfs(int x,int y){
	fill(vis,vis+maxn,false);
	queue<node> que;
	que.push(node(x,0));
	vis[x] = true;
	while(!que.empty()){
		node u = que.front();
		que.pop();
		if(u.num == y){
			printf("%d\n",u.step);
			return ;
		}
		
		per(k,0,3){
			int ty = u.num - u.num / dir[k] % 10 * dir[k];//精华所在 
			per(i,0,9){	
				//int tx = u.num - u.num / dir[k] % 10 * dir[k];
				//这是错误的，因为一个i循环时，tx就发生了变化，所以要写在i循环外面 
				if(k == 3 && i == 0){//首位不能是0 
					continue;
				}
				if(k == 0 && i % 2 == 0){//末尾不能是0 
					continue;
				}
				if(u.num / dir[k] % 10 == i){//相等 
					continue;
				}
				int tx = ty + i * dir[k];
				if(vis[tx] == false && is_prime[tx]){//因为有前面的剪枝，所以这里不需要 
					que.push(node(tx,u.step + 1));//再判断 tx >= 1000 && tx <= 9999
					vis[tx] = true;
				} 
			}
		}
	}
	printf("Impossible\n");
}

int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	ouler(10000);
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&m,&n);
		bfs(m,n);
	}
	
	return 0; 
}
