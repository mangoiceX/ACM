#include<bits/stdc++.h>
using namespace std;
double a[100],b[100];
int main(){
	freopen("a.txt","r",stdin);
	for(int i = 1;i <= 18;++i){
		scanf("%lf %lf",&a[i],&b[i]);
	}
	for(int i = 1;i <= 18;++i){
		printf("h:%.1lf b:%.1lf %c",9.615*a[i],129.03*b[i],(i % 3 == 0)?'\n':' ');
	}
	//cout << a[8] << endl;
	printf("-----------\n");
	for(int i = 21;i <= 28;++i){
		scanf("%lf %lf",&a[i],&b[i]);
	}
	//cout << a[21] << endl;
	for(int i = 21;i <= 28;++i){
		printf("h:%.1lf b:%.1lf %c",9.615*a[i],129.03*b[i],(i % 3 == 0)?'\n':' ');
	}
	
	return 0;
} 
