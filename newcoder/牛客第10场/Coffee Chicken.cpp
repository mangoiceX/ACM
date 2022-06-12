#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 5e2 + 10;
int n = 0,m = 0;
LL k = 0;
string s1 = "COFFEE",s2 = "CHICKEN";
string s3;
string str1 = "COFFEE",str2 = "CHICKEN";
int pos = 0,loc = 0;
LL f[maxn];
LL gi(){
    char a=getchar();LL b=0;
    while(a<'0'||a>'9')a=getchar();
    while(a>='0'&&a<='9')b=b*10+a-'0',a=getchar();
    return b;
}
int gi2(){
    char a=getchar();int b=0;
    while(a<'0'||a>'9')a=getchar();
    while(a>='0'&&a<='9')b=b*10+a-'0',a=getchar();
    return b;
}
void pre_solve(){

	memset(f,0,sizeof(f));
	f[1] = 6; f[2] = 7;
	pos = 0,loc = 0;
	per(i,3,500){
		f[i] = f[i-1] + f[i-2];
		if(f[i] > 1e12){
			pos = i;
			break;
		}
	}
}
void solve(){
	s1 = "COFFEE";s2 = "CHICKEN";
	int i = n;
	LL tmp = f[n];
	while(f[i] > 1e6 && k > 0){
		if(f[i-2] < k){
			k -= f[i-2];
			tmp -= f[i-2];
			i = i - 1;
		}else{
			i = i-2;
		}
	}
	if(k > f[i]){//这个要加上，否则会输出空，判定为超时
		++i;
	}
	per(j,3,i){
		s3 = s1 + s2;
		s1 = s2; s2 = s3;
	}
	bool fg = true;
	for(int j = k;j < k+10 && j <= tmp;++j){
		printf("%c",s3[j-1]);
		fg = false;
	}
	puts("");
}
int main(){
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	pre_solve();
	int T = 0;
	scanf("%d",&T);
	while(T--){
		// scanf("%d %lld",&n,&k);
		n = gi2(); k = gi();
		if(n == 1){
			per(i,k-1,6-1){
				printf("%c",str1[i]);
			}
			puts("");
			continue;
		}else if(n == 2){
			per(i,k-1,7-1){
				printf("%c",str2[i]);
			}
			puts("");
			continue;
		}
		if(f[n] == 0){
			n = pos;
		}
		solve();
	}

	return 0;
}
