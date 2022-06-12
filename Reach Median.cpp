#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 100;
int a[maxn];
int n = 0,s = 0;
int main(){
	while(scanf("%d %d",&n,&s) != EOF){
		int min_c = 0,max_c = 0,flag = 0;
		for(int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
			if(a[i] == s && flag == 0){
				--max_c;
				flag = 1;
			}
			a[i] >= s ? ++max_c : ++min_c;
		}
		
		sort(a+1,a+n+1);
		LL ans = 0;
		if(max_c > n / 2){
			for(int i = 1;i <= max_c - n/2;++i){
				if(flag == 1){
					ans += a[min_c+1+i] - s;
				}else{
					ans += a[min_c+i] - s;
				}
				
				//cout << "en "<<a[min_c+1+i] << endl;
			}
			printf("%I64d\n",ans);
		}else if(max_c <= n / 2){//测试数据 1 100 88 我输出0，答案是88 
			for(int i = 1;i <= min_c - n/2;++i){
			
				if(flag == 1){
					ans += s - a[n-max_c-i];
				}else{
					ans += s - a[n-max_c+1-i];
				}
			}
			
			printf("%I64d\n",ans);
		}
		//}else{		//去掉然后就AC了，太可惜了，要不然就涨分了 
		//	printf("0\n");
		//}
		
	}
	
	return 0;
} 
