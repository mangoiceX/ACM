#include<bits/stdc++.h>
using namespace std;
const int maxn = 30;
double total_score = 36;
double score[maxn];
double w[maxn];
int main(){
	double sum = 0;
	double ans = 0;
	int i = 0;
	while(true){
		scanf("%lf %lf",&w[i],&score[i]);
		if(fabs(w[i] + 1) < 1e-2){
			break;
		}
		sum += w[i];
		ans += w[i]*score[i];
		++i;
	}
	printf("%lf\n",ans / sum);
	return 0;
}

// 4 71
// 1.5 87
// 4 83
// 3 90
// 3 79
// 3 76
// 3 85
// 4 95
// 3.5 74
// 0.5 86
// 0.5 69
// 2 75
// 2 86
// 2 85
// -1 -1

