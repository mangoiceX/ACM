#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 1e4 + 100;
struct Gas{
	int dist,gasoline;
};
Gas gas[maxn];
int n = 0,p = 0,l = 0;
void solve(){
	gas[0].dist = 0;gas[0].gasoline = 0;//将0设置为起点方便书写 
	//因为输入的数据dist是从小到大，我们将重点看成数轴的原点0，从n到0遍历 
	priority_queue<int> pque;
	int times = 0,tank = p;
	for(int i = n;i >= 0;--i){
		while(l - tank > gas[i].dist){//现在所能到达的最小坐标，tank表示现在为止所有的有油(拥有的） 
			if(pque.empty()){//不减去消耗的油 
				//printf("%d %d %d -1\n",i,gas[i].dist,tank);
				printf("-1\n");
				return ;
			}
			tank += pque.top();
			//printf("%d\n",tank);
			pque.pop();
			times++;
		}
		pque.push(gas[i].gasoline);
	}
	printf("%d\n",times);
}
int main(){
	while(scanf("%d",&n) != EOF && n){
	
		for(int i = 1;i <= n;++i){
			scanf("%d %d",&gas[i].dist,&gas[i].gasoline);
		}
		scanf("%d %d",&l,&p);
		solve();
	}
	
	return 0;
} 
