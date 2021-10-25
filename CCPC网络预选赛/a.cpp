#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 1e9;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		int ans = 0;
		cin >> n;
		if(n % 2)
			ans = n / 2 + 1;
		else
			ans = n / 2;
		for(int i = 1; i <= n; i += 2)
		{
			if(3 * i + 1 > n)
				ans += 1;
		}
		cout << ans << endl;
	}
	return 0;
}