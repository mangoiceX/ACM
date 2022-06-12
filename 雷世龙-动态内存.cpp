#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#define INF 0x3f3f3f
using namespace std;
const int maxn = 1e5 + 100;
int m = 0,n = 0;

double s1 = 0,s2 = 0,s3 = 0,ave1 = 0,ave2= 0,ave3 = 0;//�����ƽ���� 
double cal_s(int *a,int m,double ave){//���㷽�� 
	double sum = 0;
	for(int i = 0;i < m;++i){
		sum += (a[i] - ave)*(a[i] - ave);
	}
	return sum / m;
}
void print(int* a,int m){//��ӡ���� 
	for(int i = 0;i < m;++i){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main(){
	while(scanf("%d %d",&m,&n) != EOF){//������������ 
		int *a,*b,*c;
		a = (int *)malloc(m*sizeof(int));b = (int *)malloc(n*sizeof(int));c = (int *)malloc((m+n+100)*sizeof(int));
		srand(time(NULL));//��ʼ������ 
		double sum1 = 0;
		for(int i = 0;i < m;++i){
			a[i] = rand() % 100;
			c[i] = a[i];
			sum1 += a[i];
		}
		ave1 = sum1 / m;
		double sum2 = 0;
		for(int i = 0;i < n;++i){
			b[i] = rand() % 100;
			c[m+i] = b[i];
			sum2 += b[i];
		}
		ave2 = sum2 / n;
		ave3 = (sum1 + sum2)/(m + n);

		printf("The origin data aer as follows:\n"); 
		print(a,m);print(b,n);//��ӡ��ʼ������
		printf("After sorted:\n");
		sort(a,a+m);sort(b,b+n);//���� 
		print(a,m);print(b,n);
		printf("Their average and variance are as follows:\n");
		
		printf("Array a: ave and variance\n");
		printf("%lf %lf\n",ave1,cal_s(a,m,ave1)); 
		
		printf("Array b: ave and variance\n");
		printf("%lf %lf\n",ave2,cal_s(b,n,ave2)); 
		
		printf("After merge:\n");
		sort(c,c+m+n);
		print(c,m+n);
		printf("Array c: ave and variance\n");
		printf("%lf %lf\n",ave3,cal_s(c,m+n,ave3)); 
		
		char s[10];
		printf("please input your command:\n");
		int size = m + n;//��¼����c�Ĵ�С 
		while(true){
			scanf("%s",s);
			int x = 0;
			if(s[0] == 'i'){
				scanf("%d",&x);
				c[size] = x;
				size++;
				printf("After sorted:\n");
				sort(c,c + size );
				print(c,size );
			}else if(s[0] == 'd'){
				scanf("%d",&x);
				c[x-1] = INF;//Ҫɾ��������INF��ǣ��������Ȼ�����������Ȼ����������� 
				printf("After sorted:\n");
				sort(c,c+size);
				print(c ,size - 1);
				size--;
			}else{
				break;
			}
		}
		
		free(a);free(b);free(c);
	}
	
	return 0;
} 
