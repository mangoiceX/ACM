#include<bits/stdc++.h> 
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 3e5 + 10;
pair<int,int> s[maxn];
//���Ӷȼ���һ�£����ǿ��Թ��� 
int main(){
	int n = 0;
	while(scanf("%d",&n) != EOF){
		multiset<int> l,r;
		for(int i = 0;i < n;++i){
			scanf("%d %d",&s[i].first,&s[i].second);
			l.insert(s[i].first),r.insert(s[i].second);
		}
		int maxv = 0;
		for(int i = 0;i < n;++i){
			l.erase(l.find(s[i].first)),r.erase((r.find(s[i].second)));
			maxv = max ( maxv , *r.begin() - *l.rbegin());//rbegin()ָ��������һ��Ԫ�� 
		//	maxv = max ( maxv , *r.begin() - *l.end());//��end()ָ��������һ��Ԫ�ص���һ�� 
			l.insert(s[i].first),r.insert(s[i].second);
		}
		printf("%d\n",maxv);
	}	
	
	return 0;
} 
