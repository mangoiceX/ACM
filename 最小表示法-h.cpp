#include<iostream>
#include<string>
#include<vector>
#include<cstring> 
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 10;
int n = 0;
string str;//��С��ʾ����ʱ�临�Ӷ�O(n)

int min_rep(){//����С��ʾ�����ַ���S����С�ֵ���,�����ֵ�����С�Ĵ�������ĸλ��
	
	int i = 1,j = 0,k = 0;
	while(i < n && j < n){//����ѭ���ԣ�������str[(i+k)%n]��Ҫ��nȡģ����֤�����������ѭ����
	//Ҳ��Ҳ��ԭ�����ַ���*2 
		k = 0;
		while(str[(i+k) % n] == str[(j+k) % n] && k < n){//ֱ����һ������ȵ�λ�� 
			++k;
		}
		if(k == n){
			//return i < j?i :j;// �������ߵĽ���ֵ�������Ǿ���i
			return min(i,j); 
			//return i;//���Ǵ���� 
		}
		if(str[(i+k) % n] > str[(j+k) % n]){
			/*
			if(i +k +1 > j){
				i = i+k+1;	
			}else{
				i = j+1;
			}*/
			i = max(i+k+1 ,j + 1);//�����������棬����д��. 
		}else{
			/*
			if(j+k+1 > i){
				j = j+k+1;	
			}else{
				j = i+1;
			}*/
			j = max(j+k+1, i+1);
		}
	}
	//return i < j? i :j; 
	return min(i,j);
}
int main(){
	int T = 0;
	//scanf("%d",&T);
	cin >> T;
	while(T--){
		//scanf("%d",&n);
		//scanf("%s",&str[0]);//��RE 
		cin >> n;
		cin >> str;
		cout << min_rep() << endl;
	//	printf("%d\n",min_rep());
	}
	
	return 0;
}
