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
#define inf 0x3f3f3f3f
typedef long long ll;
const double eps=1.0e-5;
const int maxn=2e5 + 10;

int cnt1=0,cnt2=0,cnt3=0,n,a[maxn],b[maxn],c[maxn],ma=-inf,flag;

int main(){//代码注释见另外一个程序 
	//freopen("in.txt","r",stdin);
	while(~scanf("%d",&n)){
		cnt1=0,cnt2=0,cnt3=0;
		flag = 0;ma = -inf;
		per(i,1,n){//输入+预处理 
			int tmp = 0;
			scanf("%d",&tmp);
			if(tmp < 0){
				a[++cnt1] = i;
				if(tmp > ma){
					ma = tmp;
					flag = i;
				}
			}else if(tmp == 0){
				b[++cnt2] = i;
			}else{
				c[++cnt3] = i;
			}
		} 
		
		per(i,1,cnt3 - 1){//
			printf("1 %d %d\n",c[i],c[i+1]);
		}
		if(cnt1 > 0){//
			if(cnt1 % 2 == 1){
				
				per(i,1,cnt1-1){//
					if(a[i] == flag){
						continue;
					}
					if(a[i+1] == flag){//
						a[i+1] = a[i];
					}else{// 
						printf("1 %d %d\n",a[i],a[i+1]);
					}
				}
				
				per(i,1,cnt2){//
					printf("1 %d %d\n",flag,b[i]);
					flag = b[i];
				}
				
				if(cnt3 > 0 || cnt1 > 1){//
					printf("2 %d\n",cnt2 == 0 ?flag : b[cnt2]);
				}
				
				if(cnt3 > 0 && cnt1 > 1){//
					printf("1 %d %d\n",c[cnt3],a[cnt1]);
				}
			}else{
				per(i,1,cnt1-1){//
					printf("1 %d %d\n",a[i],a[i+1]);
				}
				per(i,1,cnt2-1){//
					printf("1 %d %d\n",b[i],b[i+1]); 
				}
				if(cnt2 > 0){
					printf("2 %d\n",b[cnt2]);
				}
				if(cnt3 > 0){
					printf("1 %d %d\n",a[cnt1],c[cnt3]);
				}
			}
		}else{
			per(i,1,cnt2-1){
				printf("1 %d %d\n",b[i],b[i+1]); 
			}
			if(cnt3 > 0 && cnt2 > 0){//必须要有正数，否则这将是第n次操作 
				printf("2 %d\n",b[cnt2]);
			}
		}
	}
	
	return 0; 
}
