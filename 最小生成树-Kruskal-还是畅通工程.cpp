#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#define INF  1e5
using namespace std;
const int maxn = 9710;//1e4可以过，1e3RE 
//注意，n<100,最多可能是完全图99*98条边，再考虑数组的边界 
struct MGraph{
	//char vertex[maxn];//顶点表   
	int edges[maxn][maxn];//邻接矩阵,可看做边表 
	int n,e;//图中当前的顶点数和边数     
};
MGraph G;

struct Edge{
	int u;//边的起始顶点   
	int v; //边的终止顶点   
	int w;//边的权值   
	bool flag = false;
};
bool cmp(Edge a,Edge b){
	return a.w < b.w;
}
int e_size = 0; //边的数量 
int kruskal(){
	int i,j,sn1,sn2,k;
	int vset[maxn];//辅助数组，判定两个顶点是否连通 
	Edge E[maxn]; //存放所有的边   
	k = 1;//E数组的下标从1开始   
	for(i = 1;i <= G.n;++i){
		//for(int j =1;j <= G.n;++j){//j从1开始会有重复，1,2与2,1会重复计算 
		for(int j =i + 1;j <= G.n;++j){//不会出现重复 
			if(G.edges[i][j] != 0 && G.edges[i][j] != INF){//
				E[k].u = i,E[k].v = j,E[k].w = G.edges[i][j];
				++k;
			}
		}
	}
	//cout << E[1].u << " mam " << E[1].v << endl;
	e_size = k - 1;
	
	//heapsort(E,k,sizeof(E[0]));
	sort(E+1,E+k,cmp);
	//调试输出 
	/*
	for(int i = 1;i <= e_size;++i){
		cout << "emm " << E[i].w;
	}
	cout << endl; 
	*/
	for(int i = 1;i <= G.n;++i){//初始化辅助数组   
		vset[i] = i;
	}
	k = 1,j = 1;
	int res = 0;
	while(k < G.n){//生成的边数，最后要刚好为总边数   
		sn1 = vset[E[j].u],sn2 = vset[E[j].v];//得到两顶点属于的集合编号   
		//cout << " " << E[j].u << " " << E[j].v << " " << sn1  <<" " << sn2 << " " << k << endl;
		if(sn1 != sn2){		//不在同一集合编号内的话，把边加入最小生成树   
			res += E[j].w;	//重复的边比如1,2与2,1 ,但是 在算1,2时，
			//后面会将节点1,2划分为同一个联通分支,所以重复的情况，会过不了if条件 
			 
			E[j].flag = true;//标记已经用过 
			++k;
			for(int i = 1;i <= G.n;++i){
				if(vset[i] == sn2 ){
					vset[i] = sn1;
				}
			}	
		}
		++j;
	}
	return res;
}
int main(){
	int x = 0,y= 0,wt = 0;
	while(scanf("%d",&G.n) != EOF && G.n){
		for(int i = 0;i <= G.n;++i){
			for(int j = 0;j <= G.n;++j){
				G.edges[i][j] = INF;
			}
		}
		for(int i = 1;i <= G.n*(G.n-1)/2;++i){
			scanf("%d %d %d",&x,&y,&wt);
			G.edges[x][y] = G.edges[y][x] = wt;
		}		
		int ans1 = kruskal();
		printf("%d\n",ans1);
		//for(int i = 1;i <= e_size;++i){
		//	if(E[i])
		//}
	}
	
	
	
	return 0;
}
