//3824运算游戏 
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
bool can  = false;
int color[4];

void judge(int ans,int *A ,int cur){
	int i = 0,j = 0;
	if(can){
		return;
	}
	if(cur == 4){
		if(ans == 24){
			can = true;
			return ;
		}else{
			return ;
		}
	}
	
	if(cur == 2){
		for( i = 0;i < 4;i++){
			if(color[i] == 0){//没有使用的 
				color[i] = 1;
				judge(ans+A[i],A,cur+1); 
				judge(fabs(ans-A[i]),A,cur+1); 
				judge(ans*A[i],A,cur+1); 
				judge(ans/A[i],A,cur+1); 
				judge(A[i]/ans,A,cur+1); 
				color[i] = 0;//
			}
		}
		
		
		for(i = 0;i < 4;i++){	
			for(j = 0;j < 4;j++){
				if(color[i] == 0 && color[j] == 0 && i != j){
					color[j] = 1;color[i] = 1;
					judge(ans/fabs(A[i]-A[j]),A,cur + 2);
					judge(fabs(A[i]-A[j])/ans,A,cur + 2);
					color[j] = 0;color[i] = 0;	//
				}
			}
		}
	
	}
	else{
			for(int i = 0;i < 4;i++){
			if(color[i] == 0){//没有使用的 
				color[i] = 1;
				judge(ans+A[i],A,cur+1); 
				judge(fabs(ans-A[i]),A,cur+1); 
				judge(ans*A[i],A,cur+1); 
				judge(ans/A[i],A,cur+1); 
				judge(A[i]/ans,A,cur+1); 
				color[i] = 0;//
			}
		}
		
	}
	
	
} 
/*
void judge_game(int ans,int *A){
	
	int ans1[4] = { 0,0,0,0};
	for(int i = 0;i < 4;i++){	//
		for(int j = 0;j < 4;j++){
			if(j == i){//
				continue;
			}	
			ans1[0] = A[i]+A[j]; ans1[1] = fabs(A[i]-A[j]);ans1[2] = fabs(A[i]*A[j]);
			ans1[3] = maxn(A[i],A[j])/min(A[i],A[j]);
			for(int k = 0;k < 4;k++){
				if(k == i || k== j){//
					continue;
				}		
				ans1[0] += A[k]; ans1[1] = fabs(ans1[1]-A[j]);ans1[2] = fabs(A[i]*A[j]);
				ans1[3] = maxn(A[i],A[j])/min(A[i],A[j]);
				for(int v = 0;v < 4;v++){//
					if(v == i || v== j || v == k){
					continue;
					}		
					
					
				}
			}
		}
	}
	
}
*/
int main(){
	
	int A[4];
	memset(A,0,sizeof(A));
	memset(color,0,sizeof(color));
	
	for(int i = 0;i < 4;i++){
		cin >> A[i];
	}
	sort(A,A+4);
	judge(1,A,0);
	if(can){
		printf("yes\n");
	}else{
		printf("no\n");
	}
	return 0;
} 

