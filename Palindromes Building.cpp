#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int maxn = 30;

char str[maxn];
int ans = 1, n = 0;
int times[maxn];
int fac(int x){
	int fa = 1;
	for(int i = 1;i <= x;++i){
		fa *= i;
	}
	return fa;
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		getchar();
		memset(times,0,sizeof(times));
		int odd = 0,flag = 1;
		for(int i = 0;i < n;++i){
			scanf("%c",&str[i]);
			++times[str[i] - 'a'];
		}
		//sort(str,str + n);
		for(int i = 0;i < 26;++i){
			if(times[i] % 2 == 1 ){
				++odd;
				//weizhi = i;
			}
			if(odd > 1){
				ans = 0;
				flag = 0;
				break;
			}
		}
		
		if(flag == 0){
			printf("%d\n",ans);
		}else{
			ans = 1;
			for(int i = 0;i < 26;++i){
				if(times[i] > 1){
					ans *= fac(times[i]/2);
				}
			}
			ans = fac(n/2) / ans;
			printf("%d\n",ans);
		}
		
	}
	return 0;
}

