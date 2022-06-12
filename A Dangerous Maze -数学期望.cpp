#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#define INF 0x7fffffff
using namespace std;
const int maxn = 2002 + 10;

int gcd(int a,int b){
	return b == 0?a : gcd(b,a%b);
}
//��ʽ���Ƶ�ţ�ƣ�ͻȻ�о�������ѧ�������� 
/*
����Ŀ��֪���뿪����ķ�����������֣�����һ���������ʽ��û�취�г�����

���������뿪���������ֵ��E;

������E=(t1+t2+����+tn + G1+G2+����+Gm)/(n+m);ps:t����ֱ��ѡ�������뿪��
G����������� �뿪�Թ������

������Ҫ�����뿪�������ͱ���Ҫ��һ�������뿪��������ɴ��䣬
��Gm = abs(NEGATIVEm) + E;

������E = (t1+t2+����+tn + (abs(T1)+E)+(abs(T2)+E)+����+(abs(Tm)+E))/n 
�� E = (t1+t2+����+tn+abs(T1)+abs(T2)+����+abs(Tm))/(n-m);

������� n-m =0 ʱ����Ϊinf

*/
int main(){
	
	int T = 0,n = 0,temp = 0,kase = 0;	
	scanf("%d",&T);
	while(T--){
		int sum = 0,m = 0,nn = 0;
		scanf("%d",&n);
		for(int i = 0;i < n;++i){
			scanf("%d",&temp);
			if(temp < 0){
				++m;
			}
			sum += abs(temp);
		}
		nn = n - m;
		if(n - m == 0){
			printf("Case %d: inf\n",++kase);
		}else{
			int gg = gcd(sum,nn);//�����ǵ����Լ�� 
				
			printf("Case %d: %d/%d\n",++kase,sum/gg,nn/gg);
		}
	}
	
	
	return 0;
}
