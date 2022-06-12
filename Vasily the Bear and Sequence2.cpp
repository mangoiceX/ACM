#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 2e5 + 100;

int data[maxn],ans[maxn];
int n = 0;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1;i <= n;++i){
		cin >> data[i];
	}
	for(int i = 30;i >= 0;--i){
		int temp = (1 << i) - 1;//�������λ��0�������ȫ��1��������ȡ��λ������� 
		int cnt = 0;
		for(int j = 1;j <= n;++j){
			if(data[j] & (1 << i)){//���λ��1 
				temp = temp & data[j];//���λ�������������&���� 
				ans[++cnt] = data[j];
			}
		}
		if(temp == 0){//�жϺ�����ܷ�ȫ�����0 
			cout << cnt << endl;
			for(int k = 1;k <= cnt;++k){
				if(k > 1){
					cout << " ";
				}
				cout << ans[k];
			}
			cout << endl;
			break;
		}
		
	}
		
	return 0;
}
