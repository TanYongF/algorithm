#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 2e5+10;
int T;
ll a[MAXN], b[MAXN],last,cur,ans,n,c;
ll need[MAXN];
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		ll tem;
		// ans = INT_MAX;
		cin >> n >> c;
		ms(a,0);
		ms(b,0);
		ms(need,0);
		need[1] = 0;
		for(int i = 1; i  <= n; i++) cin >> a[i];
		for(int i=  1; i < n; i++) cin >> b[i];
		cur = 0;
		if(c % a[1]) ans = c / a[1] + 1;
		else ans = c / a[1];
		for(int i = 1; i <= n-1; i++){
			int tem = b[i]- cur;
			if(tem <= 0) last = 0;
			else{
				if(tem % a[i] == 0) last = tem / a[i];
				else last = tem / a[i] + 1;
			}
			need[i+1] = need[i] + last + 1;
			cur = cur + last * a[i] - b[i];

			tem = c - cur;
			if(tem <= 0) ans = min(ans, need[i+1]);
			else{
				if(tem % a[i+1]) ans = min(ans, need[i+1] + (int)(tem / a[i+1]) + 1);
				else ans = min(ans, need[i+1] +  tem/a[i+1]);
			}
		}
		cout << ans << endl;
	/* code */

	}

	


    return 0;
}