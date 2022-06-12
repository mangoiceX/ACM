#include<bits/stdc++.h>
#define INF 1e6 
using namespace std;
const int maxn = 1e5 + 100;
typedef long long LL; 
multiset<int,greater<int> > a,b;
//priority_queue<int> q1,q2;
int n = 0;
LL sum1 = 0,sum2 = 0;
void solve(){
	int time = 1;
	while(!a.empty() || !b.empty()){
		/*
		if(a.empty()){
			while(!b.empty()){
				sum2 += *b.begin();
				b.erase(b.begin());
			}
			break;
		}
		if(b.empty()){
			while(!a.empty()){
				sum1 += *a.begin();
				a.erase(a.begin());
			}
			break;
		}
		*/
		if(time % 2 == 1){
			if(*(a.begin()) > *(b.begin())){
				//cout << "em "<< *b.begin()<<endl;
				sum1 += *a.begin();
				a.erase(a.begin());
			}else{
				b.erase(b.begin());
			}
			++time;
		}else{
			if(*(b.begin()) > *(a.begin())){
				
				sum2 += *b.begin();
				b.erase(b.begin());
			}else{
				//cout << "erm "<< *b.begin()<<endl;
				a.erase(a.begin());
			}
			++time;
		}
	}
	//printf("%lld %lld %I64d\n",sum1,sum2,sum1 - sum2);//提交时要删除，否则CF不通过 
	printf("%I64d\n",sum1 - sum2);
}
int main(){
	while(scanf("%d",&n) != EOF){
		int x = 0;
		a.clear();b.clear();
		for(int i = 0;i < n;++i){
			scanf("%d",&x);
			a.insert(x);
			//q1.push(x);
		}
		for(int i = 0;i < n;++i){
			scanf("%d",&x);
			b.insert(x);
			//q2.push(x);
		}
		solve();
	}
	
	return 0;
}
