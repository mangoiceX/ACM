#include<bits/stdc++.h>
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 2e5 + 100;
typedef long long LL;
int a[maxn];
int n = 0;
int arr[maxn];
int main(){
	while(~scanf("%d",&n)){
		int fu = 0,lin = 0,zhe = 0;
		int maxfu = 0,minfu = -INF,maxzhe = -INF,minzhe = INF;
		int maxful = 0,minful = 0,maxzhel = 0,minzhel = 0,linl;
		for(int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
			//cout << "po " << a[i] << endl;
			if(a[i] < 0){
				++fu;
				//cout << "pl " << fu << endl;
				if(a[i] < maxfu){
					maxfu = a[i];
					maxful = i;
				}
				if(a[i] > minfu){
					minfu = a[i];
					minful = i;
				}
			}else if(a[i] > 0){
				++zhe;
				if(a[i] > maxzhe){
					maxzhe = a[i];
					maxzhel = i;
				}
				if(a[i] < minfu){
					minzhe = a[i];
					minzhel = i;
				}
			}else{
				lin++;
				arr[lin] = i;
				linl = i;
			}
		}
		//cout << "em " << zhe << " " << fu << endl;
		int cnt = 0;
		if(lin == 1 && fu % 2 == 0){//2
			printf("2 %d\n",linl);
			cnt++;
			for(int i = 1;i <= n;i=i){
				int j = i + 1;
				if(i == linl){
					i++;
					j++;
				}
				if(j == linl){
					j++;
				}
				printf("1 %d %d\n",i,j);
				cnt++;
				if(cnt == n-1){
					break;
				}
				i = j;
			}
		}
		if(lin == 1 && fu % 2 == 1){//1
			printf("2 %d\n",minful);
			cnt++;
			for(int i = 1;i <= n;i=i){
				int j = i + 1;
				if(i == minful){
					i++;
					j++;
				}
				if(j == minful){
					j++;
				}
				printf("1 %d %d\n",i,j);
				cnt++;
				if(cnt == n-1){
					break;
				}
				i = j;
			}
		}
		
		if(lin == 0 && fu % 2 == 0){//6
			int locrm = 0;
			if(zhe == 0){
				locrm = maxful;
			}else{
				locrm = minzhel;	
			}
			printf("2 %d\n",locrm);
			cnt++;
			for(int i = 1;i <= n;i=i){
				int j = i + 1;
				if(i == locrm){
					i++;
					j++;
				}
				if(j ==locrm){
					j++;
				}
				printf("1 %d %d\n",i,j);
				cnt++;
				if(cnt == n-1){
					break;
				}
				i = j;
			}
		}
		if(lin == 0 && fu % 2 == 1){//5
			int locrm = minful;
			//cout << "em "<<endl;
			printf("2 %d\n",locrm);
			cnt++;
			if(cnt == n-1){
				break;
			}
			for(int i = 1;i <= n;i=i){
				int j = i + 1;
				if(i == locrm ){
					i++;
					j++;
				}
				if(j ==locrm ){
					j++;
				}
				printf("1 %d %d\n",i,j);
				cnt++;
				if(cnt == n-1){
					break;
				}
				i = j;
			}
		}
		if(lin > 1 && fu % 2 == 0){//3
			for(int i = 1;i <= lin - 1;++i){
				printf("1 %d %d\n",arr[i],arr[i+1]);
				cnt++;
				if(cnt == n-1){
					break;
				}
			}
			if(cnt == n-1){
				break;
			}
			int locrm = linl;
			printf("2 %d\n",locrm);
			cnt++;
			if(cnt == n-1){
				break;
			}
			for(int i = 1;i <= n;i=i){
				int j = i + 1;
				if(i == locrm|| a[i] == 0){
					i++;
					j++;
				}
				if(j ==locrm || a[j] == 0){
					j++;
				}
				printf("1 %d %d\n",i,j);
				cnt++;
				if(cnt == n-1){
					break;
				}
				i = j;
			}
		}
		
		if(lin > 1 && fu % 2 == 1){//3
			printf("2 %d\n",minful);
			cnt++;
			for(int i = 1;i <= lin - 1;++i){
				printf("1 %d %d\n",arr[i],arr[i+1]);
				cnt++;
				if(cnt == n-1){
					break;
				}
			}
			if(cnt == n-1){
				break;
			}
			int locrm = linl;
			if(cnt != n-1){
				printf("2 %d %d\n",locrm);
				cnt++;	
			}
			
			if(cnt == n-1){
				break;
			}
			for(int i = 1;i <= n;i=i){
				int j = i + 1;
				if(i == locrm|| a[i] == 0){
					i++;
					j++;
				}
				if(j ==locrm || a[j] == 0){
					j++;
				}
				printf("1 %d %d\n",i,j);
				cnt++;
				if(cnt == n-1){
					break;
				}
				i = j;
			}
		}
		
	}
	
	return 0;
} 
