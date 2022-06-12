#include<bits/stdc++.h>
using namespace std;
string str;
int main(){
	int n = 0;
	while(cin >> n){
		cin >> str;
		sort(str.begin(),str.end());
		cout << str << endl;
	}
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
char str[100010];//不能用1e5+10,而要用100010 
int main(){
	int n = 0; 
	scanf("%d %s",&n,str);
	sort(str,str+n);
	printf("%s\n",str);
	return 0;
}
*/
