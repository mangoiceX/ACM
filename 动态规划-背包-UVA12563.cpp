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
const int maxn = 50,ma = 180*50;
int n = 0,t = 0; 
int max_time = 0;
int a[maxn+10];
struct node{
	int num,time;
	bool operator < (const node &it)const{
		return num < it.num || (num == it.num && time < it.time);
	}
};
node dp[maxn+10][ma+10];
void solve(){
	memset(dp,0,sizeof(dp));
	per(i,1,n){
		rep(j,max_time,0){//֮ǰ����û�е�0,��ֻ�ǵ�a[i]�����³���
		//����a[1]=20,a[2]=50,��һ��ѭ��֪��20���ڶ���ֻѭ����50����ʵ�ڶ��ε�20-50֮���jҲ����ѭ��
		//��Ϊ��Щ��ȻС��50,���ǻ��ǿ�����֮ǰ��״̬ת�����������ﻹ��Ҫ��¼����һζ��ʱ��Ͳ��ü�¼��
		//��Ϊ20-30�Ǳ��������ˣ��޺�Ч�� 
			if(j < a[i]){
				dp[i][j] = dp[i-1][j];
				continue;
			}
			node tmp;
			tmp.num  = dp[i-1][j-a[i]].num + 1;
			tmp.time = dp[i-1][j-a[i]].time + a[i];
			dp[i][j] = (dp[i-1][j] < tmp ? tmp : dp[i-1][j]);
		}
	}

}
int main(){
	//std::ios::sync_with_stdio(false);
	int T = 0,kase = 0;
	scanf("%d",&T);
	while(T--){
		int sum = 0;
		scanf("%d %d",&n,&t);
		per(i,1,n){
			scanf("%d",&a[i]);
			sum += a[i];
		}
		max_time = min(t-1,sum);
		solve();
		printf("Case %d: %d %d\n",++kase,dp[n][max_time].num+1,dp[n][max_time].time + 678);
	}
	
	return 0;
}

