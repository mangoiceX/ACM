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
char str[100010];//������1e5+10,��Ҫ��100010 
int main(){
	int n = 0; 
	scanf("%d %s",&n,str);
	sort(str,str+n);
	printf("%s\n",str);
	return 0;
}
*/
