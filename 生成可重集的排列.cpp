#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100;
void print_permutation(int n,int A[],int P[],int cur){
	if(cur == n){
		for(int i = 0;i < n;i++){
			printf("%d ",A[i]);
		}
		printf("\n");
	}else{
		for(int i = 0;i < n;i++){
			if(!i || P[i] != P[i - 1]){ //对不同数进行递归 ,利用 || 的短路 
				int c1 = 0,c2 = 0;
				
				for(int j = 0;j < cur;++j){ //统计一个数已经在结果数组中出现了几次 
					if(A[j] == P[i])
						c1++;
				}
				
				for(int j = 0;j < n;++j){ //统计一个数在原数组的重复次数 
					if(P[i] == P[j])
						c2++;
				}
				
				if(c1 < c2){
					A[cur] = P[i];
					print_permutation(n,A,P,cur + 1);
				}
			}
			
		}
	}
		
	
}
int main(){
	int P[maxn];
	int A[maxn];
	int n = 0;
	
	freopen("n_permutation.txt","r",stdin); 
	cin >> n;
	
	for(int i = 0;i < n;++i){	//-1初始化，防止影响P，与P有交集 
		A[i] = -1;
	}
	
	for(int i = 0;i < n;i++){
		cin >> P[i];
	}
	sort(P,P + n);
	
	printf("The permutation is as follows:\n");
	
	print_permutation(n,A,P,0);
	
	return 0;
}
