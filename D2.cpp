#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
typedef long long LL;
int n = 0,k = 0;
char name[40][100];
vector<double> score[40];
struct node{
	int id ;
	double so;
}p[40];
bool cmp(node x,node y){
	return x.so > y.so;
}

int main(){
	while(~scanf("%d %d",&n,&k)){
		per(i,1,n){
			scanf("%s",name[i]);
			per(j,1,k){
				double x = 0;
				scanf("%lf",&x);
				score[i].push_back(x);
			}
			sort(score[i].begin(),score[i].end());
			double sum = 0;
			per(j,1,k-1){
				sum += score[i][j];
			}
			p[i].id = i;
			p[i].so = sum;
		}
		sort(p+1,p+1+n,cmp);
		// solve();
		printf("%s\n",name[p[1].id]);
	}
	return 0;
}