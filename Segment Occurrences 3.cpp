#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int maxn = 1000 + 10;

string str1,str2;

int m = 0,n = 0,q = 0,l = 0,r = 0;
int ans[maxn];
bool judge(int loc){
	
	for(int i = loc;i < loc + m && i < n;++i){
		if(str1[i] != str2[i - loc]){
			return false;
		}
	}
	
	return true;
}

int main(){
	//scanf("%d %d %d",&n,&m,&q);
	//scanf("%s",str1);
	//getchar();
	//scanf("%s",str2);
	//getchar();
	cout<<n<<m<<q<<endl;
	cin >> n >> m >> q;
	cin >> str1;
	cin >> str2;
	memset(ans,0,sizeof(ans));
	
	for(int i = 0;i < n;++i){
		if(str1[i] == str2[0]){
			if(judge(i)){
				ans[i] = 1;
			}
		}
	}
	
	int na = 0;
	for(int i = 0;i < n;++i){
		cout << ans[i] << " ";
		//printf("%d ",ans[i]);
	}
	//printf("\n");
	cout << endl;
	for(int i = 0;i < q;++i){
		//scanf("%d %d",&l,&r);
		cin >> l >> r;
		 na = 0;
		 cout << " jojf" << endl;
		for(int j = l - 1;j < l + m - 2 && j < r - m + 1;++j){
			if(ans[j] == 1){
				++na;	
			}	
		}
		//printf("%d\n",na);
		cout<< na << endl;
	}
	
	
	return 0;
}
