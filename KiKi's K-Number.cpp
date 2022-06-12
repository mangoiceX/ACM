#include<iostream>
#include<cstdio>
#include<algorithm>	
#include<string>
#include<cstring>
#include<set>
using namespace std;
const int maxn = 1e5 + 10;
multiset<int > st;
int main(){
	//std::ios::sync_with_stdio(false);
	int m = 0,e = 0,order = 0,a = 0,k = 0;
	multiset<int>::iterator iter;
	//while(cin >> m && m){
	while(scanf("%d",&m) != EOF && m){
		st.clear();
		for(int i = 0;i < m;++i){
			//cin >> order ;
			scanf("%d",&order);
			if(order ==  0){
				//cin >> e;
				scanf("%d",&e);
				st.insert(e);
			}else if(order == 1){
				//cin >> e;
				scanf("%d",&e);
				if(st.find(e) == st.end()){		//delete the element which does not exist 
					//cout << "No Elment!" << endl;
					printf("No Elment!\n");
				}else{							//delete one of the element which  exists 
					iter = st.lower_bound(e);
					st.erase(iter);
				}
			}else if(order == 2){
				//cin >> a >> k;
				scanf("%d %d",&a,&k);
				iter = st.upper_bound(a);
				if(iter == st.end()){	//the greater number does not exist
					//cout << "Not Find!" << endl;
					printf("Not Find!\n");
				}else{
					for(int i = 0;i < k - 1 && iter != st.end();++i){
						iter++;
					}
					if(iter == st.end()){
						//cout << "Not Find!" << endl;
						printf("Not Find!\n");
					}else{
						//cout << *iter << endl;
						printf("%d\n",*iter);
					}	
				}
			}
		}
		
	}
	
	
	return 0;
}
