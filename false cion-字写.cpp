#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int pl[505],pr[505];
int a[1010],b[1010];
int N = 0,K = 0,num = 0;

int main(){
	//int T = 0;
	int p = 0;
	//cin >> T;
	//scanf("%d",&T);
//	getchar();
	//while(T-- ){
		num = 0;
		//cin >> N >> K;
		scanf("%d %d",&N,&K);
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
			char ch;
			getchar();
			//cin >> ch;
			scanf("%c",&ch);
			getchar();
			if(ch == '='){
				for(int i = 0;i < p;++i){
					a[pl[i] ] = b[pl[i] ] = -1;
					a[pr[i] ] = b[pr[i] ] = -1;
				}
			}else if(ch == '<'){
				++num;
				for(int i = 0;i < p;++i){
					if(a[pl[i]] != -1){
						a[pl[i]]++;
					}
					if(a[pr[i]] != -1){
						b[pr[i]]++;
					}
				}
			}else if(ch == '>'){
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
		if(cnt != 1){
			//cout << "0"<< endl;
			printf("0\n");
		}else{
			//cout << ans << endl;
			printf("%d\n",ans);
		}
		//if(T){
			//cout << "\n";
		//	printf("\n");
	//	}
	//}
	
	
	return 0;
}
