#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T,n;
unordered_map<int, long long> mp;
long long dfs(long long n){
	if(n <= 3) return (mp[n] = n);
	if(n < 10000000 and mp.count(n)) return mp[n];
	if(n < 10000000) return mp[n] = max(n, dfs(n / 2) + dfs(n / 3) + dfs(n / 4));
	else return max(n, dfs(n / 2) + dfs(n / 3) + dfs(n / 4));
}
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		cin >> n; 
		cout << dfs(n) << endl;
	}
    return 0;
}