#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#define INF  1e5
using namespace std;
const int maxn = 9710;//1e4���Թ���1e3RE 
//ע�⣬n<100,����������ȫͼ99*98���ߣ��ٿ�������ı߽� 
struct MGraph{
	//char vertex[maxn];//�����   
	int edges[maxn][maxn];//�ڽӾ���,�ɿ����߱� 
	int n,e;//ͼ�е�ǰ�Ķ������ͱ���     
};
MGraph G;

struct Edge{
	int u;//�ߵ���ʼ����   
	int v; //�ߵ���ֹ����   
	int w;//�ߵ�Ȩֵ   
	bool flag = false;
};
bool cmp(Edge a,Edge b){
	return a.w < b.w;
}
int e_size = 0; //�ߵ����� 
int kruskal(){
	int i,j,sn1,sn2,k;
	int vset[maxn];//�������飬�ж����������Ƿ���ͨ 
	Edge E[maxn]; //������еı�   
	k = 1;//E������±��1��ʼ   
	for(i = 1;i <= G.n;++i){
		//for(int j =1;j <= G.n;++j){//j��1��ʼ�����ظ���1,2��2,1���ظ����� 
		for(int j =i + 1;j <= G.n;++j){//��������ظ� 
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
	//������� 
	/*
	for(int i = 1;i <= e_size;++i){
		cout << "emm " << E[i].w;
	}
	cout << endl; 
	*/
	for(int i = 1;i <= G.n;++i){//��ʼ����������   
		vset[i] = i;
	}
	k = 1,j = 1;
	int res = 0;
	while(k < G.n){//���ɵı��������Ҫ�պ�Ϊ�ܱ���   
		sn1 = vset[E[j].u],sn2 = vset[E[j].v];//�õ����������ڵļ��ϱ��   
		//cout << " " << E[j].u << " " << E[j].v << " " << sn1  <<" " << sn2 << " " << k << endl;
		if(sn1 != sn2){		//����ͬһ���ϱ���ڵĻ����ѱ߼�����С������   
			res += E[j].w;	//�ظ��ı߱���1,2��2,1 ,���� ����1,2ʱ��
			//����Ὣ�ڵ�1,2����Ϊͬһ����ͨ��֧,�����ظ���������������if���� 
			 
			E[j].flag = true;//����Ѿ��ù� 
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
