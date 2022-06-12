#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
using namespace std;
const int maxn = 10;
double a[maxn+10][maxn+10],w[maxn+10][maxn+10];
double rs[maxn+10];//每行之和 
double cs[maxn+10];//每列之和 
int r = 0,c = 0;
double ri[12] = {0,0,0,0.58,0.90,1.12,1.24,1.32,1.41,1.45,1.49,1.51};
void solve(){
	per(i,1,c){
		per(j,1,r){
			a[j][i] /= cs[i];
		}
	}
	
	per(i,1,r){
		per(j,1,c){
			rs[i] += a[i][j];
		}
	}
	
	double sum = 0;
	per(i,1,r){
		sum += rs[i];
	}
	per(i,1,r){
		rs[i] /= sum;//最后的权重向量 
	}
	
	double lan[10] = {0};
	double ans = 0;//lanta的值
	per(i,1,r){
		per(j,1,1){
			per(k,1,c){
				lan[i] += (w[i][k] * rs[k]);
			}	
		}	
	} 
	
	per(i,1,r){
		ans += (lan[i] / rs[i]);
	}
	ans /= r;
	printf("权重向量为： ");
	per(i,1,r){
		printf("%lf ",rs[i]);
	}
	printf("lanta的值是：%lf\n",ans);
	double ci = (ans - r) / (r - 1);
	printf("一致性检验指标CI是：%lf\n",ci);
	printf("%lf\n",ci / ri[r]);
	if(ci / ri[r] < 0.1){
		puts("恭喜你，一致性检验通过，你的数据构造的不错哟!");
	}else{
		puts("what a shame,说不定改一下数据就可以了"); 
	}
}
int main(){
	while(~scanf("%d %d",&r,&c)){
		memset(cs,0,sizeof(cs)); 	memset(rs,0,sizeof(rs));
		per(i,1,r){
			per(j,1,c){
				scanf("%lf",&a[i][j]);
			}
		}
		memcpy(w,a,sizeof(a));
		per(i,1,c){
			per(j,1,r){
				cs[i] += a[i][j];
			}
		}
		solve();
	}
	
	return 0;
}

/*

收视率，受众，投放成本 X矩阵 
3 3
1 0.75 1.25
1.33 1 1.5
0.8 0.67 1
 
各个频道 cctv1 湖南 重庆  S矩阵 
3 3
1 0.67 3
1.5 1 3
0.33 0.33 1

T矩阵 月收入 年龄 学历
3 3
1 0.8 1.6 
1.25 1 1.4
0.625 0.714 1

P矩阵 1-4K 4-8K >8K
3 3
1 0.8 0.6
1.25 1 0.714 
1.67 1.4 1

Q矩阵 学历
3 3
1 0.75 0.2
1.3 1 0.33
5 3 1

矩阵R 年龄
3 3
1 2 4
0.5 1 1.5
0.25 0.67 1

 
更新后的T矩阵
4 4
1 0.8 1.6 1
1.25 1 1.4 1.25
0.625 0.714 1 0.6
1 0.8 1.67 1

新加入的时间矩阵：
4 4
1 0.2 0.33 0.125 
5 1 4 0.5
3 0.25 1 0.2
8 2 5 1 

*/
