#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(){
	int a[11][11]={0},i,j,m,n,c;
	int t1,t2,t3,x1,x2,x3;
	srand(time(NULL));
	for(i=0;i<10;i++){
		do{
		m=rand()%9+1;
		n=rand()%9+1;}
		while(a[m][n]==9);
			a[m][n]=9;
	}
/*	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			printf("%10d",a[i][j]); 
		
		}
		
	}*/
	for(i=1;i<10;i++){
		for(j=1;j<10;j++){
			c=0;
			t1=i-1,t2=i,t3=i+1,x1=j-1,x2=j,x3=j+1;
			if(a[t1][x1]==9)
				c++;
			if(a[t1][x2]==9)
				c++;	
			if(a[t1][x3]==9)
				c++;	
			if(a[t2][x1]==9)
				c++;	
			if(a[t2][x3]==9)
				c++;		
			if(a[t3][x1]==9)
				c++;	
			if(a[t3][x2]==9)
				c++;	
			if(a[t3][x3]==9)
				c++;		
				a[i][j]=c;
		}	
	}
	for(i=1;i<10;i++){
		for(j=1;j<10;j++){
			printf("%8d",a[i][j]); 
		}
	}
	return 0;
}
