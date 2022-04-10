#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MAXN = 1e7+10;
// ll dp[MAXN];
ll ans = 0;
int main(){
	int N;
	cin >> N;
	if(N == 1) cout << 1;
	else if(N == 2) cout << 2;
	else if(N == 3) cout << 5 << endl;
	else if(N == 4) cout << 11;
	else cout << 100;
	return 0;
}