#include <bits/stdc++.h>

using namespace std;

int n, m, x, y;
long long res, ans = 1e18;
multiset<int> v, p[3005];

int main(){

  	scanf("%d %d", &n, &m);
 	for(int i=0; i<n; i++){
   	 	scanf("%d %d", &x, &y);
   	 	p[x].insert(y);//ÿһ��party����Ҫ��Ʊ�� 
    	if(x != 1){
    		v.insert(y);//���������˵�Ʊ�� 
		}	
 	 }
 	 long long rem = 0;
 	 int tkn = 0;
 	 for(int i = n; i > 0; i--){
   		 for(int j=2; j<=m; j++){
      		if(p[j].size() < i){//�����ڽ����Ʊ��������i���� 
      	 		continue;
	 		} 
     		while(p[j].size() >= i){//�����ڽ����Ʊ��������i���� 
	    		tkn++;					//Ŀǰȡ�ߵĸ��� i��Ʊ 
	    		rem += *p[j].begin();//set�����Զ�����ȡ����Сֵ 
	    		v.erase(v.find(*p[j].begin()));
	    		p[j].erase(p[j].begin());
      		}
    	}
    	int cnt = i - (int)p[1].size() - tkn;//����1������������Ʊ�����������Ĵ�С�Ƚ� 
    	res = rem;
    	for(auto a: v){
     	 	if(cnt <= 0){//cnt<=0˵������Ҫ�����Ʊ���ˣ�������Ҫȫ����СƱ������������Խ��һ��
			  //���п���ѡ��һ�󵳵�Ʊ����������Ʊ��-1��Ч���ȼ���-2����������̰��û��Ű
			  //���Ǻ������iʱ���������������ȥ 
      			break;
	 	 	}
      		res += a;
      		cnt--;
     	}
    ans = min(res, ans);
  }
  cout << ans << endl;

  return 0;
}
