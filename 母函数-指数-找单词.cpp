#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 55;
double temp[maxn],sup[maxn];
const int size = 26;
const int ma = 50; 
int num[maxn];
LL f[maxn];
void init(){
	f[0] = 1;
	for(int i = 1;i <= 20;++i){
		f[i] = f[i-1]*i;
	}
}
int main(){
	int T = 0;
	scanf("%d",&T);
	init();
	/*
	for(int i = 1;i <= ma;++i){
		cout << i << " " << f[i] << endl;
	}
	*/
	while(T--){
		fill(temp,temp+maxn,0);fill(sup,sup+maxn,0);
		for(int i = 1;i <= size;++i){
			scanf("%d",&num[i]);
		}
		//for(int i = 0;i <= num[1];++i){
		//	sup[i] = 1.0/f[i];
		//}
		sup[0] = 1;
		for(int i = 1;i <= size;++i){
			for(int j = 0;j <= ma;++j){
				for(int k = 0;k*i + j <= ma && k <= num[i];++k){
					//temp[j+k*i] += (sup[j]/f[k]);
					temp[j+k*i] += sup[j];
				}
			}
			for(int j = 0;j <= ma;++j){
				sup[j] = temp[j];
				temp[j] = 0;
			}
		}
		int ans = 0;
		for(int i = 1;i <= ma;++i){
			//ans += (sup[i]*f[i]);
			ans += sup[i];
			//cout << "nima " << sup[i] << endl;
		}
		printf("%d\n",ans);
	}
	return 0;
}
