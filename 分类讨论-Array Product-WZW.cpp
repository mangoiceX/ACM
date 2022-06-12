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
const int maxn=200000+10;

int cnt1=0,cnt2=0,cnt3=0,n,tmp,a[maxn],b[maxn],c[maxn],ma=-inf,flag;

int main(){
	//freopen("C:\\Users\\MAC\\Desktop\\in.txt","r",stdin);
	scanf("%d",&n);
	per(i,1,n){
		scanf("%d",&tmp);
		if(tmp<0){
			cnt1++;a[cnt1]=i;
			if(tmp>ma){ma=tmp;flag=i;}//记录绝对值最小的负数和他的位置 
		}
		else if(tmp==0) cnt2++,b[cnt2]=i;
		else cnt3++,c[cnt3]=i;
	}
	//抓住不变的量，所有情况正数的处理都可以一样 
	per(i,1,cnt3-1) printf("1 %d %d\n",c[i],c[i+1]);
	if(cnt1){//存在负数 
		if(cnt1%2){//负数是奇数个，要删除绝对值最小的负数 
			per(i,1,cnt1-1){
				if(a[i]==flag) continue;
				if(a[i+1]==flag) a[i+1]=a[i];//把a[i+1]不符合情况的覆盖掉 
				else printf("1 %d %d\n",a[i],a[i+1]);
			}
			per(i,1,cnt2) printf("1 %d %d\n",flag,b[i]),flag=b[i];//0和绝对值最小的负数合并 
			if(cnt3>0||cnt1>1)printf("2 %d\n",cnt2?b[cnt2]:flag);//然后再与0合并
			//这个条件是保证最后的结果是大于0的 
			//有正数的话，就删掉0(0和flag合并后的结果)，否则删掉flag//有正数或者负数大于1的奇数，最后只必大于0 
			if(cnt3 > 0&&cnt1>1) printf("1 %d %d\n",a[cnt1],c[cnt3]);//如果有正数，
			//并且负数大于1，那么就可以两者可以合并 
			//条件是保证最后的正数和负数合并的最后数合并 
		}else{//负数是偶数个 
			per(i,1,cnt2-1) printf("1 %d %d\n",b[i],b[i+1]);//处理0 
			per(i,1,cnt1-1) printf("1 %d %d\n",a[i],a[i+1]);//处理负数 
			if(cnt2) printf("2 %d\n",b[cnt2]);//删除0 
			if(cnt3) printf("1 %d %d\n",a[cnt1],c[cnt3]);//将负数和最终的负数合并 
		}
	}else{//没有负数 
		per(i,1,cnt2-1) printf("1 %d %d\n",b[i],b[i+1]);//处理0 
		if(cnt2&&cnt3) printf("2 %d\n",b[cnt2]);//如果有0，并且有正数，那么删除0 
	}
	return 0;
}
