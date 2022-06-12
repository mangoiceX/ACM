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
char str[maxn+10];
struct node{
	int x,y;
};
node gg[maxn+10];
void solve(){//考虑问题不全面 
	int size = 0;
	per(i,0,n-1){
		if(str[i] == 'G'){
			gg[++size].x = i+1;
			while(i < n && str[i] == 'G'){//小心i越界 
				i++;
			}
			gg[size].y = i;
		}	
	}
	int maxv = 0;
	if(size == 0){
		printf("0\n");
		return ;
	}else if(size == 1){
		printf("%d\n",gg[1].y - gg[1].x + 1);
		return ;
	}else if(size == 2){
		if(gg[2].x - gg[1].y == 2){
			printf("%d\n",gg[2].y - gg[1].x);
			return ;
		}else{//GGSSGG这种情况是3，之前cha的答案是2，要考虑擦拆东墙补西墙 
		//后面还要加1 
			printf("%d\n",max(gg[1].y - gg[1].x + 1 + 1, gg[2].y - gg[2].x + 1 + 1));
			return ;
		}
	}

	per(i,1,size-1){
		if(gg[i+1].x - gg[i].y == 2){
			maxv = max(maxv , gg[i+1].y - gg[i].x + 1);
		}
	}
	int maxv2 = 0;
	per(i,1,size){//GGSSGG这种情况是3，之前cha的答案是2，要考虑擦拆东墙补西墙 
		maxv2 = max(maxv2,gg[i].y - gg[i].x + 1 + 1);
	}
	printf("%d\n",max(maxv,maxv2));
}
int main(){
	while(~scanf("%d",&n)){
		scanf("%s",str);
		solve();
	}
	
	return 0;
}

