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
const int maxn =  5e2;
int n = 0,m = 0,k = 0; 
vector<int> vt[maxn+10];
char s[maxn+10];
int num[maxn+10][maxn+10];//num[i][j]��ʾ��i������j���κ����ѧУ�����ʱ�� 
int dp[maxn+10][maxn+10];//dp[i][j]��ʾǰi��������j���κ����ѧУ�����ʱ�� 
int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%d %d %d",&n,&m,&k)){
		per(i,1,n){
			vt[i].clear();
		}
		memset(dp,0,sizeof(dp));
		per(i,1,n){
			scanf("%s",s+1); 
			per(j,1,m){
				if(s[j] == '1'){
					vt[i].push_back(j);
				}
			}
		}
		per(i,1,n){
			int size = vt[i].size();
			if(size == 0){
				continue;
			}
			num[i][size] = 0;//������i���ȫ���γ� 
			per(len,1,size){//�ȼ����i����len��������Ҫ�����ʱ�� 
			//per(len,1,size){
				int minv = vt[i][len-1] - vt[i][0] + 1;
				for(int j = 0;j + len - 1 <= size-1;++j){
					minv = min(minv,vt[i][j+len-1] - vt[i][j] + 1);
				}
				num[i][size-len] = minv;//����size-len������������ʱ�䣬������len������������ʱ�� 
			}
		}
		per(i,0,k){
			dp[1][i] = num[1][i];//��ʼ����һ�� 
		}
		per(i,2,n){
			per(j,0,k){
				int minv = dp[i-1][j] + num[i][0];
				per(p,1,j){//��i������p���� 
					minv = min(minv,dp[i-1][j-p] + num[i][p]);
				}
				dp[i][j]  = minv;//ǰi������j���� 
			}
		}
		printf("%d\n",dp[n][k]);
	}
	
	
	return 0;
}

