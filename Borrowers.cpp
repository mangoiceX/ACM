#include<iostream> 
#include<algorithm>
#include<string>
using namespace std;
const int maxn = 100;
struct Gov
{
	string title;
	string author;
} goven[maxn];
bool cmp1(Gov gv1, Gov gv2)
{
	return gv1.author < gv2.author;
}
bool cmp2(Gov gv1, Gov gv2)
{
	return gv1.title < gv2.title;
}
int main()
{
	int n;
	cin >> n;
	string str1, str2;
	for(int i = 0; i < n; i++)
	{
		cin >> str1 >> str2;
		goven[i].title = str1;
		goven[i].author = str2;
	}
	sort(goven, goven + n, cmp1);
	sort(goven, goven + n, cmp2);
	for(int i = 0; i < n; i++)
	{
		cout << goven[i].title << " " << goven[i].author << endl;
	}
}

