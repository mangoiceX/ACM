#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
int main(){
	ULL n = 0,q = 0;
	while(cin >> n >> q){
		ULL me = 0,mo = 0;
		ULL start = 0;
		if(n % 2 == 0){
			 me = n/2,mo = n/2;
			 start = n*n / 2 + 1;
		}else{
			me = (n+1)/2,mo = (n-1)/2;
			start = (n*n + 1)/2+1;
		}
		ULL x = 0,y = 0;
		for(ULL i = 0;i < q;++i){
			cin >> x >> y;
			if(n % 2 == 0){
				if((x + y) % 2 == 0){
					cout << 1 + (x-1)*me + (y-1)/2 <<endl;
				}else{
					cout << start + (x - 1)*mo + (y - 1)/2 << endl;
				}
			}else{
				if((x + y) % 2 == 0){
					ULL sum = (x - 1)/2 * n + ((x%2 == 0) ? me : 0 );
					//cout << "em " << sum << " " << me << " " << x << " " << y << endl;
					cout << 1 + sum + (y-1)/2 <<endl;
				}else{
					ULL sum = (x - 1)/2 * n + ((x%2 == 0) ? mo : 0 );
					cout << start + sum + (y-1)/2 <<endl;
				}	
			}
			
		}
		
		cout << endl;
	}
	
	
	return 0;
}
