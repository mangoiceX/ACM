#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn = 1e3 + 10;
const LL mod = (1e9 + 7);
int n = 0,m = 0,k = 0;
char mp[maxn][maxn];
int h[maxn][maxn];
struct node{
	int v,id,w;
};
void init(){
	memset(h,0,sizeof(h));
}
void solve(){
	int ans0 = 0,ans1 = 0;
	// int h0 = 0,h1 = 0;//;
	init();
	per(i,1,n){
		stack<node> st;
		per(j,1,m+1){
			if(mp[i][j] == '1'){
				h[i][j] = h[i-1][j] + 1;
			}else{
				h[i][j] = 0;
			}
			// if(i == 4 && j == 21){
			// 	cout <<"niam "<< h[i][j] << endl;
			// }
			if(i == 4 && j == 16){
				cout << "ojo " << st.size() << " " << h[i][j] <<endl;
			}
			if(h[i][j] == 0 || j == m+1){
				if(i == 4 && j == 23){
					cout << "jojojoppppppppppppppppppp " << st.size() <<endl;
					cout << st.top().v << endl;
				}
				vector<node> vt;
					while(!st.empty()){
						vt.push_back(st.top());
						st.pop();
					}
					int si = vt.size();
					rep(k,si-1,1){
						int s0 = vt[k].v * (vt[0].id - vt[k].id + 1 + vt[k].w);
						int s1 = vt[k].v * (vt[0].id - vt[k].id + vt[k].w); 
						// if(vt[0].id - vt[i].id == 1){
						// 	s1 = 0;
						// }
						if(i == 4 && j == 23){
							cout << "jifoajdfisj  " << s0 << " " << s1 << endl;
						}
						if(s0 >= ans0){
							ans1 = ans0;
							ans0 = s0;
							// h0 = vt[i].v;
						}else if(s0 >= ans1){
							ans1 = s0;
							// h1 = vt[i].v;
						} 
						if(s1 >= ans1){
							ans1 = s1;
							// h1 = vt[i].v;
						}
					}
					if(i == 4){
						cout << "ni " << ans0 << " " << ans1 <<endl;
					}
					continue;
				}

			int width = 1;
			if(i == 4 && j == 9){
				cout << st.top().v << " " << h[i][j] <<endl;
			}
			while(!st.empty() && st.top().v >= h[i][j]){
				width += st.top().w;//加上这个数弹出的个数
				width += 1;//再加上这个数本省
				 if(i == 4){
					cout <<"haha "<< i << " " << j <<" "<< st.top().w<< endl;
				 }
				st.pop();
			}
			int s0 = h[i][j] * width,s1 = h[i][j] * (width - 1); 
			if(i == 4){
				cout << "jiba " <<j << " "<< h[i][j] <<" " <<  width << endl;
			}
			if(i == 4 && j == 230){
				cout <<"niam "<< h[i][j] << " " << width<< endl;
				cout << "jioooooooo " << ans0 << " " << ans1 <<endl;
			}
			if(s0 >= ans0){
				ans1 = ans0;
				ans0 = s0;
				// h0 = h[i][j];
			}else if(s0 >= ans1){
				ans1 = s0;
				// h1 = h[i][j];
			}
			if(s1 >= ans1){
				ans1 = s1;
				// h1 = h[i][j];
			}
			st.push(node{h[i][j],j,width-1});

		}
	}
	// printf("%d\n",ans1);
	printf("%d %d\n",ans0,ans1);
	//printf("%d %d\n",h0,h1);
}
int main(){

	while(~scanf("%d %d",&n,&m)){
		per(i,1,n){
			scanf("%s",mp[i]+1);
		}
		printf("nihao\n");
		per(i,1,n){
			per(j,1,m){
				if(mp[i][j] == '1'){
					printf("1");
				}else{
					printf("%c",' ');
				}
			}
			puts("");
		}
		solve();
	}

	return 0;
}
/*
3 3
111
110
001
*/
/*
3 5
11111
11111
11111
*/
/*
4 63
011011000110101100011100100110011010110110000001110101100011111
110010101110000111111101000100000001000101000101101101111100100
001110001101111111111001111010001001010101100010010100110100110
100001011101010111111100101011101101010111101000010001111000001

*/
/*
3 4
0011
0110
0110
*/