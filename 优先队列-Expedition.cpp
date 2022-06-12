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
	gas[0].dist = 0;gas[0].gasoline = 0;//��0����Ϊ��㷽����д 
	//��Ϊ���������dist�Ǵ�С�������ǽ��ص㿴�������ԭ��0����n��0���� 
	priority_queue<int> pque;
	int times = 0,tank = p;
	for(int i = n;i >= 0;--i){
		while(l - tank > gas[i].dist){//�������ܵ������С���꣬tank��ʾ����Ϊֹ���е�����(ӵ�еģ� 
			if(pque.empty()){//����ȥ���ĵ��� 
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
