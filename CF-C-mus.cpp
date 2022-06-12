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
const int maxn = 1e5;
int n = 0,m = 0;
vector<int> vt[maxn+10],vt1[maxn+10], pre_sum[maxn+10];
map<int,int> mp;
struct node{	
	int id,times;
};
bool cmp(int a,int b){
	return a > b;
}
bool cmp2(node a,node b){
	return a.times > b.times;
}
node sub[maxn+10];
void solve(){
	per(i,1,mp.size()){
		int sum = 0;
		pre_sum[i].push_back(0);
		per(j,0,vt1[i].size()-1){
			sum += vt1[i][j];
			pre_sum[i].push_back(sum);
		}
	}
	
	int maxv = 0;
	per(i,1,vt1[1].size()){
		int sum = 0;
		per(j,1,mp.size()){
			if(vt1[j].size() < i){
				break;
			}
			int su1 = pre_sum[j][i] - pre_sum[j][0];//如果前缀和是负数，则不要 
			if(su1 <= 0){//这里WA了好久 
				continue;
			}
			sum += su1;	
		}
		maxv = max(maxv,sum);
	}
	if(maxv <= 0){
		printf("0\n");
		return ;
	}
	printf("%d\n",maxv);
}

int main(){ 		//自己题目意思没读清楚，1是他的sub是随机的数<=m，并不是1-m都有
					//2是小于0的和可以不要，并不要求所有个数，而是最优 
	while(~scanf("%d %d",&n,&m)){
		mp.clear();
		per(i,1,m){
			sub[i].times = 0;
			sub[i].id = i;
			vt[i].clear();
			pre_sum[i].clear();
		}
		per(i,1,n){
			int s = 0,r = 0;
			scanf("%d %d",&s,&r);
			sub[s].times++;
			mp[s]++;
			//sub[s].id = s;
			vt[s].push_back(r);
		}
		per(i,1,m){
			if(vt[i].size() == 0){
				continue;
			}
			sort(vt[i].begin(),vt[i].end(),cmp);
		}

		int cnt = 0;
		sort(sub+1,sub+1+m,cmp2);
		per(i,1,mp.size()){
			vt1[i] = vt[sub[i].id]; 
		}
		
		solve();
	}
	
	return 0;
}

