#include<set>
#include<map>
#include<ctime>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<climits>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
int read(){
    int f=1,x=0;char s=getchar();   
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}  
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    return x*f;
}
#define MAXN 2000
#define INF 0x3f3f3f3f
#define Mod int(1e9+7)
int n,m;
LL x,s1[MAXN+5][MAXN+5],s2[MAXN+5][MAXN+5];
LL a[MAXN+5],b[MAXN+5],f1[MAXN+5],f2[MAXN+5];
int main(){
	n=read(),m=read();
	for(LL i=1;i<=n;i++)
		a[i]=read();
	for(LL i=1;i<=m;i++)
		b[i]=read();
	x=read();
	memset(f1,0x3f,sizeof(f1));
	memset(f2,0x3f,sizeof(f2));
	for(int l=1;l<=n;l++)
		for(int i=l;i<=n;i++)
			s1[l][i]=s1[l-1][i-1]+a[i];
	for(int l=1;l<=m;l++)
		for(int i=l;i<=m;i++)
			s2[l][i]=s2[l-1][i-1]+b[i];
	for(int l=1;l<=n;l++)
		for(int i=l;i<=n;i++)
			f1[l]=min(f1[l],s1[l][i]);
	for(int l=1;l<=m;l++)
		for(int i=l;i<=m;i++)
			f2[l]=min(f2[l],s2[l][i]);
	LL ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(f1[i]*f2[j]<=x)
				ans=max(ans,1ll*i*j);
	printf("%lld\n",ans);
}
 
