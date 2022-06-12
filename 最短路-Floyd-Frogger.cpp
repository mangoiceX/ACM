#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define INF 1e6
using namespace std;
const int maxn = 200 + 10;
struct node{
	double x,y;
};
node nod[maxn];
double d[maxn][maxn];
int n = 0;
double cal(node a,node b){//因为pow的精度问题，此处不能采用 
	//return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2));
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void init(){
	for(int i = 0;i < n;++i){
		for(int j = 0;j < n;++j){
			d[i][j] = d[j][i] = INF;
		}
	}
}

void Floyd_w(){
	for(int k = 0;k < n;++k){//k循环一定要放在外面，否则会错 
		for(int i = 0;i < n;++i){
			for(int j = 0;j < n;++j){
				//for(int k = 0;k < n;++k){//取 
				d[j][i] = d[i][j] = min(d[i][j],max(d[i][k] , d[k][j]));
				//}
			}
		}
	}
}
int main(){
	int kase = 0;
	while(scanf("%d",&n) != EOF && n){
		//init();//可以不用初始化，因为后面会算完全图 
		for(int i = 0;i < n;++i){
			scanf("%lf %lf",&nod[i].x,&nod[i].y);
		}
		for(int i = 0;i < n;++i){
			for(int j = 0;j < n;++j){//相等时，要设置为0 
				d[i][j] = d[j][i] = (i == j) ? 0 : (cal(nod[i],nod[j])); 
				//d[i][j] = d[j][i] = (cal(nod[i],nod[j]));
			}
		}
		Floyd_w();
		printf("Scenario #%d\n",++kase);
		printf("Frog Distance = %.3lf\n\n",d[0][1]);
	}
	
	
	return 0;
}
