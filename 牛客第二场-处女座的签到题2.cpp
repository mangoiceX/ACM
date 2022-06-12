#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

typedef long long LL;

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 1e2;
int n = 0,k = 0; 
struct node{
	LL x,y;
};
node a[maxn+10];
vector<LL> vt;
bool cmp(LL x,LL y){
	return x > y;
}
int main(){
	//std::ios::sync_with_stdio(false);
	
	int T = 0;
	scanf("%d",&T);
	while(T--){
		//priority_queue<LL> pq;
		vt.clear();
		scanf("%d %d",&n,&k);
		per(i,1,n){
			scanf("%lld %lld",&a[i].x,&a[i].y);
		} 
		per(i,1,n){
			per(j,i+1,n){
				per(k,j+1,n){
					LL sum = abs((a[j].x-a[i].x)*(a[k].y-a[i].y) - (a[k].x-a[i].x)*(a[j].y-a[i].y));
					vt.push_back(sum);
					//pq.push(sum);
				}
			}
		}
		//sort(vt.begin(),vt.end(),cmp);//���Ӷ�̫�� 
		nth_element(vt.begin(),vt.begin()+n*(n-1)*(n-2)/6-k,vt.end());
		/*
		STL�е�nth_element()������ʹ�� ͨ������nth_element(start, start+n, end) 
		��������ʹ��nСԪ�ش��ڵ�nλ�ã���0��ʼ,��λ�����±�Ϊ n��Ԫ�أ���
		���ұ����Ԫ��С��Ԫ�ض��������Ԫ��֮ǰ�������Ԫ�ش��Ԫ�ض��������Ԫ��֮��
		�����ܱ�֤�����������
		*/ 
		LL ans = vt[n*(n-1)*(n-2)/6-k];
		/* 
		LL ans = 0;
		while(k--){//���ȶ��еĸ��Ӷ�ƫ�� 
			ans = pq.top();
			pq.pop();
		}
		*/
		if(ans % 2 == 0){//ע���0��ʼ�����о�������/2��С������Ҫô��.00,Ҫô����.50 
			printf("%lld.00\n",ans/2);
		}else{
			printf("%lld.50\n",ans/2);
		}
	}
	
	return 0;
}

