#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
const int maxn = 10000 + 10;
using namespace std;
int data[maxn];

int main(){
	int T = 0;
	int n = 0 ,q = 0,temp = 0;
	int *it;
	while(cin >> n >> q && n && q){
		
		memset(data,-1,sizeof(data));
		for(int i = 1;i <= n;++i){
			cin >> data[i];
		}
		sort(data + 1,data + n + 1);
		cout << "CASE# " << T + 1 << ":" << "\n";
		T++;
		for(int i = 0;i < q;++i){
			cin >> temp;
			it = lower_bound(data + 1,data + n + 1,temp);
			int loc = it - data;
			
			if(data[loc] == temp){
				cout << temp << " found at " << loc   << endl; 
			}else{
				cout << temp << " not found" << endl;
			}
		}
		
	}
	
	
	return 0;
} 
