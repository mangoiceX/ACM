#include<iostream>
#include<string>
#include<vector>
#include<cstring> 
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 10;
int h[maxn];
int num = 0;
int Manacher(){
	int t[maxn*2+100];
	t[0] = -1,t[1] = 0;
	for(int i = 1;i <= num;++i){//��� 
		t[2*i] = h[i];
		t[2*i+1] = 0;
	}
	t[2 * num + 2] = -2;
	int p[maxn*2+100];
	memset(p,0,sizeof(p));
	int mx = 0,id = 0,resLen = 0,resCenter = 0;
	for(int i = 1;i <= num*2+1;++i){
		p[i] = mx > i? min(mx - i,p[2 * id - i]) : 1;//�ؼ�����
		//���ĵĵط������Ϊ0�ĵط�����������Ҫ<=ǰ��-2,��Ϊ�м��и�0
		//����������������м�������������������Ƚϣ����ԾͿ��������� 
		while(t[i + p[i]] == t[i - p[i]] &&(t[i+p[i]] == 0 || t[i+p[i]] <= t[i+p[i]-2])){
			++p[i];
		}
		if(i+p[i] > mx){
			mx = i + p[i];
			id = i;
		}
		if(p[i] > resLen){
			resLen = p[i];
			resCenter = i;
		}
	}
	return resLen - 1;
}
int main(){
	//std::ios::sync_with_stdio(false);
	//std::ios::sync_with_stdio(false);
	int T = 0;
	//cin >> T;
	scanf("%d",&T);
	while(T--){
		//cin >> num ;
		scanf("%d",&num);
		for(int i = 1;i <= num;++i){
			//cin >> h[i];
			scanf("%d",&h[i]);
		}
		//cout << Manacher() << endl;
		printf("%d\n",Manacher());
	}
	return 0;
}
