#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 250 + 10;
int val[6] = {0,1,5,10,25,50};
struct node{
	int val;
	int num;
};
node temp[maxn],sup[maxn];
int n = 0;
void solve(){
	for(int i = 0;i <= 5;++i){
		temp[i].val = 0;temp[i].num = 0;
		sup[i*50].val = 1;sup[i*50].num = i;
	}
	for(int i = 6;i <= 250;++i){
		temp[i].val = 0;temp[i].num = 0;
		if(i % 50 == 0){
			continue;
		}
		sup[i].val = 0;sup[i].num = 0;
	}
	//cout << sup[0].val << endl;
	for(int i = 4;i >= 1;--i){
		for(int j = 0;j <= maxn-10;++j){
			for(int k = 0;k*val[i] + j <= maxn-10;++k){
				//if( i == 1){
				//	cout << "ai " << sup[100].num <<endl;
			//	}
				if(k + sup[j].num > 100){
					//continue;
					cout<< "nima " << k <<" " << j << " " << sup[j].num << "ha " << 
					j + val[i]*k << " " << i << endl;
					break;
				}
				temp[j+k*val[i]].val += sup[j].val;
				temp[j+k*val[i]].num = max(sup[j].num + k,temp[j+k*val[i]].num);
				//if(k == 5 && j == 0 && i == 2){
				//	cout << "jj " << temp[25].num << endl;
				//}
			//	if(k == 100 && i == 2){
				//	cout << "ai " << temp[5].num <<endl;
				//}
			}
		}
		for(int j = 0;j <= maxn-10;++j){
			//if(temp[j].num  > 100){
			////	temp[j].val = 0;temp[j].num = 0;
			//	continue;
			//	//break;
			//}
			sup[j].val = temp[j].val;//sup[j].num = min(temp[j].num,sup[j].num);
			sup[j].num = temp[j].num;
			temp[j].val = 0;temp[j].num = 0;
		}
	}
	//cout << sup[1].val  << " " << sup[0].num<< endl;
}
int main(){
	solve();
	while(~scanf("%d",&n)){
		printf("%d\n",sup[n].val);	
	}
	
	return 0;
}
