#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
const LL maxn = 150000 + 10; 
int n = 0;
vector<pair<LL,LL> > wc;
set<int> st,st1;
void pre_solve(){
	LL i = 2;
	LL tmp1 = wc[0].first;
	//LL p = 
	while(tmp1 > 1 && i <= wc[0].first){
		if(tmp1 % i == 0 ){
			st.insert(i);
			tmp1 /= i;
			while(tmp1 % i == 0){
				tmp1 /= i;
			}
			++i;
		}else{
			++i;
			continue;
		}
		
	}
	i = 2;
	LL tmp2 = wc[0].second;
	while(tmp2 > 1 && i <= wc[0].second){
		if(tmp2 % i == 0  ){
			st.insert(i);
			tmp2 /= i;
			while(tmp2 % i == 0){
				tmp2 /= i;
			}
			++i;
		}else{
			++i;
			continue;
		}
		
	}
	
	
}
int main(){
	while(scanf("%I64d",&n) != EOF ){
		wc.clear();
		st.clear();
		//st = st1;
		//st1.clear();
		LL x = 0,y = 0;
		int flag = 0;
		for(int i = 0;i < n;++i){
			//cin >> x >> y;
			scanf("%I64d %I64d",&x,&y);
			wc.push_back(pair<LL,LL> (x,y));
		}
		pre_solve();
		/*
		set<int>::iterator it2;
		for(it2 = st.begin();it2 != st.end();it2++){
			cout << "en " << *it2 << endl;
		}
		*/
		if(st.size() == 0){
			//cout << "-1" << endl;
			printf("-1\n");
			continue;	
		}
		set<int>::iterator it;
		for(int i = 0;i < n;++i){
			st1.clear();
			
			flag = 0;
			for(it = st.begin();it != st.end();it++){
				if(wc[i].first % *it == 0 || wc[i].second % *it == 0){
					st1.insert(*it);
					flag = 1;
					//break;
				}
			}
			if(flag == 0){
				//cout << "-1" << endl;
				printf("-1\n");
				break;
			}
			if(st1.size() == 0){
				//cout << "-1" << endl;
				printf("-1\n");
				break;
			}
			st = st1;
			/*
			for(it2 = st1.begin();it2 != st1.end();it2++){
				cout << "MMen " << *it2 << endl;
			}
			*/
		}
		/*
		for(it2 = st1.begin();it2 != st1.end();it2++){
				cout << "OOOO " << *it2 << endl;
			}
			*/
		set<int>::iterator it1 = st1.begin();
		if(flag != 0 && st1.size() != 0){
			//cout << *it << endl;
			printf("%d\n",*it1);
		}
	}
	return 0;
}
