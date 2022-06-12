#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int pl[6],pr[6];
int a[20],b[20];
int N = 0,K = 0,num = 0;
char swift(int i){
	switch(i){
		case 0:
			return 'A';
		case 1:
			return 'B';
		case 2:
			return 'C';
		case 3:
			return 'D';
		case 4:
			return 'E';
		case 5:
			return 'F';
		case 6:
			return 'G';
		case 7:
			return 'H';
		case 8:
			return 'J';
		case 9:
			return 'K';
		case 10:
			return 'L';
	}
}
int main(){
	int T = 0;
	int p = 0;
	//cin >> T;
	scanf("%d",&T);
	getchar();
	while(T-- ){
		num = 0;
		//cin >> N >> K;
		//scanf("%d %d",&N,&K);
		int K = 3;
		getchar();
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		while(K--){
			//cin >> p;
			scanf("%d",&p);
			getchar();
			for(int i = 0; i < p;++i){
				//cin >> pl[i];
				scanf("%d",&pl[i]);
			}
			for(int i = 0; i < p;++i){
				//cin >> pr[i];
				scanf("%d",&pr[i]);
			}
			char ch[10];
			getchar();
			//cin >> ch;
			scanf("%s",&ch);
			getchar();
			if(ch == 'even'){
				for(int i = 0;i < p;++i){
					a[pl[i] ] = b[pl[i] ] = -1;
					a[pr[i] ] = b[pr[i] ] = -1;
				}
			}else if(ch == 'down'){
				++num;
				for(int i = 0;i < p;++i){
					if(a[pl[i]] != -1){
						a[pl[i]]++;
					}
					if(a[pr[i]] != -1){
						b[pr[i]]++;
					}
				}
			}else if(ch == 'up'){
				++num;
				for(int i = 0;i < p;++i){
					if(a[pl[i] ] != -1){
						b[pl[i]]++;
					}
					if(a[pr[i]] != -1){
						a[pr[i]]++;
					}
				}
			}
			
		}
		int ans = 0,cnt = 0;
		for(int i = 1;i <= N;++i){
			if(a[i] == num || b[i] == num){
				ans = i;
				++cnt;
			}
			if(cnt == 2){
				break;
			}
		}
	
	
			//cout << ans << endl;
			printf("%c\n",ge(ans));
		//if(T){
			//cout << "\n";
		//	printf("\n");
	//	}
	//}
}
	
	return 0;
}
