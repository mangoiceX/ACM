#include<iostream>
#include<string>
#include<vector>
#include<cstring> 
#include<algorithm>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
const int maxn = 2e2 + 10;
char s[maxn];
struct node{
	int l,r;
};
int get_max_min(string& s,int flag){
    int len = s.length();
    int i = 0, j = 1, k = 0, t;
    while(i < len && j < len && k < len) {
        t = s[(j + k) % len] - s[(i + k) % len];
        if(t == 0){
        	k++;
        }else{
            if(flag == 1){//最大表示法
                if(t >= 0){
                	// i += k + 1;
                	i = max(i+k+1,j+1);
                }else{
                	// j += k + 1;
                	j = max(j+k+1,i+1);
                } 
            }else{//最小表示法
                if(t >= 0){
                	// if(j +k+1 > i){
                	// 	j += k + 1;
                	// }else{
                	// 	j = i+1;
                	// }
                	j = max(j+k+1,i+1);
                }else{
                	// if(i+k+1 > j){
                	// 	i += k + 1;
                	// }else{
                	// 	i = j+1;
                	// }
                	i = max(i+k+1,j+1);
                } 
            }
            if(i == j){
            	++j;
            }
            k = 0;
        }
    }
    return min(i, j);
}

int main(){
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		int len = strlen(s);
		int fir = 0,las = 0;
		vector<node> ans;
		while(las <= len-1){
			rep(i,len-1,fir){
				string tmp = "";
				per(j,fir,i){
					tmp += s[j];
				}
				int res = get_max_min(tmp,0);
				if(res == 0){
					las = i;
					break;
				}
			}
			ans.push_back(node{fir,las});
			fir = las + 1;
			las=  fir;
		}
		int si = ans.size();
		per(i,0,si-1){
			per(j,ans[i].l,ans[i].r){
				printf("%c",s[j]);
			}
			printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
