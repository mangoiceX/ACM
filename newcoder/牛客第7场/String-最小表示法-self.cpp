#include<iostream>
#include<string>
#include<vector>
#include<cstring> 
#include<algorithm>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
using namespace std;
const int maxn = 1e5 + 10;
char str[300];
struct node{
	int l,r;
};
int min_rep(int st,int se){
	int i = st+1,j = st,k = 0;
	while(i < se && j < se){
		k = 0;
		int len = se - st+1;
		while(str[st+(i+k) % len] == str[st+(j+k) % len] && k < len){
			++k;
		}
		if(k == len){
			return i;
		}
		if(str[i+k] > str[j+k]){
			if(i +k +1 > j){
				i = i+k+1;	
			}else{
				i = j+1;
			}
			//i = max(i+k+1 ,j + 1);
		}else{
			if(j+k+1 > i){
				j = j+k+1;	
			}else{
				j = i+1;
			}
			//j = max(j+k+1, i+1);
		}
	}
	return i < j? i :j; 
}
int main(){
	int T = 0;
	//scanf("%d",&T);
	cin >> T;
	while(T--){
		//scanf("%d",&n);
		//scanf("%d",&)
		// cin >> str;
		// cout << min_rep() << endl;
		//cout << Mini() << endl;
		scanf("%s",str);
		vector<node> ans;
		int len = strlen(str);
		int fir = 0,las = 0;
		per(i,0,len){
			if(min_rep(fir,i) == 0){
				las = i;
			}else{
				ans.push_back(node{fir,las});
				fir = las + 1;
			}
		}
		int si = ans.size();
		per(i,0,si-1){
			printf("%d %d\n",ans[i].l,ans[i].r);
			per(j,ans[i].l,ans[i].r){
				printf("%c",str[j]);
			}
			printf(" ");
		}
		puts("");
	}
	
	return 0;
}
