#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
int main(int argc, char * argv[]){
	string s;
	cin >> s;
	int n = s.size();
	int ans = 0;
	for(int i = 1; i < n; i++){
		if(s[i] == s[i-1]){
			s[i] = '+';
			ans++;
		}
	}
	cout << ans;

    return 0;
}