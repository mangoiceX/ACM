#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 21;
bool color[maxn] ;
int A[maxn],vis[maxn];
void es_prime(int n){
	for(int i = 2;i <= maxn;i++){
		for(int j = i+1;j <= maxn;j++){
			if(A[j] % i == 0){
				color[j] = false;
			}
		}
	}
	
}
bool isprime(int a){
	if(color[a]){
		return true;
	}
	return false;
}
bool is_prime(int a){
	for(int i = 2;i < a;i++){
		if(a % i == 0){
			return 0;
		}
	}
	return 1;
}
void print_prime(int n,int cur){
	if(cur == n && is_prime(A[1]+A[n])){
		for(int i = 1;i <= n;i++){
			printf("%d ",A[i]);
		}
		printf("\n");
		return ;
	}
	/*
	for(int i = 2;i <= n;i++){
		int ok = 1;
		for(int j = 1;j < cur;j++){
			if(i == A[j] || !isprime(A[cur-1]+i)){
				ok = 0;
				break;
			}
		}
		if(ok){
			A[cur] = i;
			print_prime(n,cur+1);
		}
	}*/
	for(int i = 2;i <= n;i++){
		if(!vis[i] && is_prime(A[cur-1]+i)){
			A[cur] = i;
			vis[i] = 1;
			print_prime(n,cur+1);
			vis[i] = 0; //清楚标志，回溯法中改变了辅助的全局变量，要及时把他们恢复原状 
		}
	}
	
}
int main(){
	int n = 0;
	memset(color,true,sizeof(color));//素数标记数组 
	memset(vis,0,sizeof(color));//标记数组 
	for(int i = 1;i <= maxn - 1;i++){
		A[i] = i;
	}
	es_prime(maxn);
	cin >> n;
	print_prime(n,0);
	
	
	return 0;
}

