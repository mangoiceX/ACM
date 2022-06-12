#include<iostream>
#include<cstdio>
#include<algorithm>	
#include<string>
#include<cstring>
#include<set>
using namespace std;
const int maxn = 32000 + 10;

int tree[maxn],level[maxn];
int n = 0;

int lowbit(int x){
	return x & (-x);
}

void add(int loc,int val){
	for(int i = loc;i <= maxn;i += lowbit(i)){
		tree[i] += val;
	}
	/*
	int  i = loc;
	while(i <= loc){
		tree[i] += val;
		i += lowbit(i);
	}
	*/
}

int getsum(int loc){
	int ans = 0;
	for(int i = loc;i > 0;i -= lowbit(i)){
		ans += tree[i]; 
	}
	/*
	int  i = loc;
	while(i > 0){
		ans += tree[i];
		i -= lowbit(i);
	}
	*/
	return ans;
}
int main(){
	int x = 0,y = 0;
	memset(tree,0,sizeof(tree));
	memset(level,0,sizeof(level));
	
	scanf("%d",&n);
	for(int i = 0;i < n;++i){//��Ϊy�ǵ����ģ����Կ��Բ��ÿ���y
		scanf("%d %d",&x,&y);
		++x;				//����0�ĳ��� 
		++level[getsum(x)];	//��ǰ������1-x�ĺͣ������䣩������ˮƽ��
		add(x,1);			//���ǣ���Ϊ�ǵ����ģ����� ֻ�ܿ���ǰ1-x������ܺ�
							//Ȼ���ٵ�����£����������� 
	}
	for(int i = 0;i < n;++i){
		printf("%d\n",level[i]);
	}
	
	
	return 0;
} 
