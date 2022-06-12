#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
using namespace std;
const int maxn = 1e5 + 10;
int n = 0,k = 0,p = 0,x = 0,y = 0;
int d[1010];
int main(){	
	while(scanf("%d %d %d %d %d",&n,&k,&p,&x,&y) != EOF){
		int cnt1 = 0,cnt2 = 0;
		int sum = 0;
		for(int i = 0;i < k;++i){
			int a = 0;
			scanf("%d",&a);
			sum += a;
			if(a >= y){
				++cnt1;
			}else{
				++cnt2;
			}
		}
		if(sum > x || cnt2 > n/2){
			printf("-1\n");
			continue;
		}
		int cnt3 = 0,size = 0;
		int r = n/2 - (cnt1 - 1);
		//while(sum < x && cnt3 + k < n){
		while(r--){
			sum += y;
			d[++size] = y;
			++cnt3;
			//if(sum > x || cnt3 + k > n){
			//	flag = 1;
			///	printf("-1\n");
		//		break;
		//	}
		}
		//if(flag == 1){
		//	continue;
		//}
		//int l = n/2 - (cnt2);
		int l = n - cnt1 - cnt2 - size;
		while(l--){
			sum += 1;
			d[++size] = 1;
			++cnt3;
		}
		if(sum > x ){
			printf("-1\n");
		}else{
			for(int i = 1;i <= size;++i){
				printf("%d ",d[i]);
			}
			printf("\n");
		}
	
	}
	
	return 0;
} 
