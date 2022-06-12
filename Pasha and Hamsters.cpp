#include<iostream> 
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<queue>
using namespace std;
map<int,bool> mp1,mp2;
const int maxn = 1000 + 10;
int data1[maxn],data2[maxn];
int main(){
	int n = 0,a = 0,b = 0;

	memset(data1,0,sizeof(data1));
	memset(data2,0,sizeof(data2));
	cin >> n >> a >> b;
	for(int i = 1;i <= a;++i){
		cin >> data1[i];
		mp1[data1[i]] = 1;
	}
	for(int i = 1;i <= b;++i){
		cin >> data2[i];
		mp2[data2[i]] = 1;
	}
	
	for(int i = 1;i <= n;++i){
		
		if(i != 1){
			cout << " ";
		}
		if(mp1[i] == 1){
			cout << "1";
			continue;
		}
		if(mp2[i] == 1){
			cout << "2";
			continue;
		}
	}
	cout << endl;
	
	return 0;
}
