#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string> 
#include<cstring>
#include<set>
#define INF 0x7fffffff
using namespace std;
const int maxn = 100 + 10;
int n = 0;
//char str1[maxn],str2[maxn],s1[maxn],s2[maxn];
string str1,str2,s1,s2;
int ans[10010];
int main(){
	
	//scanf("%d",&n);
	//scanf("%s",str1);
	//scanf("%s",str2);
	cin >> n;
	cin >> str1;
	cin >> str2;
	//for(int i = 0;i < n;++i){
	//	s1[i] = str1[i];
	//	s2[i] = str2[i];
//	}
	s1 = str1,s2 = str2;
	sort(s1.begin(),s1.begin() + n);
	sort(s2.begin(),s2.begin() + n);
	if(s1 != s2){
		cout << "-1" << endl;
	}else{
		
	
	int k = 0;
	int i = 0,j = 0,h = 0;
	for( i = 0;i < n;++i){
		if(str1[i] != str2[i]){
			for( j = i+1;j < n;++j){
				if(str1[j] == str2[i]){ //找到相同的 
					for( h = j - 1;h >= i;--h){
						ans[k++] = h + 1;
					}
					char temp = str1[j];
					for(int h = j;h >= i+1;--h){
						str1[h] = str1[h-1];
					}
					str1[i] = temp;
					break;
				}
			}
		}
		//if(i == 3){
		//	cout << str1 << endl;;
		//}
	} 
	//cout << str1;
	cout << k<< endl;
	for(int i = 0;i < k;++i){
		if(i > 0){
			cout << " ";
		}
		cout << ans[i];
	}
	cout << endl;
}
	return 0;
}
