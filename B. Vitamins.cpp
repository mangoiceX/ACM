#include<bits/stdc++.h>
#include<set>
#define INF 0x3f3f3f3f 
using namespace std;
const int maxn = 1e5 + 100;
typedef long long LL;
set<int> s1,s2,s3,s4,s5,s6,s7;
int n = 0;
//char str[4];
string str;
int main(){
	//while(~scanf("%d",&n)){
	while(cin >> n){
		s1.clear();s2.clear();s3.clear();s4.clear();s5.clear();s6.clear();s7.clear();
		for(int i = 0;i < n;++i){
			int val = 0;
			//scanf("%d %s",&val,str);
			cin >> val >> str;
			if(str == "A"){
				s1.insert(val);
			}
			if(str == "B"){
				s2.insert(val);
			}
			if(str == "C"){
				s3.insert(val);
			}
			if(str == "AB" || str == "BA"){
				s4.insert(val);
			}
			if(str == "AC" || str == "CA"){
				s5.insert(val);
			}
			if(str == "BC" || str == "CB"){
				s6.insert(val);
			}
			if(str == "ABC" || str == "ACB" || str == "BAC" || 
			str == "BCA" || str == "CAB" || str == "CBA"){
				s7.insert(val);
				//cout << "em "<< endl;
			}
			
		} 
		int minv = INF;
		if(!s1.empty() && !s2.empty() && !s3.empty() &&*s1.begin() + *s2.begin() 
		+ *s3.begin()< minv){
			minv = *s1.begin() + *s2.begin() + *s3.begin();
		}
		
		if(!s1.empty() && !s6.empty() &&*s1.begin() + *s6.begin() < minv){
			minv = *s1.begin() + *s6.begin();
		}
		if(!s2.empty() && !s5.empty() && *s2.begin() + *s5.begin() < minv){
			minv = *s2.begin() + *s5.begin();
		}
		if(!s3.empty() && !s4.empty() &&*s3.begin() + *s4.begin() < minv){
			minv = *s3.begin() + *s4.begin();
		}
		
		if(!s4.empty() && !s6.empty() &&*s4.begin() + *s6.begin() < minv){
			minv = *s4.begin() + *s6.begin();
		}
		if(!s5.empty() && !s6.empty() &&*s5.begin() + *s6.begin() < minv){
			minv = *s5.begin() + *s6.begin();
		}
		if(!s4.empty() && !s5.empty() &&*s4.begin() + *s5.begin() < minv){
			minv = *s4.begin() + *s5.begin();
		}
		
		if(!s7.empty() &&*s7.begin()< minv){
			minv = *s7.begin() ;
		}
		if(minv == INF){
			printf("-1\n");
			continue;
		}
		printf("%d\n",minv);	
	}
	
	return 0;
} 
