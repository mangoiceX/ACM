#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string> 
#include<cstring>
#include<set>
#define INF 0x6ffffff
using namespace std;
typedef unsigned long long LL;
const LL maxn = 1e9;
struct Song{
	LL a,b;
	LL cha;
};
Song song[100010];
LL n = 0,m = 0;

bool cmp(Song a,Song b){
	return a.cha > b.cha;
}
int main(){
	LL sum1 = 0,sum2 = 0;
	scanf("%lld %lld",&n,&m);
	for(LL i = 0;i < n;++i){
		scanf("%lld %lld",&song[i].a,&song[i].b);
		song[i].cha = song[i].a - song[i].b;
		sum1 += song[i].a;
		sum2 += song[i].b;
	}
	if(sum2 > m ){
		printf("-1\n");
	}else{
		sort(song,song + n,cmp);
		int ans = 0,k = 0;
		while(sum1 > m){
			sum1 -= song[k].cha;
			k++;
		}
		ans += k ;
		printf("%d\n",ans);
	}
	
	
	
	return 0;
}


