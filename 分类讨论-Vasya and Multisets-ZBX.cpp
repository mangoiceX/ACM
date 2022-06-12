#include <bits/stdc++.h>
using namespace std;

int a[105], cnt[105];
char ans[105];

int main(){
	int n, _ok;
	char flag;
	cin >> n;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 1; i <= n; i++) ans[i] = '0';
	flag = 'A';
	for (int i = 1; i <= n; i++){
		if (cnt[a[i]] == 1){
			ans[i] = flag;
			if (flag == 'A') flag = 'B';
			else flag = 'A';
		}
	}
	if (flag == 'B'){
		_ok = 0;
		for (int i = 1; i <= n; i++){
			if (cnt[a[i]] >= 3){
				ans[i] = 'B';
				_ok = 1;
				break;
			}
		}
		if (!_ok){
			printf("NO\n");
			return 0;
		}
	}
	for (int i = 1; i <= n; i++){
		if (ans[i] == '0') ans[i] = 'A';
	}
	printf("YES\n");
	for (int i = 1; i <= n; i++) printf("%c",ans[i]);
	printf("\n");
	return 0;
}
