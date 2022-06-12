#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string> 
#include<cstring>
#include<set>
#define INF 0x7fffffff
using namespace std;
const int maxn = 100+ 10;
int max_sum[maxn],D[maxn][maxn];


int main(){
	int n = 0;
	cin >> n;
	for(int i = 1;i <= n;++i ){
		for(int j = 1;j <= i;++j){
			cin >> D[i][j];
		}
	}
	memset(max_sum,0,sizeof(max_sum));
	for(int i = n;i >= 1;--i){
		for(int j = 1; j <= i;++j){
			max_sum[j] = max( max_sum[j], max_sum[j+1] ) + D[i][j];
		}
	}
	
	cout << max_sum[1] << endl;
	
	return 0;
}
