#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;
typedef long long LL;

int main(){
	int a[20];
	int n = 0 ;
	int T = 0;
	freopen("Maximum.txt","r",stdin);
	while( scanf("%d",&n) != EOF){
		LL ans = 0;
		for(int i = 0;i < n;++i){
			cin >> a[i];
		}
		
		for(int i = 0;i < n ;++i){
			for(int j = i;j < n;++j){
				LL tt = 1;
				for(int k = i;k <= j;++k){
					tt *= a[k];	
				}
				ans = max(ans,tt);
			}
		}	
		printf("Case #%d: The maximum product is %lld.\n\n", ++T, ans);
	}		
	
	
	
	
	
	return 0;
} 
