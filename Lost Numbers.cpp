#include <bits/stdc++.h>
#define per(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep(i,a,b) for (int i = (a); i >= (b); --i)
using namespace std;
const int maxn = 2e5;
vector<int> vt;
int a[10],b[5];
int num[7] = {0,4 , 8, 15, 16, 23, 42};
int c1[5] = {0,60,64,92,168};//1/2时的4
int c2[5] = {0,32,120,184,336};//1/2时的8
void solve(){
	bool vis[100];
	memset(vis,false,sizeof(vis));
	per(i,1,6){
		per(j,1,6){
			if((b[1] * 1.0 / b[2]) == 0.5){
				per(k,1,4){
					if(c1[k] == b[1]){
						a[1] = 4; a[3] = 8;	
						vis[4] = true; vis[8] = true;
						break;
					}
					if(c2[k] == b[1]){
						a[1] = 8; a[3] = 16;
						vis[8] = true; vis[16] = true;
						break;
					}
				}
				i = 7,j = 7;
				continue;
			}
			if((b[1] * 1.0 / b[2]) == 2){
				per(k,1,4){
					if(c1[k] == b[2]){
						a[1] = 8; a[3] = 4;
						vis[4] = true; vis[8] = true;
						break;
					}
					if(c2[k] == b[2]){
						a[1] = 16; a[3] = 8;
						vis[8] = true; vis[16] = true;
						break;
					}
				}
				i = 7,j = 7;
				continue;
			}
			if((b[1] * 1.0 / b[2]) == 2){
				per(k,1,4){
					if(c1[k] == b[1]){
						a[1] = 4; a[3] = c1[k]/4;
					}
				}
			}
			if(num[i] *1.0 / num[j] == (b[1] * 1.0 / b[2])){
				a[1] = num[i]; a[3] = num[j];
				vis[num[i]] = true; vis[num[j]] = true;
				break;
			}
		}
	}

	per(i,1,6){
		per(j,1,6){
			if((b[2] * 1.0 / b[3]) == 0.5){
				per(k,1,4){
					if(c1[k] == b[2]){
						a[2] = 4; a[4] = 8;
						vis[4] = true; vis[8] = true;
						break;
					}
					if(c2[k] == b[2]){
						a[2] = 8; a[4] = 16;
						vis[8] = true; vis[16] = true;
						break;
					}
				}
				i = 7,j = 7;
				continue;
			}
			if((b[2] * 1.0 / b[3]) == 2){
				per(k,1,4){
					if(c1[k] == b[3]){
						a[2] = 8; a[4] = 4;
						vis[4] = true; vis[8] = true;
						break;
					}
					if(c2[k] == b[3]){
						a[2] = 16; a[4] = 8;
						vis[8] = true; vis[16] = true;
						break;
					}
				}
				i = 7,j = 7;
				continue;
			}
			if(num[i] *1.0 / num[j] == (b[2] * 1.0 / b[3])){
				a[2] = num[i]; a[4] = num[j];
				vis[num[i]] = true; vis[num[j]] = true;
				break;
			}
		}
	}

	a[5] = b[4] / a[4];
	vis[a[5]] = true;
	per(i,1,6){
		if(!vis[num[i]]){
			a[6] = num[i];
		}
	}
	//printf("! %d %d %d %d %d %d\n",a[1],a[2],a[3],a[4],a[5],a[6]);
	cout <<"!";
	per(i,1,6){
		cout << " " << a[i];
	}
	cout << endl;
	cout.flush();
}
int main(){
	
	//printf("？ 1 2\n");
	/*
	cout << "?1 2\n";
	cout.flush();
	cin >> b[1];

	cout << "?2 3\n";
	cout.flush();
	cin >> b[2];

	cout << "?3 4\n";
	//fflush(stdout);
	cout.flush();
	cin >> b[3];

	cout << "?4 5\n";
	cout.flush();
	cin >> b[4];
	*/
	for(int i = 1; i <= 4; i++){
		cout << "? " << i<< " " << i + 1 << endl;
		cout.flush();
		cin >> b[i];
	}

	solve();

	return 0;
}
