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
	LL p = sqrt(wc[0].first + 1);//����sqrt����Ҫ����1�ٿ����� 
	while(tmp1 > 1 && i <= p){//�ֽ������� 
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
	if(flag == 0){//����������������ҲҪ�Ž�st 
		st.insert(wc[0].first);
	}
	if(tmp1 > 1){//������������Ǹ�����(���Ҵ��ڸ���n),ҲҪ�Ž�ȥ��֮ǰ������Ϊ����һֱWA6 
		st.insert(tmp1);
	}
	i = 2,flag = 0;
	LL tmp2 = wc[0].second;
	p =	sqrt(wc[0].second + 1);
	
	while(tmp2 > 1 && i <= p ){//�ֽ������� 
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
	if(wc[0].first % wc[0].second == 0){//�������� 
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
		pre_solve();//Ԥ���� 
		set<int>::iterator it;
		
		for(int i = 1;i < n;++i){
			st1.clear();	
			for(it = st.begin();it != st.end();it++){
				if(wc[i].first % *it == 0 || wc[i].second % *it == 0){
					st1.insert(*it);//�洢ɸѡ��������� 
				}
			}
			if(st1.size() == 0){//û�й���������ʱ��ֱ���˳� 
				printf("-1\n");
				st = st1;
				break;
			}
			st = st1;//�ǵø�ֵ��st	
		}
		
		set<int>::iterator it1 = st.begin();//�ǵñ���st������st1����Ϊ����st1û�б�����n = 1ʱ 
		if(st.size() != 0){//֮ǰ��Ϊ����WA7 
			printf("%d\n",*it1);
		}
	}
	return 0;
}
