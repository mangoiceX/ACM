#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, prod, cnt;
	scanf("%d",&n);
	if (n == 1){
		printf("1\n");
		return 0;
	}
	if (n == 2){
		printf("1 2\n");
		return 0;
	}
	if (n == 3){
		printf("1 1 3\n");
		return 0;
	}
	for (int i = 1; i <= (n + 1) / 2; i++) printf("1 ");
	prod = 1;
	cnt = 0;
	while (true){
		prod *= 2;
		if (n < prod) break;
		cnt++;
	}
	cnt--;
	prod = 1;
	for (int i = 1; i <= cnt; i++){
		prod *= 2;
		for (int j = prod; j <= n; j += prod * 2){
			printf("%d ",prod);
		}
	}
	//printf("%d\n",n / (1 << cnt) * (1 << cnt));
	//printf("%d\n",((n / prod) % 2 == 1) ? (prod *(n/prod)) : (1 << (cnt + 1)));
	printf("%d\n",(n / prod) * prod);//����������4������Ҫɾ����2�ı���������4�ı������� 
	return 0;//��Ϊ4�����һ��2^m<n;����ɾ��2�ı�����ֻʣ��4��ǰ�涼��ӡ2����Ȼֻ��1��ȥ�� 
} 	//�ҿ���ѡ������ģ��Ǿ��Ǳ�2ɾ���ı�nС����������൱�ڲ�Ҫ4 
