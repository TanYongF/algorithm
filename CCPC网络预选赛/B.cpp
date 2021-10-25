#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define Fore(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
typedef long long ll;
const int maxn = 1e5 + 5;
using namespace std;
ll cal(ll a,ll b,ll c,ll x)
{
	return (a * x * x + b * x + c);
}
int main()
{
	int T;
	// cout<<cal(-1,4,5,3)<<endl;
	cin >> T;
	while(T--)
	{
		int a,b,c;
		int x0,x1,y0,y1,y2;
		cin >> a >> b >> c;
		cin >> x0 >> x1 >> y0 >> y1 >> y2;
		ll ya = cal(a,b,c,x0);
		if(ya <= y0)
			cout << "No" << endl;
		else
		{
			ll yb = cal(a,b,c,x1);
			if(yb < y0)
				cout << "Yes" << endl;
			else
			{
				if(yb > y2 || yb == y0)
					cout << "No" << endl;
				else
				{
					int xduichen = x1 + (x1 - x0);
					ll yduichen = cal(a,b,c,xduichen);
					if(yduichen < y0)
						cout << "Yes" << endl;
					else
						cout << "No" << endl;
				}
			}
		}
	}
	return 0;
}