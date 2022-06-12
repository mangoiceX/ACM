#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#define INF  1e5
using namespace std;
const int maxn = 110;
int maj[maxn][maxn];
bool used[maxn];
int min_cost[maxn];//�Ӽ���X�����ıߵ�ÿ���������СȨֵ 
int V = 0;

int prime(){
	
	fill(min_cost,min_cost + maxn,INF);//��ʼ�� 
	fill(used,used+maxn,false);
	
	min_cost[0] = 0;//��㻯 
	int res = 0;
	
	while(true){
		int v = -1;//�˳���� 
		for(int u = 0;u < V;++u){
			if(used[u] == false && (v == -1 || min_cost[u] < min_cost[v])){
				v = u;
			}
		}
		
		if(v == -1){//�˳���� ��V-X������û��Ԫ�� 
			break;
		}
		
		used[v] = true;//�ҵ�����Ҫ��ĵ�ʱ�Ĳ��� 
		res += min_cost[v];
		
		for(int u = 0;u < V;++u){	//����v���ڵĵ�ľ���ȫ����ʼ�� 
			min_cost[u] = min(min_cost[u],maj[v][u]);
		}
	}
	
	return res;
	
}
int main(){
	
	while(scanf("%d",&V) != EOF && V){
		for(int i = 0;i < V*(V-1)/2;++i){
			int x = 0,y = 0,dist = 0;
			scanf("%d %d %d",&x,&y,&dist);
			maj[x-1][y-1] = maj[y-1][x-1] = dist;
		}
		int ans = prime();
		printf("%d\n",ans);
	} 
	
	
	
	
	return 0;
}
