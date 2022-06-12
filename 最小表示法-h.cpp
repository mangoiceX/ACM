#include<iostream>
#include<string>
#include<vector>
#include<cstring> 
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 10;
int n = 0;
string str;//最小表示法，时间复杂度O(n)

int min_rep(){//用最小表示法求字符串S的最小字典序,返回字典序最小的串的首字母位置
	
	int i = 1,j = 0,k = 0;
	while(i < n && j < n){//由于循环性，所以是str[(i+k)%n]，要对n取模，保证不超过，变成循环的
	//也可也将原来的字符串*2 
		k = 0;
		while(str[(i+k) % n] == str[(j+k) % n] && k < n){//直到第一个不相等的位置 
			++k;
		}
		if(k == n){
			//return i < j?i :j;// 返回两者的较少值，而不是就是i
			return min(i,j); 
			//return i;//这是错误的 
		}
		if(str[(i+k) % n] > str[(j+k) % n]){
			/*
			if(i +k +1 > j){
				i = i+k+1;	
			}else{
				i = j+1;
			}*/
			i = max(i+k+1 ,j + 1);//可以这样代替，简洁的写法. 
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
		//scanf("%s",&str[0]);//会RE 
		cin >> n;
		cin >> str;
		cout << min_rep() << endl;
	//	printf("%d\n",min_rep());
	}
	
	return 0;
}
