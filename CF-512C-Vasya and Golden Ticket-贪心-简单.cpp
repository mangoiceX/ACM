#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
typedef long long LL;
const double eps=1.0e-5;
const int maxn=100 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n = 0; 
char str[maxn];
void solve(){
	per(i,0,n-2){
		int sum1 = 0;
	 	per(j,0,i){
	 	 	sum1 += str[j] - '0'; 
		}
		int k = i + 1;
		while(k < n){
			int sum2 = str[k++] - '0';//不能用0作为初始值，否则与下面的while循环的判断条件
			//有冲突，会陷入死循环，比如现在k->3,sum1->2,k+1->1,如果初始化为0,k++无法进行就会
			//死循环 
			//int sum2 = 0;
		  	while(k < n && sum2  + str[k] - '0'<= sum1){
		  //while(k < n && sum2 < sum1){//这种判断条件可能会导致sum2>sum1 
		  		sum2 += str[k++] - '0';
			}
			if(sum2 != sum1){
				break;
			}
			if(sum2 == sum1 && k == n ){//将隐含条件最好写上，防止出现 
				printf("YES\n");
				return ;
			}
		}
		
	}
	printf("NO\n");
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%d",&n)){
		scanf("%s",str);
		solve();
	}
	
	return 0; 
}
