#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 100 + 10;
int d[maxn][maxn];
int n = 0,m = 0;

void Floyd(){
	for(int k = 1;k <= n;++k){//�м�ڵ���������ѭ�� 
		for(int i = 1;i <= n;++i){
			for(int j = 1;j <= n;++j){
				d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
			}
		}
	}
}

void init(){
	fill(d[0],d[0]+maxn*maxn,INF);	
}
int main(){
	scanf("%d %d",&n,&m);
	init();
	for(int i = 0;i < m;++i){
		int a = 0,b = 0;
		scanf("%d %d",&a,&b);
		d[b][a] = 1;		//bָ��a,����һ������� 
	}
	Floyd();
	int ans = 0;
	for(int i = 1;i <= n;++i){
		int cnt = 0;
		for(int j = 1;j <= n;++j){
			if(d[i][j] != INF || d[j][i] != INF){//���ַ��򶼿��Խ���һ�ֹ�ϵ 
				++cnt;
			}
		}
		if(cnt == n - 1){
			++ans;
		}
	}
	printf("%d\n",ans);
	return 0;
} 
