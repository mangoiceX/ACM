#include<iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct node{
    int x,y;
}s[1100];
 
int cal(node A, node B, node C){
    return (A.x-B.x)*(C.y-B.y)-(C.x-B.x)*(A.y-B.y);
}
 
int main(){
    int n = 0;
    while(scanf("%d",&n) != EOF){
        for(int i=0; i<=n; i++){
        	cin>>s[i].x>>s[i].y;
		}  
        s[n+1].x = s[1].x;
        s[n+1].y = s[1].y;
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(cal(s[i-1], s[i], s[i+1]) < 0){
            	ans++;
			}
        }
        cout<<ans<<endl;
    }
    return 0;
}

