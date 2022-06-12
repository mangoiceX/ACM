#include<iostream> 
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<queue>
using namespace std;

const int maxn = 100 + 10;
int data[maxn][maxn];
int r = 0,c = 0,ans = 0;
bool solve(){
	int k = 0,flag = 1;
	
 	if(r % 2 != 0){
 		ans = r;
 		return false;
	 }
	 /*
	 for(int i = 2;i <= r;++i){	//检查k=1的情况 
	 	for(int j = 1;j <= c;++j){
	 		if(data[i][j] != data[1][j]){
	 			flag = 0;
	 			break;
			 }
		 }
		 
		 if(flag == 0){
		 	break;
		 }
	 }
	 if(flag == 1){
	 	ans = 1;
	 	return true;
	 }
	 */
 	
 	for(k = 2;k <= r - 2;k += 2){
 		int cnt = 1;
 		flag = 1;
 		if(r % k != 0 || (r / k) % 2 != 0){
 			continue;
		 }
		if(cnt % 2 != 0){
			
		
	 		for(int i = 1,p = k + 1 - i + k;i <= k;++i,--p){ //被比较的那一层 
	 				
				for(int j = 1;j <= c;++j){
		 			
		 			if(data[i][j] != data[p][j]){
		 				flag = 0;
		 				break;	
					 }
				 }	
				 if(flag == 0){
				 	break;
				 }		 
			}
		 	if(flag == 1){
		 		ans = k;
		 		return true;
			}
			cnt++;
	}else{
		for(int i = 1,p = i + k*cnt;i <= k;++i,++p){ //被比较的那一层 
	 				
				for(int j = 1;j <= c;++j){
		 			
		 			if(data[i][j] != data[p][j]){
		 				flag = 0;
		 				break;	
					 }
				 }	
				 if(flag == 0){
				 	break;
				 }		 
			}
		 	if(flag == 1){
		 		ans = k;
		 		return true;
			}
			cnt++;
	}
}

 	return false;
 	
}
int main(){
	cin >> r >> c;
	for(int i = 1;i <= r;++i){
		for(int j = 1;j <= c;++j){
			cin >> data[i][j];
		}
	} 
	
	if(solve()){
		cout << ans << endl;
	}else{
		cout << r << endl;
	}
	
	
	
	return 0;
}
