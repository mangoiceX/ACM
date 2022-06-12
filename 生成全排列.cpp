#include<iostream>
#include<cstdio>
using namespace std;
int ans = 0;
void print_permutation(int n ,int A[],int cur){
	if(cur == n){
		int cnt = 0;
		for(int i = 0;i < n;i++){
			printf("%d ",A[i]);
		}
		printf("\n");
		for(int i = 1;i < n;++i){
			for(int j = 0;j < i;++j){
				if(A[i] < A[j]){
					++cnt;
					++ans;
				}
			}
		}
		printf("%d\n",cnt);
	}
	
	else{
		for(int i = 1;i <= n;++i){
			int ok = 1;
			for(int j = 0;j < cur;++j){
				if(A[j] == i){
					ok = 0;
				}
			}	
			if(ok){
				A[cur] = i;
				print_permutation(n,A,cur + 1);
			}
		}
	}
}
int main(){
	int n = 0;
	int A[100];
	cin >> n;
	for(int i = 0;i < n;++i){
		A[i] = i + 1;
	}
	//int cur = 1;
	print_permutation(n,A,0);
	printf("%d\n",ans);
	
	
	return 0;
} 
