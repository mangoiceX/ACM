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
int n = 0,m = 0; 
int a[maxn+10][maxn+10];//a[i][j]��ʾǰi�У���j�е�����Ԫ�غ� 
/*
�������ö�ٵĻ������Ӷ�O(n4),���ʹ��ǰ׺�ͣ����Խ�һά������O(n3); 
*/
int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%d",&n)){
		memset(a,0,sizeof(a));
		per(i,1,n){
			per(j,1,n){
				int t = 0;
				scanf("%d",&t);
				a[i][j] = a[i-1][j] + t;
			}
		}
		int maxv = a[1][1];
		per(i,1,n){
			per(j,i,n){
				int sum = 0;
				per(k,1,n){
					sum += (a[j][k] - a[i-1][k]);
					if(sum < 0){//��ʱ��������������м�ĺͻ����ͻ�ö�ٵ��� 
						sum = 0;
					}
					if(sum > maxv){
						maxv = sum;
					}
				}
			}
		}
		printf("%d\n",maxv);
	}
	
	return 0;
}

