#include <bits/stdc++.h>

using namespace std;

int n, m, x, y;
long long res, ans = 1e18;
multiset<int> v, p[3005];

int main(){

  	scanf("%d %d", &n, &m);
 	for(int i=0; i<n; i++){
   	 	scanf("%d %d", &x, &y);
   	 	p[x].insert(y);//每一个party所需要的票价 
    	if(x != 1){
    		v.insert(y);//收买其他人的票价 
		}	
 	 }
 	 long long rem = 0;
 	 int tkn = 0;
 	 for(int i = n; i > 0; i--){
   		 for(int j=2; j<=m; j++){
      		if(p[j].size() < i){//类似于将最大票数控制在i以下 
      	 		continue;
	 		} 
     		while(p[j].size() >= i){//类似于将最大票数控制在i以下 
	    		tkn++;					//目前取走的高于 i的票 
	    		rem += *p[j].begin();//set集合自动排序，取出最小值 
	    		v.erase(v.find(*p[j].begin()));
	    		p[j].erase(p[j].begin());
      		}
    	}
    	int cnt = i - (int)p[1].size() - tkn;//这是1与其他政党中票数最多的政党的大小比较 
    	res = rem;
    	for(auto a: v){
     	 	if(cnt <= 0){//cnt<=0说明不需要更多的票数了，否则还需要全局最小票数，来凑数超越第一大党
			  //其中可能选第一大党的票数，是他的票数-1，效果等价于-2，但是这里贪心没考虐
			  //但是后面遍历i时，会把这种情况算进去 
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
