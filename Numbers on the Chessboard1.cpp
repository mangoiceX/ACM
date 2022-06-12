#include<bits/stdc++.h>
using namespace std;

int main(){
	int n = 0,q = 0;
	while(cin >> n >> q){
		int me = 0,mo = 0;
		int start = 0;
		if(n % 2 == 0){
			 me = n/2,mo = n/2;
			 start = n*n / 2 + 1;
		}else{
			me = (n+1)/2,mo = (n-1)/2;
			start = (n*n + 1)/2+1;
		}
		int x = 0,y = 0;
		for(int i = 0;i < q;++i){
			cin >> x >> y;
			if(n % 2 == 0){
				if((x + y) % 2 == 0){
					cout << 1 + (x-1)*me + (y-1)/2 <<endl;
				}else{
					cout << start + (x - 1)*mo + (y - 1)/2 << endl;
				}
			}else{
				if((x + y) % 2 == 0){
					int sum = (x - 1)/2 * n + x%2 == 0? me : 0;
					//cout << "en " << sum << endl;
					cout << 1 + sum + (y-1)/2 <<endl;
				}else{
					int sum = (x - 1)/2 * n + x%2 == 0? mo : 0;
					//cout << "en " << sum << endl;
					cout << start + sum + (y-1)/2 <<endl;
				}	
			}
			
		}
		
	
	}
	
	
	return 0;
}
