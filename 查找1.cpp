#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long int ans[100000 + 3];
bool compare(int a,int b ){
	return a < b;
} 

int main(){
	long long int m = 0;
	int n = 0;
	long long int *pos;
	int idx;
	
	while(cin >> n >> m && (m || n)){
		for(int i = 0 ;i < n;i++){
			cin >> ans[i];
		}
		sort(ans,ans + n,compare);
		/*if(m > ans[n - 1]){
			cout << "1" << endl;
			continue;
		}*/
		pos = upper_bound(ans, ans + n,m);
		idx = distance(ans,pos);
		//idx = pos - ans;
		cout << n - idx + 1 << endl;

	}
	
	return 0;
		
}
