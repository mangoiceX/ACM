#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define INF 1e6
using namespace std;
int n = 0,t = 0;

bool judge(){
	int odd = 0,even = 0;
	int temp = n,cnt = 1;
	while(temp > 0){
		if(cnt % 2 == 1){
			odd += temp % 10;
			temp /= 10;
		}else{
			even += temp % 10;
			temp /= 10;
		}
		++cnt;
	}
	//cout << odd << " " << even << endl;
	int sum = odd + even;
	for(int i = 0;i < t;++i){
		//odd %= 11,even %= 11;
		int temp1 = sum;
		int j = 0;
		while(sum / int(pow(10,j)) > 0){
			++j;
		}
		while(temp1 > 0){
			temp = odd,odd = even,even = temp;
			odd += temp1 / pow(10,j-1);
			sum += temp1 / pow(10,j-1);
			odd %= 11;
			temp1 = temp1 % int(pow(10,j-1));
			--j;
			//cout << odd << " " << even << endl;	
		}
	
	}
	
	return (abs(odd - even) % 11 == 0) ? true : false;
	
}
int main(){
	int kase = 0;
	while(scanf("%d %d",&n,&t) != EOF && (n != -1 || t != -1)){
		if(judge()){
			printf("Case #%d: Yes\n",++kase);
		}else{
			printf("Case #%d: No\n",++kase);
		}
	}
	
	return 0;
}
