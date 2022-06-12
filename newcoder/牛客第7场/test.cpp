#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
typedef long long LL;
#define INF 1e18
const int maxn = 2e2 + 10;
int n = 0,m = 0;
bool vis[maxn];
char s[maxn];
struct node{
    int l,r,len0,len1;
};
void solve(){
    node pai[maxn];
    int len = strlen(s);
    int pre = 0,cnt = 0;
    pai[0].len0 = pai[0].len1 = -1;
    vector<node> ans;
    ans.push_back(node{0,-1,-1,-1});
    memset(vis,false,sizeof(vis));
    per(p,0,len-1){
        ++cnt;
        while(p < len && s[p] == '0'){
            ++p;
        }
        if(p - pre > 0){
            pai[cnt].len0 = p - pre;
        }else{
            pai[cnt].len0 = 0;
        }
        int mid = p;
        // cout << "haha " << mid << endl;
        while(p < len && s[p] == '1'){
            ++p;
        }
        if(p - mid > 0){
            pai[cnt].len1 = p - mid;
        }else{
            pai[cnt].len1 = 0;
        }
        // cout << pai[cnt].len0 << " " << pai[cnt].len1 << endl;
        pai[cnt].l = pre,pai[cnt].r = p-1;
        pre = p;
        --p;
        // cout << pai[cnt].len1 << " ni " << pai[cnt].len0<< endl;
        if(pai[cnt].len1 <= 0){
            ans.push_back(node{pai[cnt].l,pai[cnt].r,pai[cnt].len0,pai[cnt].len1});
            continue;
        }
        int si = ans.size();
        if(pai[cnt].len0 > ans[si-1].len0){
            // cout << pai[cnt].len0 << " 0 "<< ans[si-1].len0 <<endl;
            // cout << pai[cnt].len1 << " 1 "<< ans[si-1].len1 <<endl;
            // 0101111101011111001010101
            ans.push_back(node{pai[cnt].l,pai[cnt].r,pai[cnt].len0,pai[cnt].len1});
        }else if(pai[cnt].len0 == ans[si-1].len0){
            if(pai[cnt].len1 < ans[si-1].len1){
                ans.push_back(node{pai[cnt].l,pai[cnt].r,pai[cnt].len0,pai[cnt].len1});
  
            }else if(pai[cnt].len1 == ans[si-1].len1){
                if(!vis[si-1]){
                    int size = ans.size();
                    ans[size-1].r = pai[cnt].r;
                    // vis[size-1] = true;
                }else{
                    int sis = ans[si-1].r - ans[si-1].l + 1;
                    // cout << "sis " << ans[si-1].r << "  "<< ans[si-1].l <<endl;
                    bool fg = true;
                    per(i,pai[cnt].l,pai[cnt].l+sis-1){
                        if(s[i-sis] != s[i]){
                            fg = false;
                            break;
                        }
                    }
                    if(fg){
                        ans[si-1].r = pai[cnt].l+sis-1;
                        p = pai[cnt].l+sis-1;
                        pre = p+1;
                        // --p;
                        // cout << pai[cnt].l <<" fj idoas " << p << endl;
                        continue;
                    }
                    ans.push_back(node{pai[cnt].l,pai[cnt].r,pai[cnt].len0,pai[cnt].len1});
                }
            }else{
                int size = ans.size();
                ans[size-1].r = pai[cnt].r;
                vis[size-1] = true;
            }
        }else{
            int size = ans.size();
            ans[size-1].r = pai[cnt].r;
            vis[size-1] = true;
        }
    }
    int size = ans.size();
    vector<node> res;
    // int before = 1;
    res.push_back(node{ans[1].l,ans[1].r,0,0});
    per(i,2,size-1){
        if(ans[i].len1 == 0 || ans[i].len0 == 0){
            res.push_back(node{ans[i].l,ans[i].r,0,0});
            continue;
        }
        string s1,s2;
        int mi = min(res[res.size()-1].r-res[res.size()-1].l,ans[i].r-ans[i].l);
        per(j,res[res.size()-1].l,res[res.size()-1].l+mi){
            s1.push_back(s[j]);
        }
        per(j,ans[i].l,ans[i].l+mi){
            s2.push_back(s[j]);
        }
        // cout << "s1 " << s1 << " " << s2 << endl;
        int sp = res.size();
        if(s1 < s2){
            res[res.size()-1].r = ans[i].r;
            continue;
        }else if(s1 == s2){
            if(res[res.size()-1].r-res[res.size()-1].l > ans[i].r-ans[i].l){
                int pos = res[sp-1].l+ans[i].r-ans[i].l;//前面都相等的话，看res后面那一位
                if(s[pos] == '0'){
                    res[res.size()-1].r = ans[i].r;
                    continue;
                }
            }
        }
        res.push_back(node{ans[i].l,ans[i].r,0,0});
        // before = i;
    }
    // per(i,1,size-1){
    //  per(j,ans[i].l,ans[i].r){
    //      printf("%c",s[j]);
    //  }
    //  printf(" ");
    // }
    // puts("");
    int sj = res.size();
    per(i,0,sj-1){
        per(j,res[i].l,res[i].r){
            printf("%c",s[j]);
        }
        // if(i == size-1){
        //  continue;
        // }
        printf(" ");
    }
    puts("");
}
int main(){
    int T = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        solve();
    }
  
    return 0;
}
/*
10
0101
0000
111
1001
0010010011
0011001
1001
10011
11100110
001010001
  
00101 001001111 0010100101111
001010010011110010100101111
 0010100101000001
  
 0101111101011111001010101
  
 010110101101011
*/