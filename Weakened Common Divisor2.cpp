#include<bits/stdc++.h>
using namespace std;
typedef int LL;
const LL maxn = 150000 + 10; 
int n = 0;
vector<pair<LL,LL> > wc;
set<int> st,st1;
void pre_solve(){
	int flag = 0;
	LL i = 2;
	LL tmp1 = wc[0].first;
	LL p = sqrt(wc[0].first + 1);//由于sqrt的误差，要加上1再开根号 
	while(tmp1 > 1 && i <= p){//分解质因数 
		if(tmp1 % i == 0 ){
			flag = 1;
			st.insert(i);
			tmp1 /= i;
			while(tmp1 % i == 0){
				tmp1 /= i;
			}
			++i;
		}else{
			++i;
		}
	}
	if(flag == 0){//如果本身就是质数，也要放进st 
		st.insert(wc[0].first);
	}
	if(tmp1 > 1){//如果最后的余数是个质数(并且大于根号n),也要放进去，之前就是因为这里一直WA6 
		st.insert(tmp1);
	}
	i = 2,flag = 0;
	LL tmp2 = wc[0].second;
	p =	sqrt(wc[0].second + 1);
	
	while(tmp2 > 1 && i <= p ){//分解质因数 
		if(tmp2 % i == 0  ){
			flag = 1;
			st.insert(i);
			tmp2 /= i;
			while(tmp2 % i == 0){
				tmp2 /= i;
			}
			++i;
		}else{
			++i;
		}
		
	}
	if(flag == 0){
		st.insert(wc[0].second);
	}
	if(tmp2 > 1){
		st.insert(tmp2);
	}
	/*
	if(wc[0].first % wc[0].second == 0){//错误的理解 
		st.insert(wc[0].second);
	}
	if(wc[0].second % wc[0].first == 0){
		st.insert(wc[0].first);
	}
*/ 
	
}
int main(){
	while(scanf("%d",&n) != EOF ){
		wc.clear();
		st.clear();
		
		LL x = 0,y = 0;
		for(int i = 0;i < n;++i){
			scanf("%d %d",&x,&y);
			wc.push_back(pair<LL,LL> (x,y));
		}
		pre_solve();//预处理 
		set<int>::iterator it;
		
		for(int i = 1;i < n;++i){
			st1.clear();	
			for(it = st.begin();it != st.end();it++){
				if(wc[i].first % *it == 0 || wc[i].second % *it == 0){
					st1.insert(*it);//存储筛选后的质因子 
				}
			}
			if(st1.size() == 0){//没有公共质因子时，直接退出 
				printf("-1\n");
				st = st1;
				break;
			}
			st = st1;//记得赋值给st	
		}
		
		set<int>::iterator it1 = st.begin();//记得遍历st而不是st1，因为可能st1没有遍历，n = 1时 
		if(st.size() != 0){//之前因为这里WA7 
			printf("%d\n",*it1);
		}
	}
	return 0;
}
