#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
using namespace std;
const int maxn = 10;
double a[maxn+10][maxn+10],w[maxn+10][maxn+10];
double rs[maxn+10];//ÿ��֮�� 
double cs[maxn+10];//ÿ��֮�� 
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
		rs[i] /= sum;//����Ȩ������ 
	}
	
	double lan[10] = {0};
	double ans = 0;//lanta��ֵ
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
	printf("Ȩ������Ϊ�� ");
	per(i,1,r){
		printf("%lf ",rs[i]);
	}
	printf("lanta��ֵ�ǣ�%lf\n",ans);
	double ci = (ans - r) / (r - 1);
	printf("һ���Լ���ָ��CI�ǣ�%lf\n",ci);
	printf("%lf\n",ci / ri[r]);
	if(ci / ri[r] < 0.1){
		puts("��ϲ�㣬һ���Լ���ͨ����������ݹ���Ĳ���Ӵ!");
	}else{
		puts("what a shame,˵������һ�����ݾͿ�����"); 
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

�����ʣ����ڣ�Ͷ�ųɱ� X���� 
3 3
1 0.75 1.25
1.33 1 1.5
0.8 0.67 1
 
����Ƶ�� cctv1 ���� ����  S���� 
3 3
1 0.67 3
1.5 1 3
0.33 0.33 1

T���� ������ ���� ѧ��
3 3
1 0.8 1.6 
1.25 1 1.4
0.625 0.714 1

P���� 1-4K 4-8K >8K
3 3
1 0.8 0.6
1.25 1 0.714 
1.67 1.4 1

Q���� ѧ��
3 3
1 0.75 0.2
1.3 1 0.33
5 3 1

����R ����
3 3
1 2 4
0.5 1 1.5
0.25 0.67 1

 
���º��T����
4 4
1 0.8 1.6 1
1.25 1 1.4 1.25
0.625 0.714 1 0.6
1 0.8 1.67 1

�¼����ʱ�����
4 4
1 0.2 0.33 0.125 
5 1 4 0.5
3 0.25 1 0.2
8 2 5 1 

*/
