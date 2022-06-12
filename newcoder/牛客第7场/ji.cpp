#include<iostream>
#include<string>
#include<vector>
#include<cstring> 
#include<algorithm>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
const int maxn = 2e2 + 10;
// string s;
char s[maxn];
struct node{
	int l,r;
};

int min_rep(string& str){
	int i = 1,j = 0,k = 0;
	int n = str.length();
	// cout << "len " << n << endl;
	while(i < n && j < n && k < len){
		k = 0;
		while(str[(i+k) % n] == str[(j+k) % n] && k < n){
			++k;
		}
		// if(k == n){
		// 	return j;
		// }
		if(str[i+k] > str[j+k]){
			if(i +k +1 > j){
				i = i+k+1;	
			}else{
				i = j+1;
			}
			//i = max(i+k+1 ,j + 1);
		}else{
			if(j+k+1 > i){
				j = j+k+1;	
			}else{
				j = i+1;
			}
			//j = max(j+k+1, i+1);
		}
		if(i == j){
			++i;
		}
	}
	// cout <<i <<" fjdal " << j << endl;
	return min(i,j); 
}

int get_max_min(string& s, int flag) { // 1 ?? 0 ??
    int len = s.length();
    int i = 0, j = 1, k = 0, t;
    while(i < len && j < len && k < len) {
        t = s[(i + k) % len] - s[(j + k) % len];
        if(!t) k++;
        else {
            if(flag) {
                if(t > 0) j += k + 1;
                else i += k + 1;
            } else {
                if(t > 0) i += k + 1;
                else j += k + 1;
            }
            if(i == j) j++;
            k = 0;
        }
    }
    return min(i, j);
}

int main(){

	// std::ios::sync_with_stdio(false);
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	int T = 0;
	// cin >> T;
	scanf("%d",&T);
	while(T--){
		// cin >> s;
		// getchar();
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
				// int res = min_rep(tmp);
				int res = get_max_min(tmp,0);
				// cout <<tmp << " " << res <<" " << i <<endl;
				if(res == 0){
					las = i;
					// cout<< las << " jfa " << i << endl;
					break;
				}
			}
			ans.push_back(node{fir,las});
			fir = las + 1;
			las=  fir;
		}
		
		int si = ans.size();
		per(i,0,si-1){
			// printf("%d %d\n",ans[i].l,ans[i].r);
			per(j,ans[i].l,ans[i].r){
				// printf("%c",s[j]);
				// cout << s[j];
				printf("%c",s[j]);
			}
			
			// if(i == si-1){
			// 	continue;
			// }
			printf(" ");
			// cout << " ";
		}
		// puts("");
		printf("\n");
		// cout << '\n';
	}
	
	return 0;
}
/*
100
00100110011001
1011010110111101100100110011001
101101011011110110010011001100100000011011010111001100111111000011010010110011000100011100110100011001111110100010111011011
001011111010101001
1101111001011111010101001000011100001111010001110000111010000110000100001001101011101111011010110000
10010010100010100011001000010110101100101011011111100011011111011101010110000011110011010
10010010100010100011001000010110101100101011011111100011011111011101010110000011110011010

111111101111101011000001010101000000000100110000001011000

8
1000000100
00010101110100
001001
010
0100001011
00001010100110
01
010111100101101110

1
0001101111001010010
*/