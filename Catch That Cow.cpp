#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 200100;
int n = 0,k = 0,minv = 0;
queue<int> que;
int time[maxn];
void bfs(){
	
	que.push(n);
	time[n] = 1;
	if(n >= k){
		minv = n - k + 1;
		return ;
	}
	while(!que.empty()){
		int u = que.front();
		que.pop();
		if(u == k){
			minv = time[u];
			return ;
		}
		
		if(time[u-1] == 0 && u - 1 >= 0){
			time[u-1] = time[u] + 1;
			que.push(u - 1);
		}
		if(time[u+1] == 0 && u + 1 <= k){
			time[u+1] = time[u] + 1;
			que.push(u + 1);
		}
		if(u <= k && time[2*u] == 0){
			time[2*u] = time[u] + 1;
			que.push(2*u);
		}
	}
}
int main(){
	
	while(cin >> n >> k){
		while(!que.empty()) que.pop();
		//memset(time,0,sizeof(time));
		fill(time,time + maxn,0);
		minv = 0;
		bfs();
		cout << minv - 1 << endl;
	}
	
	
	
	return 0;
} 
