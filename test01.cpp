#include<bits/stdc++.h>
using namespace std;

void init(char* a){
	int cnt = 0;
	for(int i = 0;i < strlen(a);++i){
		++cnt;
		a[i] = '\0';
	}
	printf("%d\n",cnt);
}
void solve(){
	char lv[3];
	lv[0] = '1',lv[1] = '2',lv[2] = '3';
	// printf("%d\n",strlen(lv));
	printf("%c %c %c\n",lv[0],lv[1],lv[2]);
	init(lv);
	printf("%c %c %c\n",lv[0],lv[1],lv[2]);

	lv[0] = '1',lv[1] = '2',lv[2] = '3';
	printf("%c %c %c\n",lv[0],lv[1],lv[2]);
	memset(lv,'\0',sizeof(lv));
	printf("%c %c %c\n",lv[0],lv[1],lv[2]);

	
}
int main(){
	solve();

	return 0;
}