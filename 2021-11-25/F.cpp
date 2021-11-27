#include <bits/stdc++.h>
using namespace std;
#define db  double
#define ll  long long
#define Pir pair<int, int>
#define fi  first
#define se  second
#define pb  push_back
#define m_p make_pair
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 2e5 + 10;
int n, m;
char a[N << 1], b[N << 1];         
int len[N << 1];

void trans()
{
    b[0] = '@';
    for (int i = 1; i <= 2 * n; i += 2)
    {
        b[i] = '#';
        b[i + 1] = a[i / 2];
    }

    b[2 * n + 1] = '#';
    b[2 * n + 2] = '\0';
    m = 2 * n + 1;
}

void Manacher()
{
    int R = 0, mid = 0;
    for (int i = 1; i <= m; i ++)
    {
        if (i < R) len[i] = min(R - i, len[2 * mid - i]);
        else len[i] = 1;

        while (b[i - len[i]] == b[i + len[i]]) len[i] ++;
        if (len[i] + i > R)
        {
            R = len[i] + i;
            mid = i;
        }
    }
}

int main(){
	int T;
	cin >> T;
	while(T--){
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(len, 0, sizeof(len));
	    scanf("%s", a);
	    n = strlen(a);
	    // cout << n;
	    trans();
	    Manacher();
	    ll ans = 0;
	    for (int i = 0; i < n; i ++)
	    {
	        int r1 = len[(i + 1) * 2] / 2;          
	        int r2 = len[(i + 1) * 2 + 1] / 2;      

	        ans += r1;
	        ans += r2;
	    }
	    printf("%lld\n", 1LL * (1 + n) * n / 2 - ans + 1);
	}
    return 0;
}