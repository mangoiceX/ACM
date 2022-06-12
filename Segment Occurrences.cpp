#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1000 + 10;

char str1[maxn],str2[maxn];

int m = 0,n = 0,q = 0,l = 0,r = 0;
int ans[maxn];
bool judge(int loc){
	
	for(int i = loc;i < loc + m && i < n;++i){
		if(str1[i] != str2[i - loc]){
			return false;
		}
	}
	
	return true;
}
bool solve(){
	if(m == 1){
		return true;
	}
	for(int i = 0;i < m - 1;++i){
		if(str2[i] != str2[i+1]){
			return false;
		}
	}
	return true;
	
	
}
int main(){
	scanf("%d %d %d",&n,&m,&q);
	scanf("%s",str1);
	getchar();
	scanf("%s",str2);
	
		//int ans = 0;
		//for(int j = l - 1;j <= r - 1;++j){
		//	if(str1[j] == str2[0]){
		//		if(judge(j)){
		//			++ans;
		//		}
		//	}
	//}
	cout << "nima" << endl;
	memset(ans,0,sizeof(ans));
	int ma = 0,len = 0;
	if(solve()){
		len = strlen(str1);
	}
	for(int j = 0;j < n;++j){
		if(str1[j] == str2[0]){
			if(judge(j)){
				//ans[j+m ] = ans[j+m-1] + 1;
				ans[j+m] = ma + 1;
			}//else{
			//	ans[j+m] = ans[j+m-1];
			//}
		}else{
			if(j + m > n){
				for(int k = j + 1;k <= n;++k){
					ans[k] = ma;
				}
			}
			ans[j+m] = ma;
		}
		ma = max(ans[j+m],ma);
		
	}
	//for(int i = 0;i <=n;++i){
	//	cout << ans[i] << " ";
	//}
	//cout << endl;
	for(int i = 0;i < q;++i){
		scanf("%d %d",&l,&r);
		if(solve()){
			printf("%d\n",ans[r] - ans[l-1]);	
		}else{
			printf("%d\n",ans[r] - ans[l]);
		}
		
	}


	
	
	return 0;
}
