#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;
bool fun(string t){
	string tmp=t;//初始串 
	string t1="";
	string t2="";
	int len=t.size();
	for(int i=1;i<=len;i++){
		string ans="";t1="";t2="";
		t1=t.substr(0,i);
		t2=t.substr(i,len-i);
		ans=t2+t1;
		if(ans<tmp) return 0;
	}
	return 1;
}
int Get_min(string s){//最小表示法
    int n = s.size();
    int i = 0,j = 1,k = 0,t;
    //表示从i开始k长度和从j开始k长度的字符串相同
    while(i < n && j < n && k < n){
        t = s[(i+k)%n] - s[(j+k)%n];
        //t用来计算相对应位置上那个字典序较大
        if(!t) k++;//字符相等的情况
        else{
            if(t > 0) i += k+1;//i位置大
            else j += k+1;//j位置大
            if(i == j) j++;
            k = 0;
        }
    }
    //return min(i,j) 
    int pos=min(i,j);
    if(pos==0) return 1;
    else return 0;
}
int main(){
	std::ios::sync_with_stdio(false);  
	int t;
	cin>>t;
	while(t--){
	  string s;
	  cin>>s;
	  int len=s.size();
	  int l=0; 
	  int r=len;
	  while(1){
	  	for(int i=r;i>=0;i--){//每次从主串末尾开始往回缩 
	  	    string t=s.substr(l,i-l);
	  	    if(Get_min(t)){
	  	    	for(int j=l;j<i;j++) 
	  	    	    cout<<s[j];
	  	        l=i;//更新 新段的l 
	           cout<<" ";  
			   break;	     	
			}
		}
		if(l==r) break;
	  }
	  cout<<endl; 
	}	
	return 0;
} 