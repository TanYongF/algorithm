#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;


typedef struct A{

}A;
int T;
int main(int argc, char * argv[]){
	int n, m, k;
	cin >> n >> m >> k;
	ll maxn = 1LL * (m - 1) * (n - 1);

	if(maxn < k){
		cout << -1;
		return 0;
	}
	vector<int> ans(n, 0);
	ans[0] = 1;
	int last = k;
	for(int i = 1; i < n; i++){
		if(last >= m - 1) ans[i] = ans[i-1] == 1 ? m : 1, last -= (m-1);
		else if(last < m - 1 and last > 0) ans[i] = ans[i-1] == 1 ? 1 + last : m - last, last = 0;
		else ans[i] = ans[i-1];  
	}
	for(auto it : ans) cout << it << " " ;
    return 0;
}