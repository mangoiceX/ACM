#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 2e5 + 100;
typedef unsigned long long LL; 
int data[maxn];
LL sum[maxn];
LL res[maxn];
int main(){
	int n = 0,k = 0;
	cin >> n >> k;
	memset(sum,0,sizeof(sum));
	for(int i = 1;i <= n;i++){
		cin >> data[i];
		sum[i] = sum[i-1] + data[i];//����ǰ׺�� 
	}
	
	for(int i = 1;i <= n - k + 1;++i){
		res[i] = sum[i + k - 1] - sum[i - 1];//��i��ʼ������k�����ĺ� 
	}
	
	int left[maxn];
	left[1] = 1;
	int maxl = 1;
	for(int i = 1;i <= n-k+1;++i){
		//��ǰ����right[i]��ʾ���Ǵ�1��i�������������Ŀ�ʼ�±� 
		if(res[i] > res[maxl]){
			maxl = i;
		}
		left[i] = maxl;
	}
	
	int right[maxn];
	right[n-k+1] = n-k+1;
	int maxr = n-k+1;
	for(int i = n-k+1;i >= 1;--i){
		//�Ӻ���ǰ��right[i]��ʾ���Ǵ�i��n�������������Ŀ�ʼ�±� 
		if(res[i] >= res[maxr]){//������>= ����ΪҪ����С���±꣬����������ʱ��ѡ��С�� 
		
			maxr = i;
		}
		right[i] = maxr;
	}
	LL maxv = 0;
	int l = 0,r = 0;
	for(int i = 1;i <= n-k+1-k;++i){
		int j = i + k;
		if( (res[left[i]] + res[right[j]] ) > maxv){
			maxv = res[left[i]] + res[right[j]];
			l = left[i],r = right[j];
		}
	}
	cout << l << " " << r << endl;
	
	return 0;
}
